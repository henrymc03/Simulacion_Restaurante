QT       += \
            core gui \
            charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chef.cpp \
    chefitem.cpp \
    customer.cpp \
    customeritem.cpp \
    file.cpp \
    food.cpp \
    globalvalue.cpp \
    graphicsdialog.cpp \
    janitor.cpp \
    janitoritem.cpp \
    logdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    scenerestaurant.cpp \
    simulationdialog.cpp \
    table.cpp \
    tableitem.cpp \
    waiter.cpp \
    waiteritem.cpp

HEADERS += \
    chef.h \
    chefitem.h \
    customer.h \
    customeritem.h \
    file.h \
    food.h \
    globalvalue.h \
    graphicsdialog.h \
    janitor.h \
    janitoritem.h \
    logdialog.h \
    mainwindow.h \
    scenerestaurant.h \
    simulationdialog.h \
    table.h \
    tableitem.h \
    waiter.h \
    waiteritem.h

FORMS += \
    graphicsdialog.ui \
    logdialog.ui \
    mainwindow.ui \
    simulationdialog.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
