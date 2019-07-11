#-------------------------------------------------
#
# Project created by QtCreator 2019-07-03T16:41:03
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PharmaCOre
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        dashboard.cpp \
        main.cpp \
        login.cpp \
        order.cpp \
        regular.cpp \
        selldetails.cpp \
        stocks.cpp \
        wholesalers.cpp

HEADERS += \
        dashboard.h \
        login.h \
        order.h \
        regular.h \
        selldetails.h \
        stocks.h \
        wholesalers.h

FORMS += \
        dashboard.ui \
        login.ui \
        order.ui \
        regular.ui \
        selldetails.ui \
        stocks.ui \
        wholesalers.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
