#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //when the push botton pressed the text in lable cahnges

    //string notation
    //connect(ui->MyButton,SIGNAL(clicked()),this,SLOT(change_text()));

    //Functor notation : Regular slot
    //connect(ui->MyButton,&QPushButton::clicked, this , &Widget::change_text);

    //Functor notation : Lambdas
    connect(ui->MyButton,&QPushButton::clicked,[=](){
        ui->label->setText("Some other text from lambda");

    });



    // Connect slider with progress bar

    //string notation
    connect(ui->MySlider,SIGNAL(valueChanged(int)),ui->MyProgressBar,SLOT(setValue(int)));
    connect(ui->MySlider,SIGNAL(valueChanged(int)),this,SLOT(respond(int)));

    //Functor notation :Regular slot
    //connect(ui->MySlider,&QSlider::sliderMoved, this, &Widget::change_bar);

    //Functor notation : lambdas
    // connect(ui->MySlider, &QSlider::sliderMoved,[=](int value){
    //     ui->MyProgressBar->setValue(value);
    //     qDebug() << "value is " << value ;
    // });

}

Widget::~Widget()
{
    delete ui;
}

void Widget::respond(int value)
{
    qDebug() << "Value is " << value;
}

// void Widget::change_bar(int value)
// {
//     ui->MyProgressBar->setValue(value);
//     qDebug() << "Value is " << value;
// }



// void Widget::change_text()
// {
//     ui->label->setText("Some other text");
// }



