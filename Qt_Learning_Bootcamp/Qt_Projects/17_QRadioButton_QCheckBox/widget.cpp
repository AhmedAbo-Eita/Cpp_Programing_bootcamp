#include "widget.h"
#include "./ui_widget.h"
#include <QButtonGroup>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QButtonGroup *osGroup = new QButtonGroup(this);
    osGroup->addButton(ui->windowsCheckBox);
    osGroup->addButton(ui->linuxCheckBox);
    osGroup->addButton(ui->macCheckBox);
    osGroup->setExclusive(true);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_windowsCheckBox_toggled(bool checked)
{
    if (checked)
    {
        qDebug() << "Windows checkbox is checked";
    }
    else
    {
        qDebug() << "Windows checkbox is unchecked";
    }
}


void Widget::on_linuxCheckBox_toggled(bool checked)
{
    if (checked)
    {
        qDebug() << "Linux checkbox is checked";
    }
    else
    {
        qDebug() << "Linux checkbox is unchecked";
    }

}


void Widget::on_macCheckBox_toggled(bool checked)
{
    if (checked)
    {
        qDebug() << "Mac checkbox is checked";
    }
    else
    {
        qDebug() << "Mac checkbox is unchecked";
    }
}

