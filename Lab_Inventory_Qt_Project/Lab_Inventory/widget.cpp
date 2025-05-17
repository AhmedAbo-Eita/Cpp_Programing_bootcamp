#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // ui->appIconlabel->setPixmap(QPixmap(":/inventoryMainIcons/Images/package_6215997.png"));
    // ui->appIconlabel->setScaledContents(true);
    // ui->appIconlabel->resize(100,100);
}

Widget::~Widget()
{
    delete ui;
}
