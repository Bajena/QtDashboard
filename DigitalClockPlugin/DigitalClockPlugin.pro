#-------------------------------------------------
#
# Project created by QtCreator 2016-03-17T18:51:27
#
#-------------------------------------------------

QT       -= gui
QT       += widgets
INCLUDEPATH  += ../..

TARGET = $$qtLibraryTarget(dashboard_digital_clock_plugin)
TEMPLATE = lib
DESTDIR  = ../plugins

DEFINES += DIGITALCLOCKPLUGIN_LIBRARY

SOURCES += digitalclockplugin.cpp

HEADERS += digitalclockplugin.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
