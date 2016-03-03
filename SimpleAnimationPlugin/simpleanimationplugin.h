#ifndef SIMPLEANIMATIONPLUGIN_H
#define SIMPLEANIMATIONPLUGIN_H

#include <QObject>
#include <QGraphicsItem>
#include <Dashboard/plugininterface.h>

class SimpleAnimationPlugin : public PluginInterface
{
public:
    SimpleAnimationPlugin();
    virtual void draw(QGraphicsScene &scene) Q_DECL_OVERRIDE;
    virtual int refreshSpeed() Q_DECL_OVERRIDE;

private:
    QGraphicsRectItem *rectangle;
    bool rectAdded;
};

class SimpleAnimationPluginFactory : public QObject, public PluginInterfaceFactory
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "Dashboard.PluginInterfaceFactory" FILE "simpleanimationplugin.json")
    Q_INTERFACES(PluginInterfaceFactory)
    public:
        virtual PluginInterface* getInstance() Q_DECL_OVERRIDE;
};

#endif // SIMPLEANIMATIONPLUGIN_H
