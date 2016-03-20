#-------------------------------------------------
#
# Project created by QtCreator 2016-03-20T16:42:45
#
#-------------------------------------------------

QT       -= gui
QT       += widgets
INCLUDEPATH  += ../..

TARGET = $$qtLibraryTarget(dashboard_line_chart_plugin)
TEMPLATE = lib
DESTDIR  = ../plugins

DEFINES += LINECHARTPLUGIN_LIBRARY

SOURCES += linechartplugin.cpp \
    chartgraphicsitem.cpp

HEADERS += linechartplugin.h \
    chartgraphicsitem.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
