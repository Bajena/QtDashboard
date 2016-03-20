#ifndef PLUGINREPOSITORY_H
#define PLUGINREPOSITORY_H

#include "plugindata.h"

#include <QDir>
#include <QList>

class PluginRepository
{
public:
    static PluginRepository *getInstance()
    {
        if (!PluginRepository::instance) PluginRepository::instance = new PluginRepository();

        return PluginRepository::instance;
    }

    PluginRepository();
    QList<PluginData*> plugins;

    void addPlugin(PluginInterfaceFactory *factory, QString filepath = "", QString name = "");
    void loadPlugins(QDir pluginsDirectory);
    void loadPlugin(QString filepath);
    PluginInterfaceFactory *findFactoryByPluginName(QString pluginName);

private:
    static PluginRepository* instance;
    void clearPlugins();
};

#endif // PLUGINREPOSITORY_H
