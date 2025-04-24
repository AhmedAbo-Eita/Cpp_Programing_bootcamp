#include "widget.h"
#include <QPushButton>
#include <QFont>
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    // add push botton
    QPushButton *button1 = new QPushButton("Click Here",this);
    QFont buttonFont("Blinker", 15 ,QFont::Medium);
    button1->setFont(buttonFont);
    button1->resize(100,50);
    button1->move(200,200);

    // show message box after clicked on pushbutton
    connect(button1,&QPushButton::clicked,[=](){
        qDebug() << "button clicked";
        //simple message box
        // QMessageBox myMessage;
        // myMessage.setText("Welcome in Qt messagebox");
        // myMessage.exec();

        //hard way:
        // QMessageBox myMessage;
        // myMessage.setMinimumSize(700,200);
        // myMessage.setWindowTitle("Message title");
        // myMessage.setText("Welcome in Qt Messagebox");
        // myMessage.setInformativeText("Do you want to do something about this");
        // myMessage.setIcon(QMessageBox::Critical);
        // myMessage.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        // myMessage.setDefaultButton(QMessageBox::Cancel);
        // int ret = myMessage.exec();

        //Critical Message -- Static constructor
        int ret = QMessageBox::warning(this, "Welcome in Qt Messagebox", "Do you want to do something about this",
                                        QMessageBox::Ok | QMessageBox::Cancel,QMessageBox::Cancel);

        if (ret == QMessageBox::Ok)
        {
            qDebug() << "Ok is pressed";
        }
        if (ret == QMessageBox::Cancel)
        {
            qDebug() << "Cancel is pressed";
        }

    });



}

Widget::~Widget() {}

// QSize Widget::sizeHint() const
// {
//     //return QSize(1000,1000);
// }
