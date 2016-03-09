#ifndef ANALOGCLOCKPLUGIN_H
#define ANALOGCLOCKPLUGIN_H

#include <QObject>
#include <QGraphicsItem>
#include <QtDashboard/plugininterface.h>

class AnalogClockPlugin : public PluginInterface
{
public:
    AnalogClockPlugin();
    ~AnalogClockPlugin();
    virtual void initializeScene(QGraphicsScene &scene) Q_DECL_OVERRIDE;
    virtual void draw(QGraphicsScene &scene) Q_DECL_OVERRIDE;
    virtual int refreshSpeed() Q_DECL_OVERRIDE;

private:
        QGraphicsPolygonItem *secondHand;
        QGraphicsPolygonItem *minuteHand;
        QGraphicsPolygonItem *hourHand;

        void rotateHands();
};

class AnalogClockPluginFactory : public QObject, public PluginInterfaceFactory
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "Dashboard.PluginInterfaceFactory" FILE "analogclockplugin.json")
    Q_INTERFACES(PluginInterfaceFactory)
    public:
        virtual PluginInterface* getInstance() Q_DECL_OVERRIDE;
};

#endif // ANALOGCLOCKPLUGIN_H
