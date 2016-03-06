#-------------------------------------------------
#
# Project created by QtCreator 2016-03-06T15:39:19
#
#-------------------------------------------------

QT       -= gui
QT       += widgets
INCLUDEPATH  += ../..

TARGET = $$qtLibraryTarget(dashboard_analog_clock_plugin)
TEMPLATE = lib
DESTDIR  = ../plugins

DEFINES += ANALOGCLOCKPLUGIN_LIBRARY

SOURCES += analogclockplugin.cpp

HEADERS += analogclockplugin.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
