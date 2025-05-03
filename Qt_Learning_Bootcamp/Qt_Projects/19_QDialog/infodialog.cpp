#include "infodialog.h"
#include "ui_infodialog.h"

infoDialog::infoDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::infoDialog)
{
    ui->setupUi(this);
}

infoDialog::~infoDialog()
{
    delete ui;
}

void infoDialog::on_OkPushButton_clicked()
{

    QString user_position = ui->PositionLineEdit->text();

    if(!user_position.isEmpty())
    {
        m_position = user_position;
        if(ui->WindowsRadioButton->isChecked())
        {
            m_os = "Windows";
        }
        if(ui->linuxRadioButton->isChecked())
        {
            m_os = "linux";
        }
        if(ui->macRadioButton->isChecked())
        {
            m_os = "Mac";
        }

        accept();
    }
    else
    {
        reject();
    }

}


void infoDialog::on_cancelPushButton_clicked()
{
    // reject the dialog
    reject();
}

QString infoDialog::os() const
{
    return m_os;
}

Ui::infoDialog *infoDialog::getUi() const
{
    return ui;
}

QString infoDialog::position() const
{
    return m_position;
}

