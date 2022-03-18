#include "dialog.h"

#include <QGridLayout>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    radiusLabel = new QLabel(this);
    radiusLabel->setText(tr("圆的半径为："));
    radiusLineEdit = new QLineEdit(this);
    areaLabel = new QLabel(this);
    countBtn = new QPushButton(this);
    countBtn->setText(tr("计算圆的面积"));

    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->addWidget(radiusLabel, 0, 0);
    mainLayout->addWidget(radiusLineEdit, 0, 1);
    mainLayout->addWidget(areaLabel, 1, 0);
    mainLayout->addWidget(countBtn, 1, 1);

    connect(countBtn, SIGNAL(clicked()), this, SLOT(showArea()));
    connect(radiusLineEdit, SIGNAL(textChanged(QString)), this, SLOT(showArea()));
}

Dialog::~Dialog()
{

}

void Dialog::showArea()
{
    bool ok;
    QString tempStr;
    QString valueStr = radiusLineEdit->text();
    int valueInt = valueStr.toInt(&ok);
    double area = valueInt * valueInt * 3.1415926;
    areaLabel->setText(tempStr.setNum(area));
}
