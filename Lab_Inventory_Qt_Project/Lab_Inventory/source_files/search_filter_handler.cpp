#include "../header_files/search_filter_handler.h"

/**
 * @brief Searches for a specific component string within a designated column of a QTableWidget.
 * This function performs a case-insensitive search through all rows of the table. It cleans
 * the target input string by stripping all whitespace, newlines, and tabs before comparison.
 * Safe pointer validation is included to prevent crashes on uninitialized or empty table cells.
 *
 * @param table         Pointer to the QTableWidget instance to search within.
 * @param item          The target component string (e.g., a Part Number) to look for.
 * @param search_column The zero-based index of the table column to scan.
 *
 * @return std::optional<int> The zero-based row index if a match is found;
 * std::nullopt if the item is not found or the cell is empty.
 */
std::optional<int> searchItemInTable(QTableWidget *tableWidget,QString item,int search_colomn)
{
    for(int item_row = 0 ; item_row < tableWidget->rowCount() ;item_row++)
    {
        //Guard Clause protection
        if (!tableWidget) return std::nullopt;
        //remove all spaces in the input text and make all letters in uppercase
        item = item.remove(' ').remove('\n').toUpper();

        //  Get the pointer to the item first
        QTableWidgetItem* currentItem = tableWidget->item(item_row, search_colomn);
        // Searching on component in table
        // Check if the item actually exists before reading its text
        if (currentItem && currentItem->text().remove(' ').remove('\n').toUpper() == item)
        {
            qDebug()<< "Item Founded at row= " << item_row+1 << " Table index = "<< item_row;
            return item_row;
        }
    }
    qDebug()<< "Item Not Founded";
    return std::nullopt;
}


// std::optional<int> filterTable(QTableWidget *table,QString filterText)
// {

// }
