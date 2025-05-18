#include "widget.h"
#include "./ui_widget.h"
#include <QLabel>
#include <QGraphicsOpacityEffect>
#include <QMessageBox>
#include <QFile>
#include <QStandardPaths>
#include <QFileDialog>
#include <qscreen.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //Setup the inventory table
    inventoryTableStyleSetup();

}

Widget::~Widget()
{
    delete ui;
}
/*******************************************************************************************************************/
/*******************************************************************************************************************/

void Widget::inventoryTableStyleSetup()
{
    //Create the table rows and coloums
    ui->inventoryTableWidget->setColumnCount(5);
    //ui->inventoryTableWidget->setRowCount(100);

    //Set Table Headers
    QStringList headers {"Manufacturer part number","Quantity","Component Type","Footrpint","Location of Component"};
    ui->inventoryTableWidget->setHorizontalHeaderLabels(headers);

    // Stretch columns to fill the table width
    ui->inventoryTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Allow sorting by clicking on headers
    ui->inventoryTableWidget->setSortingEnabled(true);

    // Make rows selectable as whole rows
    ui->inventoryTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Optional: Set table to read-only (no direct editing)
    ui->inventoryTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //Styling of Coloums headers
    ui->inventoryTableWidget->horizontalHeader()->setStyleSheet(
        "QHeaderView::section {"
        "background-color: green;"
        "color: white;"            // optional: text color
        "font-weight: bold;"       // optional: make text bold
        "padding: 4px;"
        "}"
        );

    //styling of row's numbers
    ui->inventoryTableWidget->verticalHeader()->setStyleSheet(
        "QHeaderView::section {"
        "background-color: gray;"
        "color: white;"            // optional: text color
        "font-weight: bold;"       // optional: make text bold
        "padding: 4px;"
        "}"
        );
}

/*******************************************************************************************************************/
/*******************************************************************************************************************/


/**
 * @brief add the input data from user to component list
 *        and show it in table.
 *
 * @param signal from add button.
 * @return
 */
void Widget::on_addPushButton_clicked()
{
    //get the values from user
    QString user_MPN = ui->MPNLineEdit->text();
    QString user_location = ui->locationLineEdit->text();
    QString user_type = ui->typeComboBox->currentText();
    QString user_footprint = ui->footprintComboBox->currentText();
    int     user_quantity = ui->quantitySpinBox->value();

    //creat an object from user input values
    Component user_component;
    user_component.setMPN(user_MPN);
    user_component.setLocation(user_location);
    user_component.setType(user_type);
    user_component.setFootpint(user_footprint);
    user_component.setQuantity(user_quantity);

    // add the user component to the component list
    componentList.push_back(user_component);

    //show the component list after update
    showComponentsInTable();

}

/**
 * @brief reset all the parameters of user data
 *
 * @param signal from clear button.
 * @return default values.
 */
void Widget::on_clearPushButton_clicked()
{
    ui->MPNLineEdit->clear();
    ui->locationLineEdit->clear();
    ui->typeComboBox->setCurrentIndex(0);
    ui->footprintComboBox->setCurrentIndex(0);
    ui->quantitySpinBox->setValue(0);
}

void Widget::on_exportPushButton_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(
        this,
        "Export CSV",
        QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/inventory.csv",
        "CSV Files (*.csv)"
        );

    if (!filePath.isEmpty()) {
        exportToCSV(filePath);
    }
}


/*******************************************************************************************************************/
/*******************************************************************************************************************/


/**
 * @brief reset all the parameters of user data
 *
 * @param signal from clear button.
 * @return default values.
 */
void Widget::showComponentsInTable()
{
    //clear the table
    ui->inventoryTableWidget->setRowCount(0);

    //set the number or raws according to the component list elements
    ui->inventoryTableWidget->setRowCount(componentList.size());

    for(int row = 0; row<componentList.size(); row++)
    {
        Component currentComponent = componentList[row];

        ui->inventoryTableWidget->setItem(row,0,new QTableWidgetItem(currentComponent.getMPN()));
        ui->inventoryTableWidget->setItem(row,1,new QTableWidgetItem(QString::number(currentComponent.getQuantity())));
        ui->inventoryTableWidget->setItem(row,2,new QTableWidgetItem(currentComponent.getType()));
        ui->inventoryTableWidget->setItem(row,3,new QTableWidgetItem(currentComponent.getFootprint()));
        ui->inventoryTableWidget->setItem(row,4,new QTableWidgetItem(currentComponent.getLocation()));
    }
}


/*******************************************************************************************************************/
/*******************************************************************************************************************/

void Widget::exportToCSV(const QString &filePath)
{
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);

        // Write headers
        QStringList headers;
        for (int col = 0; col < ui->inventoryTableWidget->columnCount(); col++) {
            headers << ui->inventoryTableWidget->horizontalHeaderItem(col)->text();
        }
        out << headers.join(",") << "\n";

        // Write each row
        for (int row = 0; row < ui->inventoryTableWidget->rowCount(); row++) {
            QStringList rowData;
            for (int col = 0; col < ui->inventoryTableWidget->columnCount(); ++col) {
                QTableWidgetItem *item = ui->inventoryTableWidget->item(row, col);
                rowData << (item ? item->text() : "");
            }
            out << rowData.join(",") << "\n";
        }

        file.close();
    } else {
        QMessageBox::warning(this, "Error", "Cannot write file!");
    }
}

/*******************************************************************************************************************/
/*******************************************************************************************************************/


