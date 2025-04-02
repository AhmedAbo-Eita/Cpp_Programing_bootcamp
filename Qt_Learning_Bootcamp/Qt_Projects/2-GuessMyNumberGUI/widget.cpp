#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Generating Random number based on time
    std::srand(std::time(0));
    secret_number = std::rand()%10+1; // generate random number from 1 to 10
    qDebug()<< "the secret number is "<< secret_number;

    //Disable the start over button
    ui->StartOverButton->setDisabled(true);

    //clear message lable
    ui->Messagelabel->clear();
}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_GuessButton_clicked()
{
    // get the value of guessed number from spinbox
    guessed_number = ui->NumberspinBox->value();
    // print the gussed value
    qDebug()<<"The guessed number is " << QString::number(guessed_number);

    if (guessed_number == secret_number)
    {
        ui->Messagelabel->setText("Congratulations, your guess is true.");

        //disable guess button
        ui->GuessButton->setDisabled(true);
        // Enable start over button
        ui->StartOverButton->setDisabled(false);
    }
    else
    {
        if(guessed_number > secret_number)
        {
            ui->Messagelabel->setText("Number is lower than that");
        }
        else
        {
            ui->Messagelabel->setText("Number is higher than that");
        }
    }
}


void Widget::on_StartOverButton_clicked()
{
    qDebug()<<"Start Over Button clicked";
    //Enable guess button
    ui->GuessButton->setDisabled(false);
    // Disable start over button
    ui->StartOverButton->setDisabled(true);
    //set the value of spinbox
    ui->NumberspinBox->setValue(1);
    // clear the message
    ui->Messagelabel->clear();
    // Generate new random number
    secret_number = std::rand()%10+1;
    qDebug()<< "the secret number is "<< secret_number;

}



