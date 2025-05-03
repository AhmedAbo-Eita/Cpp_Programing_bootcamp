#include "widget.h"
#include "./ui_widget.h"
#include "infodialog.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_ProvideInfoButton_clicked()
{
    infoDialog *dialog = new infoDialog(this);
    auto ret = dialog->exec();

    if(ret == QDialog::Accepted)
    {
        QString position = dialog->position();
        QString os = dialog->os();

        qDebug() << "Dialog accepted, position is: " << position <<
            "add favorate os is: " << os;
        ui->infoLabel->setText("Your piosition is : "+ position + " and your favorite os is: "+ os);
    }
    else
    {
        ui->infoLabel->setText("Dialog rejected");

    }

    dialog->raise();// put it on the top
    dialog->activateWindow();//give the dialog focus

    //non modal
    //dialog->show();
}

