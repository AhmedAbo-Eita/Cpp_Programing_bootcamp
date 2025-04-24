#include "mainwindow.h"
#include <QPushButton>
#include <QAction>
#include <QApplication>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    //creating main push button
    QPushButton *button = new QPushButton("Hello", this);
    //button->setGeometry(100,100,100,100);
    setCentralWidget(button);

    quitAction = new QAction("Quit",this);

    connect(quitAction,&QAction::triggered,[=](){
        QApplication::quit();
    });

    //adding menu bar
    QMenu *fileMenu = menuBar()->addMenu("File");
    fileMenu ->addAction(quitAction);
    menuBar()->addMenu("Edit");
    menuBar()->addMenu("Window");
    menuBar()->addMenu("Settings");
    menuBar()->addMenu("Help");


    //add status bar
    statusBar()->showMessage("Ready");
}



// set the size of the window
QSize MainWindow::sizeHint() const
{
    return QSize(1000,1000);
}
