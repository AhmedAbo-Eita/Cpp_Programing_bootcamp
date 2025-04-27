#include "widget.h"
#include "./ui_widget.h"

#include <QGridLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    // QGridLayout *layout = new QGridLayout(this);

    // //first row
    // layout->addWidget(ui->Button1,0,0);
    // layout->addWidget(ui->Button2,0,1);
    // layout->addWidget(ui->Button3,0,2,2,1);

    // //second row
    // layout->addWidget(ui->Button4,1,0);
    // layout->addWidget(ui->Button5,1,1);

    // //third row
    // layout->addWidget(ui->Button7,2,0,1,2);
    // layout->addWidget(ui->Button9,2,2);


}

Widget::~Widget()
{
    delete ui;
}
