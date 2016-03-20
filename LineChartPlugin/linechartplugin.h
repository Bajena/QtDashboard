#ifndef LineChartPlugin_H
#define LineChartPlugin_H

#include "chartgraphicsitem.h"

#include <QObject>
#include <QGraphicsItem>
#include <Dashboard/plugininterface.h>

class LineChartPlugin : public PluginInterface
{
    Q_OBJECT
public:
    LineChartPlugin();
    ~LineChartPlugin();
    virtual void initializeScene(QGraphicsScene *scene) Q_DECL_OVERRIDE;
    virtual void draw(QGraphicsScene *scene) Q_DECL_OVERRIDE;
    virtual int refreshSpeed() Q_DECL_OVERRIDE;
    virtual QList<QAction*> contextMenuActions() Q_DECL_OVERRIDE;

private slots:
    void scaleContents(const QRectF &rect);

private:
    ChartGraphicsItem *chartItem;
    QGraphicsScene *graphicsScene;
    QList<QAction*> menuActions;
};

class LineChartPluginFactory : public QObject, public PluginInterfaceFactory
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "Dashboard.PluginInterfaceFactory" FILE "LineChartPlugin.json")
    Q_INTERFACES(PluginInterfaceFactory)
    public:
        virtual QString pluginName() Q_DECL_OVERRIDE;
        virtual PluginInterface* getInstance() Q_DECL_OVERRIDE;
};

#endif // LineChartPlugin_H
