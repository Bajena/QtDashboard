#include "analogclockplugin.h"


AnalogClockPlugin::AnalogClockPlugin()
{
}

AnalogClockPlugin::~AnalogClockPlugin()
{
//    delete minuteHand;
//    delete secondHand;
//    delete hourHand;
}

void AnalogClockPlugin::initializeScene(QGraphicsScene &scene)
{
//    new QPolygonF(new QVector<QPointF>());
//    this->secondHand = new QGraphicsPolygonItem(

//                )
    scene.addRect(0,0,10,10);
}

void AnalogClockPlugin::draw(QGraphicsScene &scene)
{
    scene.addRect(0,0,100,100);
}

int AnalogClockPlugin::refreshSpeed()
{
    return 1000;
}

PluginInterface *AnalogClockPluginFactory::getInstance()
{
    return new AnalogClockPlugin();
}
