#ifndef ANALOGCLOCKPLUGIN_H
#define ANALOGCLOCKPLUGIN_H

#include <QObject>
#include <QGraphicsItem>
#include <Dashboard/plugininterface.h>

class AnalogClockPlugin : public PluginInterface
{
    Q_OBJECT
public:
    AnalogClockPlugin();
    ~AnalogClockPlugin();
    virtual void initializeScene(QGraphicsScene *scene) Q_DECL_OVERRIDE;
    virtual void draw(QGraphicsScene *scene) Q_DECL_OVERRIDE;
    virtual int refreshSpeed() Q_DECL_OVERRIDE;

private slots:
    void scaleContents(const QRectF &);

private:
        const qreal BASE_SIZE = 200.0;
        QGraphicsPolygonItem *secondHand;
        QGraphicsPolygonItem *minuteHand;
        QGraphicsPolygonItem *hourHand;
        QGraphicsScene *graphicsScene;

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
