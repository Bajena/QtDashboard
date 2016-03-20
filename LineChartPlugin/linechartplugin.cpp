#include <QDebug>
#include <QTime>

#include "chartgraphicsitem.h"
#include "linechartplugin.h"

LineChartPlugin::LineChartPlugin()
{
}

LineChartPlugin::~LineChartPlugin()
{
    delete this->chartItem;
    foreach (QAction *action, this->contextMenuActions())
    {
        delete action;
    }
}

void LineChartPlugin::initializeScene(QGraphicsScene *scene)
{
    this->chartItem = new ChartGraphicsItem(0, 0, 100, 100);
    scene->addItem(chartItem);
    QRectF sceneRect = scene->sceneRect();
    this->chartItem->setRect(sceneRect);

    connect(scene, SIGNAL(sceneRectChanged(const QRectF &)), this, SLOT(scaleContents(const QRectF &)));
}

void LineChartPlugin::draw(QGraphicsScene *scene)
{
}

int LineChartPlugin::refreshSpeed()
{
    return 1000;
}

QList<QAction *> LineChartPlugin::contextMenuActions()
{
    return this->menuActions;
}

void LineChartPlugin::scaleContents(const QRectF &rect)
{

}

QString LineChartPluginFactory::pluginName()
{
    return "Line chart";
}

PluginInterface *LineChartPluginFactory::getInstance()
{
    return new LineChartPlugin();
}

