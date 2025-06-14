/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *appLogoLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *cleanPushButton_2;
    QPushButton *cleanPushButton;
    QPushButton *savePushButton;
    QPushButton *importPushButton;
    QPushButton *exportPushButton;
    QTabWidget *inventoryTabWidget;
    QWidget *inventoryTableTab;
    QVBoxLayout *verticalLayout;
    QGroupBox *inventoryTableGroupBox;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *inventoryTableWidget;
    QHBoxLayout *horizontalLayout_5;
    QTabWidget *tabWidget;
    QWidget *NewComponentTab;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *dataEnteryGroupBox;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QComboBox *typeComboBox;
    QPushButton *footprintPackageExternalButton;
    QLabel *typeLabel;
    QLineEdit *MPNLineEdit;
    QSpinBox *quantitySpinBox;
    QLabel *quantityLabel;
    QLineEdit *locationLineEdit;
    QLabel *MPNLabel;
    QLabel *locationLabel;
    QComboBox *footprintComboBox;
    QLabel *footprintLabel;
    QPushButton *addPushButton;
    QPushButton *clearPushButton;
    QWidget *EditComponentTab;
    QHBoxLayout *horizontalLayout_7;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_8;
    QGridLayout *gridLayout_3;
    QLineEdit *editLocatioLineEdit;
    QComboBox *editTypeComboBox;
    QPushButton *applyEditspushButton;
    QLineEdit *editFootprintLineEdit;
    QLabel *editTypeLabel;
    QLabel *editLocationLabel;
    QLineEdit *editMPNLineEdit;
    QSpinBox *editQuantitySpinBox;
    QLabel *editFootprintLabel;
    QPushButton *editFindpushButton;
    QLabel *editQuantityLabel;
    QLabel *editMPNLabel;
    QPushButton *deleteComponentpushButton;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_2;
    QLabel *foundedFootprintLabel;
    QLabel *foundedTypeLable;
    QLabel *searchFootprintLabel;
    QPushButton *EditComponentPushButton;
    QLabel *searchLocationLabel;
    QLabel *foundedLocationLable;
    QLabel *searchMPNLabel;
    QPushButton *findPushButton;
    QLineEdit *searchMPNLineEdit;
    QLabel *searchTypeLabel;
    QLabel *searchQuantityLabel;
    QLabel *foundedQuantityLabel;
    QLabel *createdbylabel;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1280, 728);
        QFont font;
        font.setFamilies({QString::fromUtf8("Blinker")});
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        Widget->setFont(font);
        Widget->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        Widget->setStyleSheet(QString::fromUtf8("font: 10pt \"Blinker\";"));
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        appLogoLabel = new QLabel(Widget);
        appLogoLabel->setObjectName("appLogoLabel");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(appLogoLabel->sizePolicy().hasHeightForWidth());
        appLogoLabel->setSizePolicy(sizePolicy);
        appLogoLabel->setMaximumSize(QSize(301, 81));
        appLogoLabel->setPixmap(QPixmap(QString::fromUtf8(":/inventoryMainIcons/Images/appLogo.png")));
        appLogoLabel->setScaledContents(true);

        horizontalLayout_4->addWidget(appLogoLabel);

        horizontalSpacer = new QSpacerItem(308, 78, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        cleanPushButton_2 = new QPushButton(Widget);
        cleanPushButton_2->setObjectName("cleanPushButton_2");
        sizePolicy.setHeightForWidth(cleanPushButton_2->sizePolicy().hasHeightForWidth());
        cleanPushButton_2->setSizePolicy(sizePolicy);
        cleanPushButton_2->setMinimumSize(QSize(100, 50));
        cleanPushButton_2->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/inventoryMainIcons/Images/return_10118885.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        cleanPushButton_2->setIcon(icon);
        cleanPushButton_2->setIconSize(QSize(40, 50));

        horizontalLayout_4->addWidget(cleanPushButton_2);

        cleanPushButton = new QPushButton(Widget);
        cleanPushButton->setObjectName("cleanPushButton");
        sizePolicy.setHeightForWidth(cleanPushButton->sizePolicy().hasHeightForWidth());
        cleanPushButton->setSizePolicy(sizePolicy);
        cleanPushButton->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/inventoryMainIcons/Images/clean.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        cleanPushButton->setIcon(icon1);
        cleanPushButton->setIconSize(QSize(50, 50));

        horizontalLayout_4->addWidget(cleanPushButton);

        savePushButton = new QPushButton(Widget);
        savePushButton->setObjectName("savePushButton");
        sizePolicy.setHeightForWidth(savePushButton->sizePolicy().hasHeightForWidth());
        savePushButton->setSizePolicy(sizePolicy);
        savePushButton->setMinimumSize(QSize(125, 0));
        savePushButton->setFont(font);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/inventoryMainIcons/Images/save_9584668.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        savePushButton->setIcon(icon2);
        savePushButton->setIconSize(QSize(40, 50));

        horizontalLayout_4->addWidget(savePushButton);

        importPushButton = new QPushButton(Widget);
        importPushButton->setObjectName("importPushButton");
        sizePolicy.setHeightForWidth(importPushButton->sizePolicy().hasHeightForWidth());
        importPushButton->setSizePolicy(sizePolicy);
        importPushButton->setFont(font);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/inventoryMainIcons/Images/import.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        importPushButton->setIcon(icon3);
        importPushButton->setIconSize(QSize(50, 50));

        horizontalLayout_4->addWidget(importPushButton);

        exportPushButton = new QPushButton(Widget);
        exportPushButton->setObjectName("exportPushButton");
        sizePolicy.setHeightForWidth(exportPushButton->sizePolicy().hasHeightForWidth());
        exportPushButton->setSizePolicy(sizePolicy);
        exportPushButton->setFont(font);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/inventoryMainIcons/Images/Export.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        exportPushButton->setIcon(icon4);
        exportPushButton->setIconSize(QSize(50, 50));

        horizontalLayout_4->addWidget(exportPushButton);


        verticalLayout_2->addLayout(horizontalLayout_4);

        inventoryTabWidget = new QTabWidget(Widget);
        inventoryTabWidget->setObjectName("inventoryTabWidget");
        inventoryTabWidget->setStyleSheet(QString::fromUtf8("font: 12pt \"Blinker\";"));
        inventoryTableTab = new QWidget();
        inventoryTableTab->setObjectName("inventoryTableTab");
        verticalLayout = new QVBoxLayout(inventoryTableTab);
        verticalLayout->setObjectName("verticalLayout");
        inventoryTableGroupBox = new QGroupBox(inventoryTableTab);
        inventoryTableGroupBox->setObjectName("inventoryTableGroupBox");
        inventoryTableGroupBox->setStyleSheet(QString::fromUtf8("font: 12pt \"Blinker\";"));
        horizontalLayout_3 = new QHBoxLayout(inventoryTableGroupBox);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        inventoryTableWidget = new QTableWidget(inventoryTableGroupBox);
        inventoryTableWidget->setObjectName("inventoryTableWidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(inventoryTableWidget->sizePolicy().hasHeightForWidth());
        inventoryTableWidget->setSizePolicy(sizePolicy1);
        inventoryTableWidget->setMinimumSize(QSize(0, 0));
        inventoryTableWidget->setBaseSize(QSize(0, 150));

        horizontalLayout_3->addWidget(inventoryTableWidget);


        verticalLayout->addWidget(inventoryTableGroupBox);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        tabWidget = new QTabWidget(inventoryTableTab);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setStyleSheet(QString::fromUtf8("font: 14pt \"Blinker\";"));
        NewComponentTab = new QWidget();
        NewComponentTab->setObjectName("NewComponentTab");
        horizontalLayout = new QHBoxLayout(NewComponentTab);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        dataEnteryGroupBox = new QGroupBox(NewComponentTab);
        dataEnteryGroupBox->setObjectName("dataEnteryGroupBox");
        verticalLayout_3 = new QVBoxLayout(dataEnteryGroupBox);
        verticalLayout_3->setObjectName("verticalLayout_3");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setContentsMargins(0, -1, 6, 0);
        typeComboBox = new QComboBox(dataEnteryGroupBox);
        typeComboBox->addItem(QString());
        typeComboBox->addItem(QString());
        typeComboBox->addItem(QString());
        typeComboBox->addItem(QString());
        typeComboBox->addItem(QString());
        typeComboBox->addItem(QString());
        typeComboBox->addItem(QString());
        typeComboBox->addItem(QString());
        typeComboBox->setObjectName("typeComboBox");
        typeComboBox->setStyleSheet(QString::fromUtf8("font: 14pt \"Blinker\";"));

        gridLayout->addWidget(typeComboBox, 3, 1, 1, 2);

        footprintPackageExternalButton = new QPushButton(dataEnteryGroupBox);
        footprintPackageExternalButton->setObjectName("footprintPackageExternalButton");
        sizePolicy.setHeightForWidth(footprintPackageExternalButton->sizePolicy().hasHeightForWidth());
        footprintPackageExternalButton->setSizePolicy(sizePolicy);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/inventoryMainIcons/Images/pdf-file_8257805.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        footprintPackageExternalButton->setIcon(icon5);
        footprintPackageExternalButton->setIconSize(QSize(100, 100));

        gridLayout->addWidget(footprintPackageExternalButton, 2, 3, 3, 1);

        typeLabel = new QLabel(dataEnteryGroupBox);
        typeLabel->setObjectName("typeLabel");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Blinker")});
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        typeLabel->setFont(font1);
        typeLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Blinker\";"));

        gridLayout->addWidget(typeLabel, 3, 0, 1, 1);

        MPNLineEdit = new QLineEdit(dataEnteryGroupBox);
        MPNLineEdit->setObjectName("MPNLineEdit");
        MPNLineEdit->setStyleSheet(QString::fromUtf8("font: 14pt \"Blinker\";"));

        gridLayout->addWidget(MPNLineEdit, 0, 1, 1, 3);

        quantitySpinBox = new QSpinBox(dataEnteryGroupBox);
        quantitySpinBox->setObjectName("quantitySpinBox");
        quantitySpinBox->setStyleSheet(QString::fromUtf8("font: 14pt \"Blinker\";"));
        quantitySpinBox->setMaximum(99999);

        gridLayout->addWidget(quantitySpinBox, 2, 1, 1, 2);

        quantityLabel = new QLabel(dataEnteryGroupBox);
        quantityLabel->setObjectName("quantityLabel");
        quantityLabel->setFont(font1);
        quantityLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Blinker\";"));

        gridLayout->addWidget(quantityLabel, 2, 0, 1, 1);

        locationLineEdit = new QLineEdit(dataEnteryGroupBox);
        locationLineEdit->setObjectName("locationLineEdit");
        locationLineEdit->setStyleSheet(QString::fromUtf8("font: 14pt \"Blinker\";"));

        gridLayout->addWidget(locationLineEdit, 1, 1, 1, 3);

        MPNLabel = new QLabel(dataEnteryGroupBox);
        MPNLabel->setObjectName("MPNLabel");
        MPNLabel->setFont(font1);
        MPNLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Blinker\";"));

        gridLayout->addWidget(MPNLabel, 0, 0, 1, 1);

        locationLabel = new QLabel(dataEnteryGroupBox);
        locationLabel->setObjectName("locationLabel");
        locationLabel->setFont(font1);
        locationLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Blinker\";"));

        gridLayout->addWidget(locationLabel, 1, 0, 1, 1);

        footprintComboBox = new QComboBox(dataEnteryGroupBox);
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->addItem(QString());
        footprintComboBox->setObjectName("footprintComboBox");
        footprintComboBox->setEnabled(true);
        footprintComboBox->setStyleSheet(QString::fromUtf8("font: 14pt \"Blinker\";"));

        gridLayout->addWidget(footprintComboBox, 4, 1, 1, 2);

        footprintLabel = new QLabel(dataEnteryGroupBox);
        footprintLabel->setObjectName("footprintLabel");
        footprintLabel->setFont(font1);
        footprintLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Blinker\";"));

        gridLayout->addWidget(footprintLabel, 4, 0, 1, 1);

        addPushButton = new QPushButton(dataEnteryGroupBox);
        addPushButton->setObjectName("addPushButton");
        addPushButton->setStyleSheet(QString::fromUtf8("font: 14pt \"Blinker\";"));
        addPushButton->setAutoDefault(true);

        gridLayout->addWidget(addPushButton, 6, 2, 1, 2);

        clearPushButton = new QPushButton(dataEnteryGroupBox);
        clearPushButton->setObjectName("clearPushButton");
        clearPushButton->setStyleSheet(QString::fromUtf8("font: 14pt \"Blinker\";"));

        gridLayout->addWidget(clearPushButton, 8, 2, 1, 2);


        verticalLayout_3->addLayout(gridLayout);


        horizontalLayout_2->addWidget(dataEnteryGroupBox);


        horizontalLayout->addLayout(horizontalLayout_2);

        tabWidget->addTab(NewComponentTab, QString());
        EditComponentTab = new QWidget();
        EditComponentTab->setObjectName("EditComponentTab");
        horizontalLayout_7 = new QHBoxLayout(EditComponentTab);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        groupBox_2 = new QGroupBox(EditComponentTab);
        groupBox_2->setObjectName("groupBox_2");
        horizontalLayout_8 = new QHBoxLayout(groupBox_2);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        editLocatioLineEdit = new QLineEdit(groupBox_2);
        editLocatioLineEdit->setObjectName("editLocatioLineEdit");

        gridLayout_3->addWidget(editLocatioLineEdit, 4, 1, 1, 1);

        editTypeComboBox = new QComboBox(groupBox_2);
        editTypeComboBox->addItem(QString());
        editTypeComboBox->addItem(QString());
        editTypeComboBox->addItem(QString());
        editTypeComboBox->addItem(QString());
        editTypeComboBox->addItem(QString());
        editTypeComboBox->addItem(QString());
        editTypeComboBox->addItem(QString());
        editTypeComboBox->addItem(QString());
        editTypeComboBox->setObjectName("editTypeComboBox");

        gridLayout_3->addWidget(editTypeComboBox, 6, 1, 1, 1);

        applyEditspushButton = new QPushButton(groupBox_2);
        applyEditspushButton->setObjectName("applyEditspushButton");

        gridLayout_3->addWidget(applyEditspushButton, 7, 1, 1, 1);

        editFootprintLineEdit = new QLineEdit(groupBox_2);
        editFootprintLineEdit->setObjectName("editFootprintLineEdit");

        gridLayout_3->addWidget(editFootprintLineEdit, 5, 1, 1, 1);

        editTypeLabel = new QLabel(groupBox_2);
        editTypeLabel->setObjectName("editTypeLabel");

        gridLayout_3->addWidget(editTypeLabel, 6, 0, 1, 1);

        editLocationLabel = new QLabel(groupBox_2);
        editLocationLabel->setObjectName("editLocationLabel");

        gridLayout_3->addWidget(editLocationLabel, 4, 0, 1, 1);

        editMPNLineEdit = new QLineEdit(groupBox_2);
        editMPNLineEdit->setObjectName("editMPNLineEdit");

        gridLayout_3->addWidget(editMPNLineEdit, 0, 1, 1, 1);

        editQuantitySpinBox = new QSpinBox(groupBox_2);
        editQuantitySpinBox->setObjectName("editQuantitySpinBox");

        gridLayout_3->addWidget(editQuantitySpinBox, 3, 1, 1, 1);

        editFootprintLabel = new QLabel(groupBox_2);
        editFootprintLabel->setObjectName("editFootprintLabel");

        gridLayout_3->addWidget(editFootprintLabel, 5, 0, 1, 1);

        editFindpushButton = new QPushButton(groupBox_2);
        editFindpushButton->setObjectName("editFindpushButton");

        gridLayout_3->addWidget(editFindpushButton, 1, 1, 1, 1);

        editQuantityLabel = new QLabel(groupBox_2);
        editQuantityLabel->setObjectName("editQuantityLabel");

        gridLayout_3->addWidget(editQuantityLabel, 3, 0, 1, 1);

        editMPNLabel = new QLabel(groupBox_2);
        editMPNLabel->setObjectName("editMPNLabel");

        gridLayout_3->addWidget(editMPNLabel, 0, 0, 1, 1);

        deleteComponentpushButton = new QPushButton(groupBox_2);
        deleteComponentpushButton->setObjectName("deleteComponentpushButton");
        deleteComponentpushButton->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 0);"));

        gridLayout_3->addWidget(deleteComponentpushButton, 8, 1, 1, 1);


        horizontalLayout_8->addLayout(gridLayout_3);


        horizontalLayout_7->addWidget(groupBox_2);

        tabWidget->addTab(EditComponentTab, QString());

        horizontalLayout_5->addWidget(tabWidget);

        groupBox = new QGroupBox(inventoryTableTab);
        groupBox->setObjectName("groupBox");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName("verticalLayout_4");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        foundedFootprintLabel = new QLabel(groupBox);
        foundedFootprintLabel->setObjectName("foundedFootprintLabel");
        foundedFootprintLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);"));
        foundedFootprintLabel->setMargin(9);

        gridLayout_2->addWidget(foundedFootprintLabel, 5, 1, 1, 1);

        foundedTypeLable = new QLabel(groupBox);
        foundedTypeLable->setObjectName("foundedTypeLable");
        foundedTypeLable->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);"));
        foundedTypeLable->setMargin(9);

        gridLayout_2->addWidget(foundedTypeLable, 6, 1, 1, 1);

        searchFootprintLabel = new QLabel(groupBox);
        searchFootprintLabel->setObjectName("searchFootprintLabel");
        searchFootprintLabel->setFont(font1);
        searchFootprintLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Blinker\";"));

        gridLayout_2->addWidget(searchFootprintLabel, 5, 0, 1, 1);

        EditComponentPushButton = new QPushButton(groupBox);
        EditComponentPushButton->setObjectName("EditComponentPushButton");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(EditComponentPushButton->sizePolicy().hasHeightForWidth());
        EditComponentPushButton->setSizePolicy(sizePolicy3);
        EditComponentPushButton->setMinimumSize(QSize(0, 35));
        EditComponentPushButton->setFont(font1);
        EditComponentPushButton->setStyleSheet(QString::fromUtf8("font: 14pt \"Blinker\";"));

        gridLayout_2->addWidget(EditComponentPushButton, 7, 1, 1, 1);

        searchLocationLabel = new QLabel(groupBox);
        searchLocationLabel->setObjectName("searchLocationLabel");
        searchLocationLabel->setFont(font1);
        searchLocationLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Blinker\";"));

        gridLayout_2->addWidget(searchLocationLabel, 3, 0, 1, 1);

        foundedLocationLable = new QLabel(groupBox);
        foundedLocationLable->setObjectName("foundedLocationLable");
        foundedLocationLable->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);"));
        foundedLocationLable->setMargin(9);

        gridLayout_2->addWidget(foundedLocationLable, 3, 1, 1, 1);

        searchMPNLabel = new QLabel(groupBox);
        searchMPNLabel->setObjectName("searchMPNLabel");
        searchMPNLabel->setFont(font1);
        searchMPNLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Blinker\";"));

        gridLayout_2->addWidget(searchMPNLabel, 0, 0, 1, 1);

        findPushButton = new QPushButton(groupBox);
        findPushButton->setObjectName("findPushButton");
        findPushButton->setStyleSheet(QString::fromUtf8("font: 14pt \"Blinker\";"));
        findPushButton->setAutoDefault(true);

        gridLayout_2->addWidget(findPushButton, 1, 1, 1, 1);

        searchMPNLineEdit = new QLineEdit(groupBox);
        searchMPNLineEdit->setObjectName("searchMPNLineEdit");
        searchMPNLineEdit->setStyleSheet(QString::fromUtf8("font: 14pt \"Blinker\";"));

        gridLayout_2->addWidget(searchMPNLineEdit, 0, 1, 1, 1);

        searchTypeLabel = new QLabel(groupBox);
        searchTypeLabel->setObjectName("searchTypeLabel");
        searchTypeLabel->setFont(font1);
        searchTypeLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Blinker\";"));

        gridLayout_2->addWidget(searchTypeLabel, 6, 0, 1, 1);

        searchQuantityLabel = new QLabel(groupBox);
        searchQuantityLabel->setObjectName("searchQuantityLabel");
        searchQuantityLabel->setFont(font1);
        searchQuantityLabel->setStyleSheet(QString::fromUtf8("font: 14pt \"Blinker\";"));

        gridLayout_2->addWidget(searchQuantityLabel, 2, 0, 1, 1);

        foundedQuantityLabel = new QLabel(groupBox);
        foundedQuantityLabel->setObjectName("foundedQuantityLabel");
        foundedQuantityLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);"));
        foundedQuantityLabel->setMargin(9);

        gridLayout_2->addWidget(foundedQuantityLabel, 2, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout_2);


        horizontalLayout_5->addWidget(groupBox);


        verticalLayout->addLayout(horizontalLayout_5);

        inventoryTabWidget->addTab(inventoryTableTab, QString());

        verticalLayout_2->addWidget(inventoryTabWidget);

        createdbylabel = new QLabel(Widget);
        createdbylabel->setObjectName("createdbylabel");

        verticalLayout_2->addWidget(createdbylabel);


        retranslateUi(Widget);

        inventoryTabWidget->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);
        addPushButton->setDefault(true);
        findPushButton->setDefault(true);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Lab Inventory", nullptr));
        appLogoLabel->setText(QString());
        cleanPushButton_2->setText(QCoreApplication::translate("Widget", "   Reset", nullptr));
        cleanPushButton->setText(QCoreApplication::translate("Widget", "Clean Table  ", nullptr));
        savePushButton->setText(QCoreApplication::translate("Widget", " Import CSV", nullptr));
        importPushButton->setText(QCoreApplication::translate("Widget", "Import CSV  ", nullptr));
        exportPushButton->setText(QCoreApplication::translate("Widget", "Export CSV  ", nullptr));
        inventoryTableGroupBox->setTitle(QCoreApplication::translate("Widget", "Inventory Table", nullptr));
        dataEnteryGroupBox->setTitle(QCoreApplication::translate("Widget", "Data Entery", nullptr));
        typeComboBox->setItemText(0, QCoreApplication::translate("Widget", "IC", nullptr));
        typeComboBox->setItemText(1, QCoreApplication::translate("Widget", "MOSFET", nullptr));
        typeComboBox->setItemText(2, QCoreApplication::translate("Widget", "Transistor", nullptr));
        typeComboBox->setItemText(3, QCoreApplication::translate("Widget", "Connector", nullptr));
        typeComboBox->setItemText(4, QCoreApplication::translate("Widget", "Resistor ", nullptr));
        typeComboBox->setItemText(5, QCoreApplication::translate("Widget", "Capacitor", nullptr));
        typeComboBox->setItemText(6, QCoreApplication::translate("Widget", "Inductor", nullptr));
        typeComboBox->setItemText(7, QCoreApplication::translate("Widget", "Diode", nullptr));

        footprintPackageExternalButton->setText(QString());
        typeLabel->setText(QCoreApplication::translate("Widget", "Component Type:", nullptr));
