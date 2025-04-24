#include "widget.h"
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //make style for button font
    QFont buttonFont("Times",18, QFont::Medium);
    //creat button1
    QPushButton *button1 = new QPushButton("Button1",this);
    button1->setFont(buttonFont);
    button1->resize(200,100);

    //connect when the button clickred print clicked
    connect(button1,&QPushButton::clicked,[=](){
        qDebug() << "button 1 clicked";
    });

    //create button 2
    QPushButton *button2 = new QPushButton("Button2",this);
    button2->setFont(buttonFont);
    button2->resize(200,100);
    button2->move(205,0);

    //connect button 2
    //when pressed send button is pressed
    connect(button2,&QPushButton::pressed,[=](){
        qDebug() << "button 2 pressed";
    });
    //when released send button is released
    connect(button2,&QPushButton::released,[=](){
        qDebug() << "button 2 released";
    });


}

Widget::~Widget() {}
