#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrl>
#include <QJsonArray>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onGetTemp(QNetworkReply*)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onGetTemp(QNetworkReply* reply){

        if(reply->error() == QNetworkReply::NoError){

                connected = true;
                QByteArray responseBytes = reply->readAll();
                QJsonDocument jsonResponse = QJsonDocument::fromJson(responseBytes);
                QJsonObject jsonObject = jsonResponse.object();
                double temperature = jsonObject["main"].toObject()["temp"].toDouble();
                QString weatherDescription = jsonObject["weather"].toArray()[0].toObject()["description"].toString();
                QString city = jsonObject["name"].toString();
                qDebug() << city;
                disconnect(timer, SIGNAL(timeout()), this, SLOT(countMill()));
                emit sendResponse(temperature, weatherDescription, city, mill);
                mill = 0;
                return;
    }
    qDebug()<< "the connection Faill";
    connected = false;
    disconnect(timer, SIGNAL(timeout()), this, SLOT(countMill()));
    mill = 0;

}


void MainWindow::on_pushButton_clicked()
{
    QString API_KEY = "d86807edf6e968011a12cc2e243cad5c";
    QString city = ui->lineEdit->text();
    QUrl url("http://api.openweathermap.org/data/2.5/weather?q=" + city + "&appid=" + API_KEY + "&units=metric");
    manager->get(QNetworkRequest(url));
    connect(timer, SIGNAL(timeout()), this, SLOT(countMill()));
    timer->start(100);
}

void MainWindow::countMill(){

    mill++;
    qDebug()<< mill;

}


























