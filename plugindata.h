#ifndef PLUGINDATA_H
#define PLUGINDATA_H

#include <QString>

#include "plugininterface.h"


class PluginData
{
public:
    PluginData(PluginInterfaceFactory *instance, QString filepath = "", QString name = "");
    ~PluginData();
    QString name;
    QString filePath;
    PluginInterfaceFactory *pluginFactory;
};

#endif // PLUGINDATA_H
