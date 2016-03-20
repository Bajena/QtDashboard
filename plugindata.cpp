#include "plugindata.h"

PluginData::PluginData(PluginInterfaceFactory *instance, QString filepath, QString name)
{
    this->pluginFactory = instance;
    this->filePath = filepath;
    this->name = name;
}

PluginData::~PluginData()
{
    if (this->pluginFactory) delete this->pluginFactory;
}
