#ifndef IMPORT_EXPORT_HANDLER_H
#define IMPORT_EXPORT_HANDLER_H


#include <QObject>
#include <QWidget>
#include "qtablewidget.h"
#include "component.h"


void importTableFromCSV(QTableWidget *tableWidget, std::vector<Component> &componentList, QWidget *parent);
void exportTableToCSV(QTableWidget *tableWidget,QWidget *parent);
void importTableFromCSVLocal(QTableWidget *tableWidget,QString filePath,
                             std::vector <Component> &componentList,QWidget *parent);
void exportTableToCSVLocal(QTableWidget *tableWidget,QString filePath,
                           std::vector <Component> &componentListoldSave,
                           std::vector <Component> &componentList ,QWidget *parent);
void checkCSV(QString dataDirPath, QString destPath, QWidget *parent);

#endif // IMPORT_EXPORT_HANDLER_H
