#include "../header_files/widget.h"
#include "./ui_widget.h"


//Macros
//number of colums of attributs in table
#define quantityOfComponent     1
#define typeOfComponent         2
#define footprintOfComponent    3
#define locationOfComponent     4

//Global Variables
std::optional<int> updatedIndex;

QString dataDirPath = QCoreApplication::applicationDirPath() + "/data";
// Prepare CSV file path
QString destPath = dataDirPath + "/My_Inventory.csv";


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Setup the inventory table
    inventoryTableStyleSetup();

    //connect functions of widget
    widget_connect_func();

    //Check the CSV file
    checkCSV();

    //import the local CSV file to the application
    importTableFromCSVLocal(ui->inventoryTableWidget,destPath ,this);


}

Widget::~Widget()
{
    delete ui;
}
/*******************************************************************************************************************/
/*******************************************************************************************************************/


void Widget::widget_connect_func()
{
    /*--------------------------------------------------------------------------------------------*/
    /**********************************************************************************************/
    /*--------------------------------------------------------------------------------------------*/

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


    /*--------------------------------------------------------------------------------------------*/
    /**********************************************************************************************/
    /*--------------------------------------------------------------------------------------------*/

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


    /*--------------------------------------------------------------------------------------------*/
    /**********************************************************************************************/
    /*--------------------------------------------------------------------------------------------*/

    /**
     * @brief this function clear all the data in table dependent on signal
     * from clear pushBotton using connect function
     *
     * @param signal from clean button.
     * @return empty table
     */
    connect(ui->cleanPushButton, &QPushButton::clicked, this, [=](){
        // Message to make sure that the user need to clean the inventory tabto avoid cliking by accident
        auto ret = QMessageBox::question(this, tr("Reset to the last save"),
                                         tr("Do you want to Clear all the data in the inventory table?"),
                                         QMessageBox::Ok | QMessageBox::Cancel);

        if(ret == QMessageBox::Ok)
        {
            componentList = {};// clear all components in component list
            showComponentsInTable();
        }
        else return;
    });


    /*--------------------------------------------------------------------------------------------*/
    /**********************************************************************************************/
    /*--------------------------------------------------------------------------------------------*/


    /**
     * @brief This connect function to rest the table of lab inventory to the last save
     *
     * @param signal from reset button.
     * @return load the last save of inventory
     */
    connect(ui->resetPushButton,&QPushButton::clicked,this,[=]()
    {
        // Message to make sure that the user need to resrt to avoid cliking by accident
        auto ret = QMessageBox::question(this, tr("Reset to the last save"),
                                tr("Do you want to reset all the changes to the last save?"),
                                QMessageBox::Ok | QMessageBox::Cancel);

        if (ret == QMessageBox::Ok)
        {
            componentList = {};// clear all components in component list
            showComponentsInTable();
            importTableFromCSVLocal(ui->inventoryTableWidget,destPath ,this);

        }
        else return;
    });

    /*--------------------------------------------------------------------------------------------*/
    /**********************************************************************************************/
    /*--------------------------------------------------------------------------------------------*/

    /**
     * @brief This connect function to save the current table to the local CSV file
     *
     * @param signal from reset button.
     * @return load the last save of inventory
     */
    connect(ui->savePushButton,&QPushButton::clicked,this,[=]()
    {
        // Message to make sure that the user need to Save to avoid cliking by accident
        auto ret = QMessageBox::question(this, tr("Reset to the last save"),
                                         tr("Do you want to reset all the changes to the last save?"),
                                         QMessageBox::Ok | QMessageBox::Cancel);

        if(ret == QMessageBox::Ok)
        {
            exportTableToCSVLocal(ui->inventoryTableWidget,destPath,this);
        }
        else return;
    });

    /*--------------------------------------------------------------------------------------------*/
    /**********************************************************************************************/
    /*--------------------------------------------------------------------------------------------*/

    /**
     * @brief Export the inventory table as CSV.
     *
     * @param signal from Export button.
     * @return non
     */
    connect(ui->exportPushButton,&QPushButton::clicked,this,[=](){
        exportTableToCSV(ui->inventoryTableWidget,this);
    });

    /*--------------------------------------------------------------------------------------------*/
    /**********************************************************************************************/
    /*--------------------------------------------------------------------------------------------*/

    /**
     * @brief Import Data from CSV file and put it in vector component list
     * then show it in the taple.
     *
     * @param signal from import button.
     * @return non
     */
    connect(ui->importPushButton,&QPushButton::clicked,this,[=](){
        importTableFromCSV(ui->inventoryTableWidget,this);
    });


    /*--------------------------------------------------------------------------------------------*/
    /**********************************************************************************************/
    /*--------------------------------------------------------------------------------------------*/

    /**
     * @brief show the PDF of the footprint packages externally
     *
     * @param signal from footprintPackageExternalButton button.
     * @return open the PDF
     */
    connect(ui->footprintPackageExternalButton,&QPushButton::clicked,this,[=](){
        //create a string includes the pdfPath
        QString pdfPath = ":/footprint/footprint/SMDDimensionSelectionGuide.pdf";

        //crating pdfFile
        QFile pdfFile(pdfPath);

        if (!pdfFile.open(QIODevice::ReadOnly)) {
            QMessageBox::warning(this, "Error", "Failed to load embedded PDF.");
            return;
        }

        // Write to a temporary file
        QTemporaryFile tempFile(QDir::tempPath() + "/XXXXXX.pdf");
        if (!tempFile.open()) {
            QMessageBox::warning(this, "Error", "Could not create a temporary file.");
            return;
        }

        tempFile.write(pdfFile.readAll());
        tempFile.flush(); // Ensure all data is written

        // Ensure the file stays after the function ends
        QString tempFilePath = tempFile.fileName();
        tempFile.setAutoRemove(false); // Optional: remove manually later if needed

        // Open the PDF
        bool opened = QDesktopServices::openUrl(QUrl::fromLocalFile(tempFilePath));
        if (!opened) {
            QMessageBox::warning(this, "Error", "Could not open the PDF file.");
        }


    });

    /*--------------------------------------------------------------------------------------------*/
    /**********************************************************************************************/
    /*--------------------------------------------------------------------------------------------*/

    /**
     * @brief Search on component in lab inventory by MPN
     *
     * @param signal from Search pushbutton button.
     * @return display status of the component on Ui
     */

    connect(ui->findPushButton,&QPushButton::clicked,this,[=]()
    {
        //component search and return its row index value
        std::optional<int> index = searchComponentsInTable(ui->searchMPNLineEdit->text());
        updatedIndex = index;


        // Check if the component available in inventory or not
        //if not let the user know
        if(index != std::nullopt)
        {
            //show the location of component
            ui->foundedLocationLable->setText(ui->inventoryTableWidget->item(*index,locationOfComponent)->text());
            //show the Quantity of component
            ui->foundedQuantityLabel->setText(ui->inventoryTableWidget->item(*index,quantityOfComponent)->text());
            //show the footprint of component
            ui->foundedFootprintLabel->setText(ui->inventoryTableWidget->item(*index,footprintOfComponent)->text());
            //show the type of component
            ui->foundedTypeLable->setText(ui->inventoryTableWidget->item(*index,typeOfComponent)->text());
        }
        else if (ui->searchMPNLineEdit->text().isEmpty())
        {
            QMessageBox::warning(this, tr("Component Search"),
                                 tr("You didn't enter the MPN\n"
                                    "Please insert it and try again"),
                                 QMessageBox::Ok);
        }
        else
        {
            auto ret = QMessageBox::warning(this, tr("Component Search"),
                                 tr("The MPN you Entered not in your inventory\n"
                                    "Do you want to add it?"),
                                 QMessageBox::Ok |QMessageBox::Cancel);
            if(ret == QMessageBox::Ok)
            {
                ui->tabWidget->setCurrentIndex(0);//open add component widget
                ui->MPNLineEdit->setText(ui->searchMPNLineEdit->text());// copy the MPN to the tab of add
                ui->locationLineEdit->setFocus();// move the pointer to Location
                ui->searchMPNLineEdit->clear();//clear the search editline
            }
        }
    });

    /*--------------------------------------------------------------------------------------------*/
    /**********************************************************************************************/
    /*--------------------------------------------------------------------------------------------*/

    /**
     * @brief Connect function while pressing the button of edit component from search tab
     * all the info of the component move to the Edit tab to edit it and then update inventory
     *
     * @param signal from Edit component of search groupbox pushbutton button.
     * @return display status of the component on edit group box
     */
    connect(ui->EditComponentPushButton, &QPushButton::clicked,this,[=]()
    {
        ui->tabWidget->setCurrentIndex(1);
        ui->editMPNLineEdit->setText(ui->searchMPNLineEdit->text());

        //Disable search in Edit mode
        ui->editMPNLineEdit->setDisabled(true);
        ui->editFindpushButton->setDisabled(true);

        //Set the editable values to current vlaues as start
        ui->editQuantitySpinBox->setValue(ui->foundedQuantityLabel->text().toInt());
        ui->editFootprintLineEdit->setText(ui->foundedFootprintLabel->text());
        ui->editLocatioLineEdit->setText(ui->foundedLocationLable->text());
        ui->editTypeComboBox->setCurrentIndex(getComponentTypeIndex(ui->foundedTypeLable->text().remove(' ').remove('\n')));

        //reset the search tabs values
        ui->foundedFootprintLabel->clear();
        ui->foundedLocationLable->clear();
        ui->foundedQuantityLabel->clear();
        ui->foundedTypeLable->clear();
        ui->searchMPNLineEdit->clear();
    });

    /*--------------------------------------------------------------------------------------------*/
    /**********************************************************************************************/
    /*--------------------------------------------------------------------------------------------*/

    /**
     * @brief Connect function while pressing the button of find component from edit tab
     * all the info of the component move to the Edit tab to edit it and then update inventory
     * Checking if the MPN in inventory or not if not ask the user to add it
     *
     * @param signal from find component of Edit groupbox pushbutton button.
     * @return display status of the component on edit group box to help the user to edit it
     */
    connect(ui->editFindpushButton,&QPushButton::clicked,this,[=]()
    {
        //Searching on the component
        std::optional<int> index = searchComponentsInTable(ui->editMPNLineEdit->text());
        updatedIndex = index;

        // Check if the component available in inventory or not
        //if not let the user know
        if(index != std::nullopt)
        {
            //show the location of component
            ui->editLocatioLineEdit->setText(ui->inventoryTableWidget->item(*index,locationOfComponent)->text());
            //show the Quantity of component
            ui->editQuantitySpinBox->setValue(ui->inventoryTableWidget->item(*index,quantityOfComponent)->text().toInt());
            //show the footprint of component
            ui->editFootprintLineEdit->setText(ui->inventoryTableWidget->item(*index,footprintOfComponent)->text());
            //show the type of component
            ui->editTypeComboBox->setCurrentIndex(getComponentTypeIndex(ui->inventoryTableWidget->item(*index,typeOfComponent)->text().remove(' ').remove('\n')));
            //disable editing on component
            ui->editMPNLineEdit->setDisabled(true);
            ui->editFindpushButton->setDisabled(true);
        }
        else if (ui->editMPNLineEdit->text().isEmpty())
        {
            QMessageBox::warning(this, tr("Component Search"),
                                 tr("You didn't enter the MPN\n"
                                    "Please insert it and try again"),
                                 QMessageBox::Ok);
        }
        else
        {
            auto ret = QMessageBox::warning(this, tr("Component Search"),
                                            tr("The MPN you Entered not in your inventory\n"
                                               "Do you want to add it?"),
                                            QMessageBox::Ok |QMessageBox::Cancel);
            if(ret == QMessageBox::Ok)
            {
                ui->tabWidget->setCurrentIndex(0);//open add component widget
                ui->MPNLineEdit->setText(ui->editMPNLineEdit->text());// copy the MPN to the tab of add
                ui->locationLineEdit->setFocus();// move the pointer to Location
            }
        }

    });

    /*--------------------------------------------------------------------------------------------*/
    /**********************************************************************************************/
    /*--------------------------------------------------------------------------------------------*/
    /**
     * @brief Connect function that update the data of inventory table
     *
     * @param signal from Edit component of Edit groupbox pushbutton button.
     * @return change the values according to user input and save it in table and component list
     */
    connect(ui->applyEditspushButton,&QPushButton::clicked,this,[=]()
    {
        //update table widget
        ui->inventoryTableWidget->item(*updatedIndex,locationOfComponent)->setText(ui->editLocatioLineEdit->text());
        ui->inventoryTableWidget->item(*updatedIndex,footprintOfComponent)->setText(ui->editFootprintLineEdit->text());
        ui->inventoryTableWidget->item(*updatedIndex,quantityOfComponent)->setText(ui->editQuantitySpinBox->text());
        ui->inventoryTableWidget->item(*updatedIndex,typeOfComponent)->setText(ui->editTypeComboBox->currentText());

        //update Component list
        componentList.at(*updatedIndex).setLocation(ui->editLocatioLineEdit->text());
        componentList.at(*updatedIndex).setFootpint(ui->editFootprintLineEdit->text());
        componentList.at(*updatedIndex).setQuantity(ui->editQuantitySpinBox->text().toInt());
        componentList.at(*updatedIndex).setType(ui->editTypeComboBox->currentText());

        //clear editline
        ui->editFootprintLineEdit->clear();
        ui->editLocatioLineEdit->clear();
        ui->editMPNLineEdit->clear();
        ui->editQuantitySpinBox->setValue(0);
        ui->editTypeComboBox->setCurrentIndex(0);

        // Enable to find component
        //disable editing on component
        ui->editMPNLineEdit->setDisabled(false);
        ui->editFindpushButton->setDisabled(false);
    });

    /*--------------------------------------------------------------------------------------------*/
    /**********************************************************************************************/
    /*--------------------------------------------------------------------------------------------*/
    /**
     * @brief Connect function that delete a component from inventory table
     *
     * @param signal from delete component of Edit groupbox pushbutton button.
     * @return remove component
     */

    connect(ui->deleteComponentpushButton,&QPushButton::clicked,this,[=]()
    {
        auto ret = QMessageBox::information(this, tr("Component Delete"),
                             tr("Are you sure, Do you want to delete this component?"),
                             QMessageBox::Ok | QMessageBox::Cancel );

        if(ret == QMessageBox::Ok)
        {
            int index = *updatedIndex;
            ui->inventoryTableWidget->removeRow(*updatedIndex);
            componentList.erase(componentList.begin() + index);
            //clear editline
            ui->editFootprintLineEdit->clear();
            ui->editLocatioLineEdit->clear();
            ui->editMPNLineEdit->clear();
            ui->editQuantitySpinBox->setValue(0);
            ui->editTypeComboBox->setCurrentIndex(0);

            // Enable to find component
            //disable editing on component
            ui->editMPNLineEdit->setDisabled(false);
            ui->editFindpushButton->setDisabled(false);
        }
        else return;
    });

}

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

