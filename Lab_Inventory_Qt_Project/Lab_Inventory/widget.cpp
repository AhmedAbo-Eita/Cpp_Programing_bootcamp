#include "widget.h"
#include "./ui_widget.h"
#include <QLabel>
#include <QGraphicsOpacityEffect>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    inventoryTableSetup();


}

Widget::~Widget()
{
    delete ui;
}

void Widget::inventoryTableSetup()
{
    //Create the table rows and coloums
    ui->inventoryTableWidget->setColumnCount(5);
    ui->inventoryTableWidget->setRowCount(100);

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
