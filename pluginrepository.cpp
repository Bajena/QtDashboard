#include "pluginrepository.h"

#include <QPluginLoader>

PluginRepository* PluginRepository::instance = NULL;

PluginRepository::PluginRepository()
{

}

void PluginRepository::addPlugin(PluginInterfaceFactory *factory, QString filepath, QString name)
{
    plugins.append(new PluginData(factory, filepath, name));
}

void PluginRepository::loadPlugins(QDir pluginsDirectory)
{
    clearPlugins();
    foreach (QString filename, pluginsDirectory.entryList(QDir::Files)) {
        QString filepath = pluginsDirectory.absoluteFilePath(filename);
        loadPlugin(filepath);
    }
}

void PluginRepository::loadPlugin(QString filepath)
{
    QPluginLoader loader(filepath);
    QObject *plugin = loader.instance();
    if (plugin) {
        PluginInterfaceFactory* instanceFactory = qobject_cast<PluginInterfaceFactory*>(plugin);
        this->addPlugin(instanceFactory, filepath, instanceFactory->pluginName());
    }
}

PluginInterfaceFactory *PluginRepository::findFactoryByPluginName(QString pluginName)
{
    foreach (PluginData *pluginData, PluginRepository::getInstance()->plugins)
    {
        if (pluginData->name == pluginName) return pluginData->pluginFactory;
    }

    return NULL;
}

void PluginRepository::clearPlugins()
{
    foreach (PluginData* pluginData, this->plugins)
    {
        delete pluginData;
    }

    this->plugins.clear();
}