/*--------------------------------------------------------------------------------------------*/
/**********************************************************************************************/
/*--------------------------------------------------------------------------------------------*/

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


/*--------------------------------------------------------------------------------------------*/
/**********************************************************************************************/
/*--------------------------------------------------------------------------------------------*/

std::optional<int> Widget::searchComponentsInTable(QString MPN){
    for(std::size_t component_index = 0 ; component_index < componentList.size();component_index++)
    {
        //remove all spaces in the input text and make all letters in uppercase
        MPN = MPN.remove(' ').remove('\n').toUpper();

        // Searching on component in table
        if (ui->inventoryTableWidget->item(component_index,0)->text().toUpper() == MPN)
        {
            return component_index;
        }
    }
    return std::nullopt;
}

/*--------------------------------------------------------------------------------------------*/
/**********************************************************************************************/
/*--------------------------------------------------------------------------------------------*/


/**
 * @brief Exports the contents of a QTableWidget to a CSV file.
 *
 * This function opens a file dialog for the user to select a location and filename,
 * then writes the table's header and contents row-by-row into a properly formatted
 * CSV (Comma-Separated Values) file.
 *
 * @param tableWidget Pointer to the QTableWidget containing the data to export.
 * @param parent Optional parent widget, used for file dialog and message boxes.
 */
