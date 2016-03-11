#ifndef PLUGININTERFACE_H
#define PLUGININTERFACE_H

#include <QGraphicsScene>
#include <QtPlugin>

class PluginInterface : public QObject
{
    public:
        virtual ~PluginInterface() {}
        virtual void draw(QGraphicsScene *scene) = 0;
        virtual void initializeScene(QGraphicsScene *scene) = 0;
        virtual int refreshSpeed() = 0;
};

class PluginInterfaceFactory
{
    public:
        virtual PluginInterface* getInstance() = 0;
};

QT_BEGIN_NAMESPACE

#define PluginInterfaceFactory_iid "Dashboard.PluginInterfaceFactory"

Q_DECLARE_INTERFACE(PluginInterfaceFactory, PluginInterfaceFactory_iid)
QT_END_NAMESPACE

#endif // PLUGININTERFACE_H
