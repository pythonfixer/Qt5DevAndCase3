#include "dialog.h"
#include "ui_dialog.h"

const static double PI = 3.1415926;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_countBtn_clicked()
{
    showArea();
}

void Dialog::on_radiusLineEdit_textChanged(const QString &arg1)
{
    showArea();
}

void Dialog::showArea()
{
    bool ok;
    QString tempStr;
    QString valueStr = ui->radiusLineEdit->text();
    int valueInt = valueStr.toInt(&ok);
    double area = valueInt * valueInt * PI;
    ui->areaLabel2->setText(tempStr.setNum(area));
}