void Widget::exportTableToCSV(QTableWidget *tableWidget, QWidget *parent)
{
    // User select the file name and location and store it in fileName
    QString fileName = QFileDialog::getSaveFileName(parent, "Save as CSV", "My_Inventory.csv", "CSV Files (*.csv)");

    //if user click cancel --> do nothing
    if (fileName.isEmpty()) return;

    //create a QFile to write the file needed
    QFile file(fileName);

    //
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(parent, "Unable to open file", file.errorString());
        return;
    }

    // QTextStream handles formatted text output to the file
    QTextStream out(&file);

    // Write headers
    QStringList headers;
    for (int col = 0; col < tableWidget->columnCount(); col++) {
        QTableWidgetItem *headerItem = tableWidget->horizontalHeaderItem(col);
        headers << (headerItem ? "\"" + headerItem->text() + "\"" : "\"\"");
    }
    out << headers.join(",") << "\n";

    // Write table content
    for (int row = 0; row < tableWidget->rowCount(); ++row) {
        QStringList rowContents;
        for (int col = 0; col < tableWidget->columnCount(); col++) {
            QTableWidgetItem *item = tableWidget->item(row, col);
            rowContents << "\"" + (item ? item->text() : "") + "\"";
        }
        out << rowContents.join(",") << "\n";
    }

    file.close();
    QMessageBox::information(parent, "Export Complete", "Inventory table was saved to CSV successfully.");
}


