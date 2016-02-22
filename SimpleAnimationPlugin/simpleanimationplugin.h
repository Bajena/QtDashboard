#ifndef SIMPLEANIMATIONPLUGIN_H
#define SIMPLEANIMATIONPLUGIN_H

#include <QObject>
#include <QGraphicsItem>
#include <Dashboard/plugininterface.h>

class SimpleAnimationPlugin : public QObject, public PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "Dashboard.PluginInterface" FILE "simpleanimationplugin.json")
    Q_INTERFACES(PluginInterface)

public:
    SimpleAnimationPlugin();
    virtual void draw(QGraphicsScene &scene) Q_DECL_OVERRIDE;
    virtual int refreshSpeed() Q_DECL_OVERRIDE;

private:
    QGraphicsRectItem *rectangle;
    bool rectAdded;
};

#endif // SIMPLEANIMATIONPLUGIN_H
