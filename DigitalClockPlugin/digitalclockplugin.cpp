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
    this->timeItem = scene->addText(buildTimeString(), QFont("Calibri", 72));
    QRectF rect = this->timeItem->boundingRect();
    this->timeItem->setPos(-rect.width() / 2, -rect.height() / 2);
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
}

QString DigitalClockPluginFactory::pluginName()
{
    return "Digital clock";
}

PluginInterface *DigitalClockPluginFactory::getInstance()
{
    return new DigitalClockPlugin();
}

