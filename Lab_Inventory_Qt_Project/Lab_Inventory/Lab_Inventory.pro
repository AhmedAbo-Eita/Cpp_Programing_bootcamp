QT += core gui widgets pdf pdfwidgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    source_files/import_export_handler.cpp \
    source_files/widget.cpp \
    source_files/component.cpp

HEADERS += \
    header_files/import_export_handler.h \
    header_files/widget.h \
    header_files/component.h

FORMS += \
    form_files/widget.ui

RESOURCES += \
    Resources.qrc

DISTFILES += \
    data/My_Inventory.csv

RC_FILE = Lab_Inventory.rc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
