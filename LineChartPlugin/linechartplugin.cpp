#include <QDebug>
#include <QGraphicsView>
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
    this->chartItem->fetchNewValue();

    connect(scene, SIGNAL(sceneRectChanged(const QRectF &)), this, SLOT(scaleContents(const QRectF &)));
}

void LineChartPlugin::draw(QGraphicsScene *scene)
{
    this->chartItem->fetchNewValue();
    scene->views().first()->viewport()->update();
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
    QRectF sceneRectHalf(rect.x() + 1, rect.y() + 1, rect.width() - 1, rect.height() - 1);
    this->chartItem->setRect(sceneRectHalf);
}

QString LineChartPluginFactory::pluginName()
{
    return "Line chart";
}

PluginInterface *LineChartPluginFactory::getInstance()
{
    return new LineChartPlugin();
}

