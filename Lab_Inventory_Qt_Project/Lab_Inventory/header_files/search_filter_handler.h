#ifndef SEARCH_FILTER_HANDLER_H
#define SEARCH_FILTER_HANDLER_H

#include <QObject>
#include <QWidget>
#include <QTableWidget>
#include <QRegularExpression>


std::optional<int> searchItemInTable(QTableWidget *table,QString item,int search_colomn);
std::optional<int> filterTable(QTableWidget *tableWidget, QString filterText);

#endif // SEARCH_FILTER_HANDLER_H
