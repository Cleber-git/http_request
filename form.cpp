#include "form.h"
#include "ui_form.h"
#include "mainwindow.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    MainWindow *mw = new MainWindow();
    connect(mw, SIGNAL(sendResponse(double, QString, QString, int)), this, SLOT(onReceiverResponse(double, QString, QString, int)));
    mw->show();

}

Form::~Form()
{
    delete ui;
}




void Form::onReceiverResponse(double temp, QString desc, QString city, int mill){

    if(temp == 0.0 && desc.isEmpty() && city.isEmpty()) return;

    ui->label_3->setText(city);
    ui->label->setText("  "+QString::number(temp) + "ºC");
        if(mill < 20){
        ui->l_wifi->setStyleSheet("border-image:url(:/new/prefix1/wifi.png);");
        return;
    }
    ui->l_wifi->setStyleSheet("border-image:url(:/new/prefix1/wifi-desligado.png);");
}
