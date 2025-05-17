#include "widget.h"
#include <QApplication>
#include <QWidget>
#include <QScreen>


Widget *initialize_mainWindow();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget *mainWindow = initialize_mainWindow();
    mainWindow->show();

    return a.exec();
}


Widget *initialize_mainWindow()
{
    //Creating the mainWidget
    Widget *mainWidget = new Widget();

    //Add title to the mainWidget
    mainWidget->setWindowTitle("Lab Inventory");

    // Load and set window icon
    mainWidget->setWindowIcon(QIcon(":/inventoryMainIcons/Images/package_6215997.png"));

    //Set the size of mainWidget to Maximum
    mainWidget->showMaximized();

    return mainWidget;

}
