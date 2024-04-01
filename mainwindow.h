#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
public slots:
    void onGetTemp(QNetworkReply* reply);
    void countMill();
signals:
    void sendResponse(double temp, QString desc, QString city, int mill);

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    QTimer *timer = new QTimer(this);
    int mill = 0;
    bool connected = false;
};
#endif // MAINWINDOW_H
