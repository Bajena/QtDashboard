#-------------------------------------------------
#
# Project created by QtCreator 2016-02-22T23:02:09
#
#-------------------------------------------------

QT       -= gui
QT       += widgets
INCLUDEPATH  += ../..

TARGET = $$qtLibraryTarget(dashboard_simple_animation_plugin)
TEMPLATE = lib
DESTDIR  = ../plugins

DEFINES += SIMPLEANIMATIONPLUGIN_LIBRARY

SOURCES += simpleanimationplugin.cpp

HEADERS += simpleanimationplugin.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
