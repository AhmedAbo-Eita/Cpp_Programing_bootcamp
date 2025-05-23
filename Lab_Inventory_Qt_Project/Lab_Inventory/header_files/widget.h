#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <vector>
#include <QLabel>
#include <QGraphicsOpacityEffect>
#include <QMessageBox>
#include <QFile>
#include <QStandardPaths>
#include <QFileDialog>
#include <QVBoxLayout>
#include "component.h"



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


private:
    Ui::Widget *ui;
    std::vector<Component> componentList;
    void inventoryTableStyleSetup();
    void showComponentsInTable();
    std::optional<int> searchComponentsInTable(QString MPN);


};
#endif // WIDGET_H
