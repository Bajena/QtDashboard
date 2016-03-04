#include "pluginrepository.h"

PluginRepository* PluginRepository::instance = NULL;

PluginRepository::PluginRepository()
{

}

void PluginRepository::addPlugin(PluginInterfaceFactory *factory, QString filepath, QString name)
{
    plugins.append(new PluginData(factory, filepath, name));
}

PluginInterfaceFactory *PluginRepository::findFactoryByPluginName(QString pluginName)
{
    foreach (PluginData *pluginData, PluginRepository::getInstance()->plugins)
    {
        if (pluginData->name == pluginName) return pluginData->pluginFactory;
    }

    return NULL;
}
