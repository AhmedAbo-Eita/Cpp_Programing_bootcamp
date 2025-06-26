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
#include <QStandardPaths>
#include <QCloseEvent>
#include "import_export_handler.h"
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

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::Widget *ui;
    std::vector<Component> componentList;
    std::vector<Component> componentListoldSave;
    std::optional<int> updatedIndex = std::nullopt;
    void inventoryTableStyleSetup();
    void widget_connect_func();
    void showComponentsInTable();
    std::optional<int> searchComponentsInTable(QString MPN);
    int getComponentTypeIndex(QString type);
    void checkCSV(QString dataDirPath,QString destPath);
    QString dataDirPath = QCoreApplication::applicationDirPath() + "/data";
    // Prepare CSV file path
    QString destPath = dataDirPath + "/My_Inventory.csv";
    void showVectorOfComponents(std::vector<Component> list);

};
#endif // WIDGET_H
