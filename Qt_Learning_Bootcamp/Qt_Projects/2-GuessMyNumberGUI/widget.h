#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_GuessButton_clicked();
    void on_StartOverButton_clicked();

private:
    Ui::Widget *ui;

    int secret_number{};    // random number
    int guessed_number{};   // user input number
};
#endif // WIDGET_H
