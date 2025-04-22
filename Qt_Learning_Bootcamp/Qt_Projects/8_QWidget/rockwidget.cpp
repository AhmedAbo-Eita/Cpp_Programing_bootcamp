#include "rockwidget.h"
#include <QMessageBox>
#include <QLabel>
#include <QPalette>
#include <QPushButton>

RockWidget::RockWidget(QWidget *parent): QWidget{parent}
{

    // creat a label
    QLabel *label = new QLabel(this);
    //label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    label->setText("first line\nsecond line");
    label->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
    label->move(50,50);

    //add styeled widget
    QPalette label1Palette;
    label1Palette.setColor(QPalette::Window,Qt::yellow);
    label1Palette.setColor(QPalette::WindowText, Qt::blue);

    QFont label1font ("Blinker",15,QFont::Bold);

    QLabel *label1 = new QLabel(this);
    label1->setAutoFillBackground(true);
    label1->setText("My colored label");
    label1->setFont(label1font);
    label1->setPalette(label1Palette);
    label1->move(150,50);


    // another label
    QPalette label2Palette;
    label2Palette.setColor(QPalette::Window,Qt::white);
    label2Palette.setColor(QPalette::WindowText, Qt::red);

    QFont label2font ("Times",15,QFont::Bold);

    QLabel *label2 = new QLabel(this);
    label2->setAutoFillBackground(true);
    label2->setText("My colored label2");
    label2->setFont(label2font);
    label2->setPalette(label2Palette);
    label2->move(50,150);


    //create PushButton
    QFont buttonFont ("Blinker", 18 , QFont::Bold);
    QPushButton *button1 = new QPushButton("Click Me", this);
    button1->setGeometry(50,200,200,50);
    button1->setFont(buttonFont);


    connect(button1,SIGNAL(clicked()),this,SLOT(button_clicked()));

}

void RockWidget::button_clicked()
{
    QMessageBox::information(this , "Message", "You clicked on my button");
}

QSize RockWidget::sizeHint() const
{
    return QSize(500,500);
}
