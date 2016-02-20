#ifndef PLUGININTERFACE_H
#define PLUGININTERFACE_H

#include <QGraphicsScene>

class PluginInterface
{
public:
    virtual ~PluginInterface() {}
    virtual void draw(QGraphicsScene &scene) = 0;
    virtual int refreshSpeed() = 0;
};

QT_BEGIN_NAMESPACE

#define PluginInterface_iid "Qt.PluginInterface"

Q_DECLARE_INTERFACE(PluginInterface, PluginInterface_iid)
QT_END_NAMESPACE

#endif // PLUGININTERFACE_H
