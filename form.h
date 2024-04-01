#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QVector>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
public slots:
    void onReceiverResponse(double temp, QString desc, QString city, int mill);
private:
    Ui::Form *ui;
};

#endif // FORM_H
