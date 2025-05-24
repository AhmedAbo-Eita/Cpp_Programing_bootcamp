#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <vector>
#include <QLabel>
#include <QGraphicsOpacityEffect>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QFileInfo>
#include <QDesktopServices>
#include <QUrl>
#include <QCoreApplication>
#include <QTemporaryFile>
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
    void widget_connect_func();
    void showComponentsInTable();
    std::optional<int> searchComponentsInTable(QString MPN);
    void exportTableToCSV(QTableWidget *tableWidget,QWidget *parent);
    void importTableFromCSV(QTableWidget *tableWidget, QWidget *parent);



};
#endif // WIDGET_H
