#include "widget.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //creating label for firstname
    QLabel *first_name_label = new QLabel("First Name",this);
    first_name_label->setMinimumSize(70,50);
    first_name_label->move(10,10);

    //creating Line edit for firstname
    QLineEdit *first_name_line_edit = new QLineEdit(this);
    first_name_line_edit->setMinimumSize(200,30);
    first_name_line_edit->move(100,20);

    //creating label for lastname
    QLabel *last_name_label = new QLabel("Last Name",this);
    last_name_label->setMinimumSize(70,50);
    last_name_label->move(10,70);

    //creating Line edit for lastname
    QLineEdit *last_name_line_edit = new QLineEdit(this);
    last_name_line_edit->setMinimumSize(200,30);
    last_name_line_edit->move(100,80);

    //creating label for city
    QLabel *city_label = new QLabel("City",this);
    city_label->setMinimumSize(70,50);
    city_label->move(10,130);

    //creating Line edit for city
    QLineEdit *city_line_edit = new QLineEdit(this);
    city_line_edit->setMinimumSize(200,30);
    city_line_edit->move(100,140);

    // creat a pushbutton to grab the data
    QFont Button ("Times",12,QFont::Medium);
    QPushButton *grab_data = new QPushButton("Grab Data", this);
    grab_data->setFont(Button);
    grab_data->setFixedSize(120,40);
    grab_data->move(180,190);

    //Setting a Hint text
    first_name_line_edit->setPlaceholderText("First Name");
    last_name_line_edit->setPlaceholderText("Last Name");
    city_line_edit->setPlaceholderText("City");


    connect(grab_data,&QPushButton::clicked,[=](){
        QString firstName = first_name_line_edit->text();
        QString lastName = last_name_line_edit->text();
        QString city = city_line_edit->text();

        if(!firstName.isEmpty() && !lastName.isEmpty() && !city.isEmpty())
        {
            qDebug() << "First Name is: " << firstName;
            qDebug() << "Last Name is: " << lastName;
            qDebug() << "City is: " << city;
        }
        else if (!firstName.isEmpty() && !lastName.isEmpty() && city.isEmpty())
        {
            qDebug() << "First Name is: " << firstName;
            qDebug() << "Last Name is: " << lastName;
            qDebug() << "City not inserted" ;
        }
        else if (!firstName.isEmpty() && lastName.isEmpty() && !city.isEmpty())
        {
            qDebug() << "First Name is: " << firstName;
            qDebug() << "Last not inserted ";
            qDebug() << "City is: " << city;
        }
        else if (firstName.isEmpty() && !lastName.isEmpty() && !city.isEmpty())
        {
            qDebug() << "First Name not inserted";
            qDebug() << "Last Name is: " << lastName;
            qDebug() << "City is: " << city;
        }
        else
        {
            qDebug("Please Compelete the data");
        }

    });

}

Widget::~Widget() {}