/*--------------------------------------------------------------------------------------------*/
/**********************************************************************************************/
/*--------------------------------------------------------------------------------------------*/

/**
 * @brief Exports the contents of a QTableWidget to a CSV Local file.
 * writes the table's header and contents row-by-row into a properly formatted
 * CSV (Comma-Separated Values) file.
 *
 * @param tableWidget Pointer to the QTableWidget containing the data to export.
 * @param parent Optional parent widget, used for file dialog and message boxes.
 * @param filePath: this is the path of the local CSV file
 */
void Widget::exportTableToCSVLocal(QTableWidget *tableWidget,QString filePath ,QWidget *parent)
{
    //if user click cancel --> do nothing
    if (filePath.isEmpty()) return;

    //create a QFile to write the file needed
    QFile file(filePath);

    //
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(parent, "Unable to open file", file.errorString());
        return;
    }

    // QTextStream handles formatted text output to the file
    QTextStream out(&file);

    // Write headers
    QStringList headers;
    for (int col = 0; col < tableWidget->columnCount(); col++) {
        QTableWidgetItem *headerItem = tableWidget->horizontalHeaderItem(col);
        headers << (headerItem ? "\"" + headerItem->text() + "\"" : "\"\"");
    }
    out << headers.join(",") << "\n";

    // Write table content
    for (int row = 0; row < tableWidget->rowCount(); ++row) {
        QStringList rowContents;
        for (int col = 0; col < tableWidget->columnCount(); col++) {
            QTableWidgetItem *item = tableWidget->item(row, col);
            rowContents << "\"" + (item ? item->text() : "") + "\"";
        }
        out << rowContents.join(",") << "\n";
    }

    file.close();
    QMessageBox::information(parent, "Export Complete", "Inventory table was saved to CSV successfully.");
}


