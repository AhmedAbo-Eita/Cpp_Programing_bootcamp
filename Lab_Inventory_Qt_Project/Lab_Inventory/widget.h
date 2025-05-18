#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <vector>
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

private slots:
    void on_addPushButton_clicked();
    void on_clearPushButton_clicked();
    void on_exportPushButton_clicked();

private:
    Ui::Widget *ui;
    std::vector<Component> componentList;
    void inventoryTableStyleSetup();
    void showComponentsInTable();
    void exportToCSV(const QString &filePath);
    void resizeWithAspectRatio(float aspectRatio);



};
#endif // WIDGET_H
