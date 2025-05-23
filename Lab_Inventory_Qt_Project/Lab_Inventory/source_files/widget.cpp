#include "../header_files/widget.h"
#include "./ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //Setup the inventory table
    inventoryTableStyleSetup();


    /**
     * @brief add the input data from user to component list
     *        and show it in table.
     *
     * @param signal from add button.
     * @return
     */
    connect(ui->addPushButton,&QPushButton::clicked,this,[=]()
    {
        if(ui->MPNLineEdit->text().isEmpty() && ui->locationLineEdit->text().isEmpty())
        {
            QMessageBox::critical(this, tr("Not Completed Info"),
                                        tr("You do not insert the MPN and location of component.\n"
                                        "Please insert the all info needed"),QMessageBox:: Ok);
        }
        else if(ui->MPNLineEdit->text().isEmpty())
        {
            QMessageBox::critical(this, tr("Not Completed Info"),
                                  tr("You do not insert the MPN of component.\n"
                                     "Please insert the all info needed"),QMessageBox:: Ok);
        }
        else if(ui->locationLineEdit->text().isEmpty())
        {
            QMessageBox::critical(this, tr("Not Completed Info"),
                                  tr("You do not insert the Location of component.\n"
                                     "Please insert the all info needed"),QMessageBox:: Ok);
        }
        else
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

            if(searchComponentsInTable(user_MPN) == std::nullopt)
            {
                // add the user component to the component list
                componentList.push_back(user_component);

                //show the component list after update
                showComponentsInTable();

                //reset all the input data to default state
                ui->MPNLineEdit->clear();
                ui->locationLineEdit->clear();
                ui->quantitySpinBox->setValue(0);
                ui->footprintComboBox->setCurrentIndex(0);
                ui->typeComboBox->setCurrentIndex(0);
            }
            else
            {
                QMessageBox::critical(this, tr("Not New Component"),
                                      tr("This component is already founded in your inventory\n"
                                         "Please cheack it"),QMessageBox:: Ok);
            }
        }
    });


    /**
     * @brief reset all the parameters of user data
     *
     * @param signal from clear button.
     * @return default values.
     */
    connect(ui->clearPushButton,&QPushButton::clicked,this,[=]()
    {
        ui->MPNLineEdit->clear();
        ui->locationLineEdit->clear();
        ui->typeComboBox->setCurrentIndex(0);
        ui->footprintComboBox->setCurrentIndex(0);
        ui->quantitySpinBox->setValue(0);
    });


    /**
     * @brief this function clear all the data in table dependent on signal
     * from clear pushBotton using connect function
     *
     * @param signal from clean button.
     * @return empty table
     */
    connect(ui->cleanPushButton, &QPushButton::clicked, this, [=](){
        componentList = {};// clear all components in component list
        showComponentsInTable();
    });


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


    // Set the font
    // QFont appFont("Blinker", 12);
    // QApplication::setFont(appFont);

}


void Widget::showComponentsInTable()
{
    //clear the table
    ui->inventoryTableWidget->setRowCount(0);

    //set the number or raws according to the component list elements
    ui->inventoryTableWidget->setRowCount(componentList.size());

    for(std::size_t row = 0; row<componentList.size(); row++)
    {
        Component currentComponent = componentList[row];

        ui->inventoryTableWidget->setItem(row,0,new QTableWidgetItem(currentComponent.getMPN()));
        ui->inventoryTableWidget->setItem(row,1,new QTableWidgetItem(QString::number(currentComponent.getQuantity())));
        ui->inventoryTableWidget->setItem(row,2,new QTableWidgetItem(currentComponent.getType()));
        ui->inventoryTableWidget->setItem(row,3,new QTableWidgetItem(currentComponent.getFootprint()));
        ui->inventoryTableWidget->setItem(row,4,new QTableWidgetItem(currentComponent.getLocation()));
    }
}

std::optional<int> Widget::searchComponentsInTable(QString MPN){
    for(std::size_t component_index = 0 ; component_index < componentList.size();component_index++)
    {
        if (ui->inventoryTableWidget->item(component_index,0)->text() == MPN)
        {
            return component_index;
        }
    }
    return std::nullopt;
}



