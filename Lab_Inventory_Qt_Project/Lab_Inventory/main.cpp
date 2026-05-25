#include "header_files/widget.h"
#include <QApplication>
#include <QFile>
#include <QWidget>
#include <QScreen>



Widget *initialize_mainWindow();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //read the style file and apply it
    QFile styleFile(":/styles/styles/app_style.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        QString style = QString::fromLatin1(styleFile.readAll());
        a.setStyleSheet(style);
        styleFile.close();
    }

    // ----------------------------
    // Starting the application
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
