#ifndef SIMPLEANIMATIONPLUGIN_H
#define SIMPLEANIMATIONPLUGIN_H

#include <QGraphicsItem>

#include "plugininterface.h"

class SimpleAnimationPlugin : public PluginInterface
{
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
