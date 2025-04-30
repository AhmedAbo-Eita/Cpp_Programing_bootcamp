#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QWidget *customTab = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addWidget(new QPushButton("Button1",this));
    layout->addWidget(new QPushButton("Button2",this));
    layout->addWidget(new QPushButton("Button3",this));

    QPushButton *button4 = new QPushButton ("Button4", this);
    layout->addWidget(button4);
    connect (button4,&QPushButton::clicked,[=](){
        qDebug() << "Button 4 from custom tab clicked";
    });

    customTab->setLayout(layout);
    ui->tabWidget->insertTab(0,customTab,"My custom Tab");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_3_clicked()
{
    qDebug() << "Click Entered";
}

