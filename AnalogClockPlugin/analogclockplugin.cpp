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
    hourPolygon << QPointF(7, 8) << QPointF(-7, 8) << QPointF(0, -40);
    this->hourHand = new QGraphicsPolygonItem(hourPolygon);
    scene.addItem(this->hourHand);


    QPolygonF minutePolygon;
    minutePolygon << QPointF(7, 8) << QPointF(-7, 8) << QPointF(0, -70);
    this->minuteHand = new QGraphicsPolygonItem(minutePolygon);
    scene.addItem(this->minuteHand);

    QPolygonF secondPolygon;
    secondPolygon << QPointF(7, 8) << QPointF(-7, 8) << QPointF(0, -90);
    this->secondHand = new QGraphicsPolygonItem(secondPolygon);
    scene.addItem(this->secondHand);

    rotateHands();
}

void AnalogClockPlugin::draw(QGraphicsScene &scene)
{
    rotateHands();
}

int AnalogClockPlugin::refreshSpeed()
{
    return 1000;
}

void AnalogClockPlugin::rotateHands()
{
    QTime time = QTime::currentTime();
    this->hourHand->setRotation(30.0 * ((time.hour() + time.minute() / 60.0)));
    this->minuteHand->setRotation(6.0 * ((time.minute() + time.second() / 60.0)));
    this->secondHand->setRotation(6.0 * time.second());
}

PluginInterface *AnalogClockPluginFactory::getInstance()
{
    return new AnalogClockPlugin();
}

