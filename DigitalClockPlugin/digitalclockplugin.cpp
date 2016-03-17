#include "digitalclockplugin.h"

#include <QDebug>
#include <QTime>


DigitalClockPlugin::DigitalClockPlugin()
{

}

DigitalClockPlugin::~DigitalClockPlugin()
{
    delete this->timeItem;

    foreach (QAction *action, this->contextMenuActions())
    {
        delete action;
    }
}

void DigitalClockPlugin::initializeScene(QGraphicsScene *scene)
{
    this->timeItem = scene->addText(buildTimeString());
    connect(scene, SIGNAL(sceneRectChanged(const QRectF &)), this, SLOT(scaleContents(const QRectF &)));
}


void DigitalClockPlugin::draw(QGraphicsScene *scene)
{
    this->timeItem->setPlainText(buildTimeString());
}

int DigitalClockPlugin::refreshSpeed()
{
    return 1000;
}

QList<QAction *> DigitalClockPlugin::contextMenuActions()
{
    return this->menuActions;
}

QString DigitalClockPlugin::buildTimeString()
{
    QTime time = QTime::currentTime();
    QString timeString = "";
    return timeString.sprintf("%02d:%02d:%02d", time.hour(), time.minute(), time.second());
}

void DigitalClockPlugin::scaleContents(const QRectF &rect)
{
    qDebug() << "scaleContents:" << rect;
//    qreal minDimension = rect.width() < rect.height() ? rect.width() : rect.height();
//    qDebug() << "minDimension: " << minDimension;
//    qDebug() << "scale: " << minDimension / BASE_SIZE;

//    foreach (QGraphicsItem *item, this->graphicsScene->items())
//    {
//        item->setScale(minDimension / BASE_SIZE);
//    }
}

QString DigitalClockPluginFactory::pluginName()
{
    return "Digital clock";
}

PluginInterface *DigitalClockPluginFactory::getInstance()
{
    return new DigitalClockPlugin();
}

