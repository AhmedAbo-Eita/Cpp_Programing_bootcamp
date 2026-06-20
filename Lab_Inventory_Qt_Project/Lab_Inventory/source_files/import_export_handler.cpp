#include"../header_files/import_export_handler.h"
#include "header_files/widget.h"



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
void exportTableToCSV(QTableWidget *tableWidget, QWidget *parent)
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
void exportTableToCSVLocal(QTableWidget *tableWidget,QString filePath,std::vector <Component> &componentListoldSave
                           ,std::vector <Component> &componentList ,QWidget *parent)
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
    componentListoldSave = componentList;
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
void importTableFromCSV(QTableWidget *tableWidget, std::vector <Component> &componentList,QWidget *parent)
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
    //tableWidget->setRowCount(0);//set the table rows
    //tableWidget->setColumnCount(0);//set the table colomns
    //componentList.clear(); // clear all the data in component list

    // This map stores the actual index of each column from the CSV, allowing them to be in any order
    std::vector<int> columnIndexMap(7, -1);
    
    // Read headers
    if (!in.atEnd()) {
        QString headerLine = in.readLine();
        QStringList headers = headerLine.split(',', Qt::KeepEmptyParts);
        for (int i = 0; i < headers.size(); ++i) {
            QString header = headers[i];
            // Convert to lowercase and trim quotes/spaces to safely handle capital and small letters
            header = header.remove('\"').trimmed().toLower();
            
            // Map the CSV columns to our expected data regardless of their sort order
            if (header == "manufacturer part number") columnIndexMap[0] = i;
            else if (header == "quantity") columnIndexMap[1] = i;
            else if (header == "component type") columnIndexMap[2] = i;
            else if (header == "value") columnIndexMap[3] = i;
            else if (header == "footprint") columnIndexMap[4] = i;
            else if (header == "location of component") columnIndexMap[5] = i;
            else if (header == "customer code") columnIndexMap[6] = i;
        }

        // Verify that all required columns were found in the header
        bool validHeader = true;
        for (int idx : columnIndexMap) {
            if (idx == -1) { // -1 means the column was never found
                validHeader = false;
                break;
            }
        }
        
        if (!validHeader) {
            QMessageBox::warning(parent, "Invalid CSV File", "The selected CSV file does not contain the required headers.");
            file.close();
            return;
        }

        tableWidget->setColumnCount(7);
        QStringList standardHeaders = {"Manufacturer part number", "Quantity", "Component Type", "Value", "Footprint", "Location of Component", "Customer Code"};
        tableWidget->setHorizontalHeaderLabels(standardHeaders);
    }

    // Read and parse each row
    int row = tableWidget->rowCount();
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList cells = line.split(',', Qt::KeepEmptyParts);

        // Helper function to safely fetch data using the mapped column index
        auto getCell = [&](int internalIdx) -> QString {
            int csvIdx = columnIndexMap[internalIdx];
            if (csvIdx >= 0 && csvIdx < cells.size()) {
                QString cell = cells[csvIdx];
                return cell.remove('\"').trimmed();
            }
            return "";
        };

        QString current_mpn        = getCell(0);
        QString current_quantity   = getCell(1);
        if (current_quantity.isEmpty()) current_quantity = "0";
        QString current_type       = getCell(2);
        QString current_value      = getCell(3);
        QString current_footprint  = getCell(4);
        QString current_location   = getCell(5);
        QString current_customer   = getCell(6);

        if (current_mpn.isEmpty() && current_type.isEmpty() && current_value.isEmpty()) {
            continue; // Skip empty rows
        }

        tableWidget->insertRow(row);

        // Fill the table
        tableWidget->setItem(row, 0, new QTableWidgetItem(current_mpn));
        tableWidget->setItem(row, 1, new QTableWidgetItem(current_quantity));
        tableWidget->setItem(row, 2, new QTableWidgetItem(current_type));
        tableWidget->setItem(row, 3, new QTableWidgetItem(current_value));
        tableWidget->setItem(row, 4, new QTableWidgetItem(current_footprint));
        tableWidget->setItem(row, 5, new QTableWidgetItem(current_location));
        tableWidget->setItem(row, 6, new QTableWidgetItem(current_customer));

        // Add to componentList
        Component c;
        c.setMPN(current_mpn);
        c.setQuantity(current_quantity.toInt());
        c.setType(current_type);
        c.setValue(current_value);
        c.setFootpint(current_footprint);
        c.setLocation(current_location);
        c.setCustomercode(current_customer);
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
void importTableFromCSVLocal(QTableWidget *tableWidget, QString filePath,
                             std::vector<Component> &componentList, QWidget *parent)
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

    // This map stores the actual index of each column from the CSV, allowing them to be in any order
    std::vector<int> columnIndexMap(7, -1);
    
    // Read headers
    if (!in.atEnd()) {
        QString headerLine = in.readLine();
        QStringList headers = headerLine.split(',', Qt::KeepEmptyParts);
        for (int i = 0; i < headers.size(); ++i) {
            QString header = headers[i];
            // Convert to lowercase and trim quotes/spaces to safely handle capital and small letters
            header = header.remove('\"').trimmed().toLower();
            
            // Map the CSV columns to our expected data regardless of their sort order
            if (header == "manufacturer part number") columnIndexMap[0] = i;
            else if (header == "quantity") columnIndexMap[1] = i;
            else if (header == "component type") columnIndexMap[2] = i;
            else if (header == "value") columnIndexMap[3] = i;
            else if (header == "footprint") columnIndexMap[4] = i;
            else if (header == "location of component") columnIndexMap[5] = i;
            else if (header == "customer code") columnIndexMap[6] = i;
        }

        // Verify that all required columns were found in the header
        bool validHeader = true;
        for (int idx : columnIndexMap) {
            if (idx == -1) { // -1 means the column was never found
                validHeader = false;
                break;
            }
        }
        
        if (!validHeader) {
            QMessageBox::warning(parent, "Invalid CSV File", "The selected CSV file does not contain the required headers.");
            file.close();
            return;
        }

        tableWidget->setColumnCount(7);
        QStringList standardHeaders = {"Manufacturer part number", "Quantity", "Component Type", "Value", "Footprint", "Location of Component", "Customer Code"};
        tableWidget->setHorizontalHeaderLabels(standardHeaders);
    }

    // Read and parse each row
    int row = tableWidget->rowCount();
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList cells = line.split(',', Qt::KeepEmptyParts);

        // Helper function to safely fetch data using the mapped column index
        auto getCell = [&](int internalIdx) -> QString {
            int csvIdx = columnIndexMap[internalIdx];
            if (csvIdx >= 0 && csvIdx < cells.size()) {
                QString cell = cells[csvIdx];
                return cell.remove('\"').trimmed();
            }
            return "";
        };

        QString current_mpn        = getCell(0);
        QString current_quantity   = getCell(1);
        if (current_quantity.isEmpty()) current_quantity = "0";
        QString current_type       = getCell(2);
        QString current_value      = getCell(3);
        QString current_footprint  = getCell(4);
        QString current_location   = getCell(5);
        QString current_customer   = getCell(6);

        if (current_mpn.isEmpty() && current_type.isEmpty() && current_value.isEmpty()) {
            continue; // Skip empty rows
        }

        tableWidget->insertRow(row);

        // Fill the table
        tableWidget->setItem(row, 0, new QTableWidgetItem(current_mpn));
        tableWidget->setItem(row, 1, new QTableWidgetItem(current_quantity));
        tableWidget->setItem(row, 2, new QTableWidgetItem(current_type));
        tableWidget->setItem(row, 3, new QTableWidgetItem(current_value));
        tableWidget->setItem(row, 4, new QTableWidgetItem(current_footprint));
        tableWidget->setItem(row, 5, new QTableWidgetItem(current_location));
        tableWidget->setItem(row, 6, new QTableWidgetItem(current_customer));

        // Add to componentList
        Component c;
        c.setMPN(current_mpn);
        c.setQuantity(current_quantity.toInt());
        c.setType(current_type);
        c.setValue(current_value);
        c.setFootpint(current_footprint);
        c.setLocation(current_location);
        c.setCustomercode(current_customer);
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
 * @brief function to check the local database CSV file.
 *
 * @param
 * @return
 */
void checkCSV(QString dataDirPath,QString destPath,QWidget *parent)
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
            QMessageBox::warning(parent, "Error", "Unable to create My_Inventory.csv:\n" + file.errorString());
            return;
        }
        QTextStream out(&file);
        // Write fixed headers
        out << "\"Manufacturer part number\",\"Quantity\",\"Component Type\",\"Value\",\"Footprint\",\"Location of Component\",\"Customer Code\"\n";
        file.close();

        QMessageBox::information(parent, "Info", "New My_Inventory.csv created successfully.");
    }

}


