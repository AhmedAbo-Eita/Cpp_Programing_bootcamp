#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setStyleSheet("Background:black; color:red;");
    ui->cancelButton->setStyleSheet("Background:black; color:red;");
}

Widget::~Widget()
{
    delete ui;
}