#if QT_CONFIG(accessibility)
        MPNLineEdit->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        MPNLineEdit->setPlaceholderText(QCoreApplication::translate("Widget", "Enter the component's MPN", nullptr));
        quantityLabel->setText(QCoreApplication::translate("Widget", "Quantity:", nullptr));
        locationLineEdit->setPlaceholderText(QCoreApplication::translate("Widget", "Enter the component's location", nullptr));
        MPNLabel->setText(QCoreApplication::translate("Widget", "Manufacturer part number:", nullptr));
        locationLabel->setText(QCoreApplication::translate("Widget", "Location of component in Lab:", nullptr));
        footprintComboBox->setItemText(0, QCoreApplication::translate("Widget", "SOT-8", nullptr));
        footprintComboBox->setItemText(1, QCoreApplication::translate("Widget", "TSSOP-8", nullptr));
        footprintComboBox->setItemText(2, QCoreApplication::translate("Widget", "0201", nullptr));
        footprintComboBox->setItemText(3, QCoreApplication::translate("Widget", "0201-A", nullptr));
        footprintComboBox->setItemText(4, QCoreApplication::translate("Widget", "CSP0201", nullptr));
        footprintComboBox->setItemText(5, QCoreApplication::translate("Widget", "CSP1006-2", nullptr));
        footprintComboBox->setItemText(6, QCoreApplication::translate("Widget", "DFN1006-2", nullptr));
        footprintComboBox->setItemText(7, QCoreApplication::translate("Widget", "DFN1006-2L", nullptr));
        footprintComboBox->setItemText(8, QCoreApplication::translate("Widget", "DFN1006-3", nullptr));
        footprintComboBox->setItemText(9, QCoreApplication::translate("Widget", "DFN1308-5", nullptr));
        footprintComboBox->setItemText(10, QCoreApplication::translate("Widget", "DFN1510-6", nullptr));
        footprintComboBox->setItemText(11, QCoreApplication::translate("Widget", "DFN1608-2", nullptr));
        footprintComboBox->setItemText(12, QCoreApplication::translate("Widget", "DFN1610-2", nullptr));
        footprintComboBox->setItemText(13, QCoreApplication::translate("Widget", "DFN1610-6", nullptr));
        footprintComboBox->setItemText(14, QCoreApplication::translate("Widget", "DFN1616-6", nullptr));
        footprintComboBox->setItemText(15, QCoreApplication::translate("Widget", "DFN1616-6L", nullptr));
        footprintComboBox->setItemText(16, QCoreApplication::translate("Widget", "DFN2020-3A", nullptr));
        footprintComboBox->setItemText(17, QCoreApplication::translate("Widget", "DFN2020-3L", nullptr));
        footprintComboBox->setItemText(18, QCoreApplication::translate("Widget", "DFN2020-6J", nullptr));
        footprintComboBox->setItemText(19, QCoreApplication::translate("Widget", "DFN2020-6JA", nullptr));
        footprintComboBox->setItemText(20, QCoreApplication::translate("Widget", "DFN2020-6L", nullptr));
        footprintComboBox->setItemText(21, QCoreApplication::translate("Widget", "DFN2020-6LE", nullptr));
        footprintComboBox->setItemText(22, QCoreApplication::translate("Widget", "DFN-10", nullptr));
        footprintComboBox->setItemText(23, QCoreApplication::translate("Widget", "DFN2626-10", nullptr));
        footprintComboBox->setItemText(24, QCoreApplication::translate("Widget", "DFN3333", nullptr));
        footprintComboBox->setItemText(25, QCoreApplication::translate("Widget", "DFN3333-8", nullptr));
        footprintComboBox->setItemText(26, QCoreApplication::translate("Widget", "DFN3333-D", nullptr));
        footprintComboBox->setItemText(27, QCoreApplication::translate("Widget", "DFN4120-10", nullptr));
        footprintComboBox->setItemText(28, QCoreApplication::translate("Widget", "DFN5060", nullptr));
        footprintComboBox->setItemText(29, QCoreApplication::translate("Widget", "DFN5060-8D", nullptr));
        footprintComboBox->setItemText(30, QCoreApplication::translate("Widget", "DFN8080A", nullptr));
        footprintComboBox->setItemText(31, QCoreApplication::translate("Widget", "D2-PAK", nullptr));
        footprintComboBox->setItemText(32, QCoreApplication::translate("Widget", "DPAK", nullptr));
        footprintComboBox->setItemText(33, QCoreApplication::translate("Widget", "DO-218AB", nullptr));
        footprintComboBox->setItemText(34, QCoreApplication::translate("Widget", "DO-221AC", nullptr));
        footprintComboBox->setItemText(35, QCoreApplication::translate("Widget", "SMA", nullptr));
        footprintComboBox->setItemText(36, QCoreApplication::translate("Widget", "SMB", nullptr));
        footprintComboBox->setItemText(37, QCoreApplication::translate("Widget", "SMBF", nullptr));
        footprintComboBox->setItemText(38, QCoreApplication::translate("Widget", "SMC", nullptr));
        footprintComboBox->setItemText(39, QCoreApplication::translate("Widget", "SME", nullptr));
        footprintComboBox->setItemText(40, QCoreApplication::translate("Widget", "SMG", nullptr));
        footprintComboBox->setItemText(41, QCoreApplication::translate("Widget", "SOD-123", nullptr));
        footprintComboBox->setItemText(42, QCoreApplication::translate("Widget", "SOD-123FL", nullptr));
        footprintComboBox->setItemText(43, QCoreApplication::translate("Widget", "SOD-123HE1", nullptr));
        footprintComboBox->setItemText(44, QCoreApplication::translate("Widget", "SOD-123TFL", nullptr));
        footprintComboBox->setItemText(45, QCoreApplication::translate("Widget", "SOD-323", nullptr));
        footprintComboBox->setItemText(46, QCoreApplication::translate("Widget", "SOD-323FL", nullptr));
        footprintComboBox->setItemText(47, QCoreApplication::translate("Widget", "SOD-323HE", nullptr));
        footprintComboBox->setItemText(48, QCoreApplication::translate("Widget", "SOD-323HL", nullptr));
        footprintComboBox->setItemText(49, QCoreApplication::translate("Widget", "SOD-523", nullptr));
        footprintComboBox->setItemText(50, QCoreApplication::translate("Widget", "SOD-923", nullptr));
        footprintComboBox->setItemText(51, QCoreApplication::translate("Widget", "SOP-8", nullptr));
        footprintComboBox->setItemText(52, QCoreApplication::translate("Widget", "SOT-143", nullptr));
        footprintComboBox->setItemText(53, QCoreApplication::translate("Widget", "SOT-223", nullptr));
        footprintComboBox->setItemText(54, QCoreApplication::translate("Widget", "SOT-23", nullptr));
        footprintComboBox->setItemText(55, QCoreApplication::translate("Widget", "SOT-23-3L", nullptr));
        footprintComboBox->setItemText(56, QCoreApplication::translate("Widget", "SOT23-6L", nullptr));
        footprintComboBox->setItemText(57, QCoreApplication::translate("Widget", "SOT-323", nullptr));
        footprintComboBox->setItemText(58, QCoreApplication::translate("Widget", "SOT-363", nullptr));
        footprintComboBox->setItemText(59, QCoreApplication::translate("Widget", "SOT-523", nullptr));
        footprintComboBox->setItemText(60, QCoreApplication::translate("Widget", "SOT-563", nullptr));
        footprintComboBox->setItemText(61, QCoreApplication::translate("Widget", "SOT-723", nullptr));
        footprintComboBox->setItemText(62, QCoreApplication::translate("Widget", "SOT-89", nullptr));
        footprintComboBox->setItemText(63, QCoreApplication::translate("Widget", "TO-277", nullptr));
        footprintComboBox->setItemText(64, QCoreApplication::translate("Widget", "SDB-1", nullptr));
        footprintComboBox->setItemText(65, QCoreApplication::translate("Widget", "DB-1", nullptr));
        footprintComboBox->setItemText(66, QCoreApplication::translate("Widget", "DBL-1", nullptr));
        footprintComboBox->setItemText(67, QCoreApplication::translate("Widget", "SDBL-1", nullptr));
        footprintComboBox->setItemText(68, QCoreApplication::translate("Widget", "LMBS-1", nullptr));
        footprintComboBox->setItemText(69, QCoreApplication::translate("Widget", "MBLS-1", nullptr));
        footprintComboBox->setItemText(70, QCoreApplication::translate("Widget", "MBS-1", nullptr));
        footprintComboBox->setItemText(71, QCoreApplication::translate("Widget", "TBL", nullptr));
        footprintComboBox->setItemText(72, QCoreApplication::translate("Widget", "TBS", nullptr));
        footprintComboBox->setItemText(73, QCoreApplication::translate("Widget", "TBN", nullptr));
        footprintComboBox->setItemText(74, QCoreApplication::translate("Widget", "TOLL-8L", nullptr));
        footprintComboBox->setItemText(75, QCoreApplication::translate("Widget", "D3K", nullptr));
        footprintComboBox->setItemText(76, QCoreApplication::translate("Widget", "JA", nullptr));
        footprintComboBox->setItemText(77, QCoreApplication::translate("Widget", "JB", nullptr));
        footprintComboBox->setItemText(78, QCoreApplication::translate("Widget", "GBJ", nullptr));
        footprintComboBox->setItemText(79, QCoreApplication::translate("Widget", "GBL", nullptr));
        footprintComboBox->setItemText(80, QCoreApplication::translate("Widget", "GBP", nullptr));
        footprintComboBox->setItemText(81, QCoreApplication::translate("Widget", "KBJ", nullptr));
        footprintComboBox->setItemText(82, QCoreApplication::translate("Widget", "GBU", nullptr));
        footprintComboBox->setItemText(83, QCoreApplication::translate("Widget", "TSB-5", nullptr));
        footprintComboBox->setItemText(84, QCoreApplication::translate("Widget", "PB-6", nullptr));
        footprintComboBox->setItemText(85, QCoreApplication::translate("Widget", "PB-10", nullptr));
        footprintComboBox->setItemText(86, QCoreApplication::translate("Widget", "PB", nullptr));
        footprintComboBox->setItemText(87, QCoreApplication::translate("Widget", "GBPC", nullptr));
        footprintComboBox->setItemText(88, QCoreApplication::translate("Widget", "GBPC-H", nullptr));
        footprintComboBox->setItemText(89, QCoreApplication::translate("Widget", "GBPC-W", nullptr));
        footprintComboBox->setItemText(90, QCoreApplication::translate("Widget", "MT-35A", nullptr));
        footprintComboBox->setItemText(91, QCoreApplication::translate("Widget", "MB-35", nullptr));
        footprintComboBox->setItemText(92, QCoreApplication::translate("Widget", "MB-35W", nullptr));
        footprintComboBox->setItemText(93, QCoreApplication::translate("Widget", "MP-50", nullptr));
        footprintComboBox->setItemText(94, QCoreApplication::translate("Widget", "MP-50W", nullptr));
        footprintComboBox->setItemText(95, QCoreApplication::translate("Widget", "AK", nullptr));
        footprintComboBox->setItemText(96, QCoreApplication::translate("Widget", "TO-220", nullptr));
        footprintComboBox->setItemText(97, QCoreApplication::translate("Widget", "TO-220 TO-220AB", nullptr));
        footprintComboBox->setItemText(98, QCoreApplication::translate("Widget", "TO-220AB(H)", nullptr));
        footprintComboBox->setItemText(99, QCoreApplication::translate("Widget", "TO-220AC", nullptr));
        footprintComboBox->setItemText(100, QCoreApplication::translate("Widget", "TO-220F", nullptr));
        footprintComboBox->setItemText(101, QCoreApplication::translate("Widget", "ITO-220AB", nullptr));
        footprintComboBox->setItemText(102, QCoreApplication::translate("Widget", "ITO-220AC", nullptr));
        footprintComboBox->setItemText(103, QCoreApplication::translate("Widget", "TO-247", nullptr));
        footprintComboBox->setItemText(104, QCoreApplication::translate("Widget", "TO-247-2L", nullptr));
        footprintComboBox->setItemText(105, QCoreApplication::translate("Widget", "TO-247AD", nullptr));
        footprintComboBox->setItemText(106, QCoreApplication::translate("Widget", "TO-247AB", nullptr));
        footprintComboBox->setItemText(107, QCoreApplication::translate("Widget", "TO-247-4", nullptr));
        footprintComboBox->setItemText(108, QCoreApplication::translate("Widget", "TO-262L", nullptr));
        footprintComboBox->setItemText(109, QCoreApplication::translate("Widget", "TSSOP-8", nullptr));
        footprintComboBox->setItemText(110, QCoreApplication::translate("Widget", "A-405", nullptr));
        footprintComboBox->setItemText(111, QCoreApplication::translate("Widget", "DO-15", nullptr));
        footprintComboBox->setItemText(112, QCoreApplication::translate("Widget", "DO-201AD", nullptr));
        footprintComboBox->setItemText(113, QCoreApplication::translate("Widget", "DO-201AE", nullptr));
        footprintComboBox->setItemText(114, QCoreApplication::translate("Widget", "DO-41", nullptr));
        footprintComboBox->setItemText(115, QCoreApplication::translate("Widget", "R-3", nullptr));
        footprintComboBox->setItemText(116, QCoreApplication::translate("Widget", "R-6", nullptr));
        footprintComboBox->setItemText(117, QCoreApplication::translate("Widget", "RS-4L", nullptr));
        footprintComboBox->setItemText(118, QCoreApplication::translate("Widget", "RS-6", nullptr));
        footprintComboBox->setItemText(119, QCoreApplication::translate("Widget", "C2", nullptr));
        footprintComboBox->setItemText(120, QCoreApplication::translate("Widget", "D1", nullptr));
        footprintComboBox->setItemText(121, QCoreApplication::translate("Widget", "D2", nullptr));
        footprintComboBox->setItemText(122, QCoreApplication::translate("Widget", "1206", nullptr));
        footprintComboBox->setItemText(123, QCoreApplication::translate("Widget", "0603", nullptr));
        footprintComboBox->setItemText(124, QCoreApplication::translate("Widget", "0805", nullptr));

        footprintLabel->setText(QCoreApplication::translate("Widget", "Component Footprint:", nullptr));
        addPushButton->setText(QCoreApplication::translate("Widget", "Add Component", nullptr));
        clearPushButton->setText(QCoreApplication::translate("Widget", "Clear All", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(NewComponentTab), QCoreApplication::translate("Widget", "Add New Component", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "Edit Component", nullptr));
        editTypeComboBox->setItemText(0, QCoreApplication::translate("Widget", "IC", nullptr));
        editTypeComboBox->setItemText(1, QCoreApplication::translate("Widget", "MOSFET", nullptr));
        editTypeComboBox->setItemText(2, QCoreApplication::translate("Widget", "Transistor", nullptr));
        editTypeComboBox->setItemText(3, QCoreApplication::translate("Widget", "Connector", nullptr));
        editTypeComboBox->setItemText(4, QCoreApplication::translate("Widget", "Resistor", nullptr));
        editTypeComboBox->setItemText(5, QCoreApplication::translate("Widget", "Capacitor", nullptr));
        editTypeComboBox->setItemText(6, QCoreApplication::translate("Widget", "Inductor", nullptr));
        editTypeComboBox->setItemText(7, QCoreApplication::translate("Widget", "Diode", nullptr));

        applyEditspushButton->setText(QCoreApplication::translate("Widget", "Apply Edits", nullptr));
        editTypeLabel->setText(QCoreApplication::translate("Widget", "Component Type", nullptr));
        editLocationLabel->setText(QCoreApplication::translate("Widget", "Location of Component in Lab:", nullptr));
        editMPNLineEdit->setText(QString());
        editMPNLineEdit->setPlaceholderText(QCoreApplication::translate("Widget", "Enter the Component's MPN", nullptr));
        editFootprintLabel->setText(QCoreApplication::translate("Widget", "Component Footprint", nullptr));
        editFindpushButton->setText(QCoreApplication::translate("Widget", "Find Component to Edit", nullptr));
        editQuantityLabel->setText(QCoreApplication::translate("Widget", "Quantity:", nullptr));
        editMPNLabel->setText(QCoreApplication::translate("Widget", "Manufacturer part number:", nullptr));
        deleteComponentpushButton->setText(QCoreApplication::translate("Widget", "Delete Component", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(EditComponentTab), QCoreApplication::translate("Widget", "Edit Component", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget", "Search Component", nullptr));
        foundedFootprintLabel->setText(QString());
        foundedTypeLable->setText(QString());
        searchFootprintLabel->setText(QCoreApplication::translate("Widget", "Component Footprint:", nullptr));
        EditComponentPushButton->setText(QCoreApplication::translate("Widget", "Edit Component", nullptr));
        searchLocationLabel->setText(QCoreApplication::translate("Widget", "Location of component in Lab:", nullptr));
        foundedLocationLable->setText(QString());
        searchMPNLabel->setText(QCoreApplication::translate("Widget", "Manufacturer part number:", nullptr));
        findPushButton->setText(QCoreApplication::translate("Widget", "FInd Component", nullptr));
#if QT_CONFIG(accessibility)
        searchMPNLineEdit->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        searchMPNLineEdit->setPlaceholderText(QCoreApplication::translate("Widget", "Enter the component's MPN", nullptr));
        searchTypeLabel->setText(QCoreApplication::translate("Widget", "Component Type:", nullptr));
        searchQuantityLabel->setText(QCoreApplication::translate("Widget", "Quantity:", nullptr));
        foundedQuantityLabel->setText(QString());
        inventoryTabWidget->setTabText(inventoryTabWidget->indexOf(inventoryTableTab), QCoreApplication::translate("Widget", "Inventory Table", nullptr));
        createdbylabel->setText(QCoreApplication::translate("Widget", "This Application Created By: Ahmed Aboeita", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
