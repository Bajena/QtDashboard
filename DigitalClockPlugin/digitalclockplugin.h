#ifndef DigitalClockPlugin_H
#define DigitalClockPlugin_H

#include <QObject>
#include <QGraphicsItem>
#include <Dashboard/plugininterface.h>

class DigitalClockPlugin : public PluginInterface
{
    Q_OBJECT
public:
    DigitalClockPlugin();
    ~DigitalClockPlugin();
    virtual void initializeScene(QGraphicsScene *scene) Q_DECL_OVERRIDE;
    virtual void draw(QGraphicsScene *scene) Q_DECL_OVERRIDE;
    virtual int refreshSpeed() Q_DECL_OVERRIDE;
    virtual QList<QAction*> contextMenuActions() Q_DECL_OVERRIDE;

private slots:
    void scaleContents(const QRectF &rect);

private:
    QString buildTimeString();

    QGraphicsScene *graphicsScene;
    QList<QAction*> menuActions;
    QGraphicsTextItem *timeItem;
};

class DigitalClockPluginFactory : public QObject, public PluginInterfaceFactory
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "Dashboard.PluginInterfaceFactory" FILE "DigitalClockPlugin.json")
    Q_INTERFACES(PluginInterfaceFactory)
    public:
        virtual QString pluginName() Q_DECL_OVERRIDE;
        virtual PluginInterface* getInstance() Q_DECL_OVERRIDE;
};

#endif // DigitalClockPlugin_H