/*--------------------------------------------------------------------------------------------*/
/**********************************************************************************************/
/*--------------------------------------------------------------------------------------------*/

/**
 * @brief Imports data from a CSV file into a QTableWidget and updates the component list.
 *
 * This function:
 * - Prompts user to select a CSV file.
 * - Clears the table and component list.
 * - Parses the CSV and populates the table.
 * - Converts each row into a Component object and updates componentList.
 *
 * @param tableWidget Pointer to the QTableWidget to be filled.
 * @param parent Optional parent widget for dialogs.
 */
void Widget::importTableFromCSV(QTableWidget *tableWidget, QWidget *parent)
{
    //Dialoge to get the path of CSV file and store it in fileName
    QString fileName = QFileDialog::getOpenFileName(parent,
                                                    "Open CSV File",
                                                    "",
                                                    "CSV Files (*.csv)");

    // if user click cancel do nothing
    if (fileName.isEmpty())return;

    //Create an object file from QFile
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(parent, "Unable to open file", file.errorString());
        return;
    }


    QTextStream in(&file);

    // Clear the existing table and component list
    tableWidget->setRowCount(0);//set the table rows
    tableWidget->setColumnCount(0);//set the table colomns
    componentList.clear(); // clear all the data in component list

    // Read headers
    if (!in.atEnd()) {
        QString headerLine = in.readLine();
        QStringList headers = headerLine.split(',', Qt::KeepEmptyParts);
        for (QString &header : headers)
            header = header.remove('\"');
        tableWidget->setColumnCount(headers.size());
        tableWidget->setHorizontalHeaderLabels(headers);
    }

    // Read and parse each row
    int row = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList cells = line.split(',', Qt::KeepEmptyParts);
        if (cells.size() < 5) continue; // Skip incomplete rows

        tableWidget->insertRow(row);

        QString current_mpn        = cells[0].remove('\"');
        QString current_quantity   = cells[1].remove('\"');
        QString current_type       = cells[2].remove('\"');
        QString current_footprint  = cells[3].remove('\"');
        QString current_location   = cells[4].remove('\"');

        // Fill the table
        tableWidget->setItem(row, 0, new QTableWidgetItem(current_mpn));
        tableWidget->setItem(row, 1, new QTableWidgetItem(current_quantity));
        tableWidget->setItem(row, 2, new QTableWidgetItem(current_type));
        tableWidget->setItem(row, 3, new QTableWidgetItem(current_footprint));
        tableWidget->setItem(row, 4, new QTableWidgetItem(current_location));

        // Add to componentList
        Component c;
        c.setMPN(current_mpn);
        c.setQuantity(current_quantity.toInt());
        c.setType(current_type);
        c.setFootpint(current_footprint);
        c.setLocation(current_location);
        componentList.push_back(c);

        ++row;
    }

    file.close();
    QMessageBox::information(parent, "Import Complete", "Inventory table and component list loaded from CSV.");
}


