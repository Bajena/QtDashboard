#-------------------------------------------------
#
# Project created by QtCreator 2016-02-15T19:19:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Dashboard
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    Widgets/dashboardwidget.cpp \
    Widgets/dashboardpluginbase.cpp

HEADERS  += mainwindow.h \
    Widgets/dashboardwidget.h \
    Widgets/dashboardpluginbase.h

FORMS    += mainwindow.ui \
    Widgets/dashboardwidget.ui \
    Widgets/dashboardpluginbase.ui
