# include"../header_files/import_export_handler.h"
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
void exportTableToCSVLocal(QTableWidget *tableWidget,QString filePath,std::vector <Component> componentListoldSave
                           ,std::vector <Component> componentList ,QWidget *parent)
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
void importTableFromCSV(QTableWidget *tableWidget, std::vector <Component> componentList,QWidget *parent)
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
    int row = tableWidget->rowCount();
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
void importTableFromCSVLocal(QTableWidget *tableWidget, QString filePath,
                             std::vector<Component> componentList, QWidget *parent)
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


