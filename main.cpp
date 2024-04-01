#include "mainwindow.h"
#include "form.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Form form;
//    MainWindow w;
    form.show();
//    w.show();

    return a.exec();
}
