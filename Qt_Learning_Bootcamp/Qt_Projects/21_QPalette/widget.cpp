#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);



    ui->label->setAutoFillBackground(true);
    //Retrieve the palette for the label
    QPalette palette = ui->label->palette();

    //modify the palette with our changes
    palette.setColor(QPalette::Window,Qt::black);
    palette.setColor(QPalette::WindowText,Qt::white);

    //reset the palette to widget
    ui->label->setPalette(palette);

    //Active PB color set
    QPalette *buttonPalette = new QPalette();
    buttonPalette->setColor(QPalette::Button,Qt::black);
    buttonPalette->setColor(QPalette::ButtonText,Qt::white);
    ui->activeButton->setAutoFillBackground(true);
    ui->activeButton->setPalette(*buttonPalette);

    //disable pb color set
    QPalette *buttonPalette1 = new QPalette();
    buttonPalette1->setColor(QPalette::Button,Qt::red);
    buttonPalette1->setColor(QPalette::ButtonText,Qt::white);
    ui->disableButton->setAutoFillBackground(true);
    ui->disableButton->setPalette(*buttonPalette1);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_activeButton_clicked()
{

    qDebug() << "Active Button Clicked";
    ui->disableButton->setDisabled(false);

    // QPalette::ColorGroup activeButtonColorGroup = ui->activeButton->palette().currentColorGroup();
    // QPalette::ColorGroup disableButtonColorGroup = ui->activeButton->palette().currentColorGroup();

    //After click active button the color will be change
    QPalette *buttonPalette = new QPalette();
    buttonPalette->setColor(QPalette::Button,Qt::black);
    buttonPalette->setColor(QPalette::ButtonText,Qt::white);
    ui->disableButton->setAutoFillBackground(true);
    ui->disableButton->setPalette(*buttonPalette);


}


void Widget::on_disableButton_clicked()
{
    qDebug() << "Disable Button Clicked";
}