/*--------------------------------------------------------------------------------------------*/
/**********************************************************************************************/
/*--------------------------------------------------------------------------------------------*/


/**
 * @brief Imports data from a CSV file into a QTableWidget and updates the component list.
 *
 * This function:
 * - Prompts user to select a CSV file.
 * - Clears the table and component list.
 * - Parses the CSV and populates the table.
 * - Converts each row into a Component object and updates componentList.
 *
 * @param tableWidget Pointer to the QTableWidget to be filled.
 * @param Path of CSV in resource file.
 * @param parent Optional parent widget for dialogs.
 */
void Widget::importTableFromCSVLocal(QTableWidget *tableWidget, QString filePath,QWidget *parent)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(parent, "Unable to open file", file.errorString());
        return;
    }


    QTextStream in(&file);

    // Clear the existing table and component list
    tableWidget->setRowCount(0);//set the table rows
    tableWidget->setColumnCount(0);//set the table colomns
    componentList.clear(); // clear all the data in component list

    // Read headers
    if (!in.atEnd()) {
        QString headerLine = in.readLine();
        QStringList headers = headerLine.split(',', Qt::KeepEmptyParts);
        for (QString &header : headers)
            header = header.remove('\"');
        tableWidget->setColumnCount(headers.size());
        tableWidget->setHorizontalHeaderLabels(headers);
    }

    // Read and parse each row
    int row = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList cells = line.split(',', Qt::KeepEmptyParts);
        if (cells.size() < 5) continue; // Skip incomplete rows

        tableWidget->insertRow(row);

        QString current_mpn        = cells[0].remove('\"');
        QString current_quantity   = cells[1].remove('\"');
        QString current_type       = cells[2].remove('\"');
        QString current_footprint  = cells[3].remove('\"');
        QString current_location   = cells[4].remove('\"');

        // Fill the table
        tableWidget->setItem(row, 0, new QTableWidgetItem(current_mpn));
        tableWidget->setItem(row, 1, new QTableWidgetItem(current_quantity));
        tableWidget->setItem(row, 2, new QTableWidgetItem(current_type));
        tableWidget->setItem(row, 3, new QTableWidgetItem(current_footprint));
        tableWidget->setItem(row, 4, new QTableWidgetItem(current_location));

        // Add to componentList
        Component c;
        c.setMPN(current_mpn);
        c.setQuantity(current_quantity.toInt());
        c.setType(current_type);
        c.setFootpint(current_footprint);
        c.setLocation(current_location);
        componentList.push_back(c);
        ++row;
    }
    file.close();
    //QMessageBox::information(parent, "Import Complete", "Inventory table and component list loaded from CSV.");
}



/*--------------------------------------------------------------------------------------------*/
/**********************************************************************************************/
/*--------------------------------------------------------------------------------------------*/

/**
 * @brief function to return the value index of component type.
 *
 * @param Type of component as string.
 * @return index value
 */
int Widget::getComponentTypeIndex(QString type)
{
    if(type == "IC")            return 0;
    if(type == "MOSFET")        return 1;
    if(type == "Transistor")    return 2;
    if(type == "Connector")     return 3;
    if(type == "Resistor")      return 4;
    if(type == "Capacitor")     return 5;
    if(type == "Inductor")      return 6;
    if(type == "Diode")         return 7;
    else                        return -1;
}


/*--------------------------------------------------------------------------------------------*/
/**********************************************************************************************/
/*--------------------------------------------------------------------------------------------*/

/**
 * @brief function to check the local database CSV file.
 *
 * @param
 * @return
 */

void Widget::checkCSV()
{
    //load the local database csv file from resorce file
    // Prepare data directory path next to executable

    QDir dir(dataDirPath);
    if (!dir.exists()) {
        dir.mkpath(".");
    }

    if (!QFile::exists(destPath)) {
        QFile file(destPath);

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::warning(this, "Error", "Unable to create My_Inventory.csv:\n" + file.errorString());
            return;
        }
        QTextStream out(&file);
        // Write fixed headers
        out << "\"Manufacturer part number\",\"Quantity\",\"Component Type\",\"Footrpint\",\"Location of Component\"\n";
        file.close();

        QMessageBox::information(this, "Info", "New My_Inventory.csv created successfully.");
    }

}





