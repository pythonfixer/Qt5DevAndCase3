#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    init();
    connect(ui->treeWidget, SIGNAL(itemChanged(QTreeWidgetItem*,int)), this, SLOT(treeItemChanged(QTreeWidgetItem*,int)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::init()
{
    ui->treeWidget->clear();
    QTreeWidgetItem *group1 = new QTreeWidgetItem(ui->treeWidget);
    group1->setText(0, "group1");
    group1->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    group1->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem *subitem11 = new QTreeWidgetItem(group1);
    subitem11->setText(0, "subitem11");
    subitem11->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subitem11->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem *subitem12 = new QTreeWidgetItem(group1);
    subitem12->setText(0, "subitem12");
    subitem12->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subitem12->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem *subitem13 = new QTreeWidgetItem(group1);
    subitem13->setText(0, "subitem13");
    subitem13->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subitem13->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem *subitem14 = new QTreeWidgetItem(group1);
    subitem14->setText(0, "subitem14");
    subitem14->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subitem14->setCheckState(0, Qt::Unchecked);

    QTreeWidgetItem *group2 = new QTreeWidgetItem(ui->treeWidget);
    group2->setText(0, "group2");
    group2->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    group2->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem *subitem21 = new QTreeWidgetItem(group2);
    subitem21->setText(0, "subitem21");
    subitem21->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subitem21->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem *subitem22 = new QTreeWidgetItem(group2);
    subitem22->setText(0, "subitem22");
    subitem22->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subitem22->setCheckState(0, Qt::Unchecked);
    QTreeWidgetItem *subitem23 = new QTreeWidgetItem(group2);
    subitem23->setText(0, "subitem23");
    subitem23->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subitem23->setCheckState(0, Qt::Unchecked);
}

void Widget::treeItemChanged(QTreeWidgetItem *item, int column)
{
    QString itemText = item->text(0);
    if (Qt::Checked == item->checkState(0))
    {
        QTreeWidgetItem *parent = item->parent();
        int count = item->childCount();
        if (count > 0)
        {
            for (int i = 0; i < count; i++)
            {
                item->child(i)->setCheckState(0, Qt::Checked);
            }
        }
        else
        {
            updateParentItem(item);
        }
    }
    else if (Qt::Unchecked == item->checkState(0))
    {
        int count = item->childCount();
        if (count > 0)
        {
            for (int i = 0; i < count; i++)
            {
                item->child(i)->setCheckState(0, Qt::Unchecked);
            }
        }
        else
        {
            updateParentItem(item);
        }
    }
}

void Widget::updateParentItem(QTreeWidgetItem *item)
{
    QTreeWidgetItem *parent = item->parent();
    if (parent == NULL)
    {
        return ;
    }
    int selectCount = 0;
    int childCound = parent->childCount();
    for (int i = 0; i < childCound; i++)
    {
        QTreeWidgetItem *childItem = parent->child(i);
        if (childItem->checkState(0) == Qt::Checked)
        {
            selectCount++;
        }
    }
    if (selectCount <= 0)
    {
        parent->setCheckState(0, Qt::Unchecked);
    }
    else if (selectCount > 0 && selectCount < childCound)
    {
        parent->setCheckState(0, Qt::PartiallyChecked);
    }
    else if (selectCount == childCound)
    {
        parent->setCheckState(0, Qt::Checked);
    }
}
