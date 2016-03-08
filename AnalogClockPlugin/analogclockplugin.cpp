#include "analogclockplugin.h"

#include <QTime>


AnalogClockPlugin::AnalogClockPlugin()
{
}

AnalogClockPlugin::~AnalogClockPlugin()
{
    delete secondHand;
    delete minuteHand;
    delete hourHand;
}

void AnalogClockPlugin::initializeScene(QGraphicsScene &scene)
{
    QPolygonF hourPolygon;
    hourPolygon << QPointF(-20, 0) << QPointF(20, 0) << QPointF(0, -45);
    this->hourHand = new QGraphicsPolygonItem(hourPolygon);
    scene.addItem(this->hourHand);


    QPolygonF minutePolygon;
    minutePolygon << QPointF(-15, 0) << QPointF(15, 0) << QPointF(0, -60);
    this->minuteHand = new QGraphicsPolygonItem(minutePolygon);
    scene.addItem(this->minuteHand);


    QPolygonF secondPolygon;
    secondPolygon << QPointF(-10, 0) << QPointF(10, 0) << QPointF(0, -75);
    this->secondHand = new QGraphicsPolygonItem(secondPolygon);
    scene.addItem(this->secondHand);
}

void AnalogClockPlugin::draw(QGraphicsScene &scene)
{
    QTime time = QTime::currentTime();
    this->hourHand->setRotation(30.0 * ((time.hour() + time.minute() / 60.0)));
    this->minuteHand->setRotation(6.0 * ((time.minute() + time.second() / 60.0)));
    this->secondHand->setRotation(6.0 * time.second());
}

int AnalogClockPlugin::refreshSpeed()
{
    return 1000;
}

PluginInterface *AnalogClockPluginFactory::getInstance()
{
    return new AnalogClockPlugin();
}
