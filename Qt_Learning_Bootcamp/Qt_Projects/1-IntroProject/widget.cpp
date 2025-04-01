#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    //qDebug()<<"you had to click this button, isn't you?";

    // QMessageBox msgBox;
    // msgBox.setText("Hi.");
    // msgBox.setInformativeText("Wellcome Qt");
    // msgBox.setStandardButtons(QMessageBox::Cancel);
    // msgBox.setDefaultButton(QMessageBox::Cancel);
    // int ret = msgBox.exec();

    QMessageBox msgBox;
    msgBox.setText("Hi, This is the first Qt project");
    msgBox.exec();

}

