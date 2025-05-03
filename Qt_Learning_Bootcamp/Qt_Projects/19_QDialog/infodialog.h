#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>

namespace Ui {
class infoDialog;
}

class infoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit infoDialog(QWidget *parent = nullptr);
    ~infoDialog();

    Ui::infoDialog *getUi() const;
    QString position() const;

    QString os() const;

private slots:
    void on_OkPushButton_clicked();

    void on_cancelPushButton_clicked();

private:
    Ui::infoDialog *ui;
    QString m_position;
    QString m_os;
};

#endif // INFODIALOG_H
