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

/**
 * @brief Filters the rows of a QTableWidget by showing only rows that contain
 *        the filterText (case-insensitive, partial match) in ANY of their columns.
 *        Rows that do not match are hidden using setRowHidden() — the table data
 *        is never deleted or modified, only the visibility of rows changes.
 *
 * @param table       Pointer to the QTableWidget to filter.
 * @param filterText  The substring to search for across all columns.
 *
 * @return std::optional<int>  Number of rows that matched and are now visible,
 *                             or std::nullopt if the table pointer is null.
 */
 std::optional<int> filterTable(QTableWidget *tableWidget,QString filterText)
 {
    // Guard Clause
    // Validate the table pointer before doing anything else to prevent crashes.
    if (!tableWidget) return std::nullopt;

    // Handle Empty Filter 
    // If the user clears the filter box, restore ALL rows to visible and exit.
    if (filterText.trimmed().isEmpty()) // the condition here if the text is empty
    {
        for (int row = 0; row < tableWidget->rowCount(); row++)
            tableWidget->setRowHidden(row, false); // unhide every row
        qDebug() << "[Filter] Filter cleared — all" << tableWidget->rowCount() << "rows visible.";
        return tableWidget->rowCount(); // all rows are now visible
    }

    filterText = filterText.trimmed().remove(' ').remove('\n').remove('\t').toUpper();
    qDebug() << "[Filter] Searching for:" << filterText;

    //  4: Row-by-Row Scan
    int visibleCount = 0; // tracks how many rows pass the filter
    for (int row = 0; row < tableWidget->rowCount(); row++)
    {
        // Assume this row does NOT match until proven otherwise.
        bool rowMatched = false;
        // Column-by-Column Partial Match 
        // Scan every column of the current row looking for a partial match.
        // We use contains() instead of == so "STM" matches "STM32F103C8T6".
        for (int col = 0; col < tableWidget->columnCount(); col++)
        {
            // Get the cell item — it may be nullptr if the cell was never set.
            QTableWidgetItem *cellItem = tableWidget->item(row, col);
            // Skip null cells to avoid a crash (nullptr dereference).
            if (!cellItem) continue;
            // Normalize the cell text the same way we normalized filterText
            // so the comparison is always apples-to-apples.
            QString cellText = cellItem->text()
                                   .trimmed()
                                   .remove(' ')
                                   .remove('\n')
                                   .remove('\t')
                                   .toUpper();
            // Partial-match check: does this cell contain the filter string?
            if (cellText.contains(filterText))
            {
                rowMatched = true; // this row qualifies — no need to check more columns
                break;             // exit the inner column loop early (short-circuit)
            }
        }
        // Show or Hide the Row ─────────────────────────────────────
        // setRowHidden(row, true)   hides the row  (no match)
        // setRowHidden(row, false)  shows the row  (match found)
        tableWidget->setRowHidden(row, !rowMatched);
        if (rowMatched)
        {
            visibleCount++; // count how many rows survived the filter
            qDebug() << "[Filter] Match at row" << row;
        }
    }

    // ── Stage 7: Return Result ────────────────────────────────────────────────
    // Return the number of rows that are currently visible after filtering.
    qDebug() << "[Filter] Done —" << visibleCount << "row(s) matched out of" << tableWidget->rowCount();
    return visibleCount;
 }
