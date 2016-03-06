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
    hourPolygon << QPointF(-25, 0) << QPointF(25, 0) << QPointF(0, -75);
    this->hourHand = new QGraphicsPolygonItem(hourPolygon);
//    this->hourHand->setTransformOriginPoint(this->hourHand->boundingRect().width() / 2, this->hourHand->boundingRect().height());
    scene.addItem(this->hourHand);


    QPolygonF minutePolygon;
    hourPolygon << QPointF(-25, 0) << QPointF(25, 0) << QPointF(0, -75);
    this->minuteHand = new QGraphicsPolygonItem(minutePolygon);
//    this->minuteHand->setTransformOriginPoint(this->minuteHand->boundingRect().width() / 2, this->minuteHand->boundingRect().height());
    scene.addItem(this->minuteHand);


    QPolygonF secondPolygon;
    hourPolygon << QPointF(-25, 0) << QPointF(25, 0) << QPointF(0, -75);
    this->secondHand = new QGraphicsPolygonItem(secondPolygon);
//    this->secondHand->setTransformOriginPoint(this->secondHand->boundingRect().width() / 2, this->secondHand->boundingRect().height());
    scene.addItem(this->secondHand);
}

void AnalogClockPlugin::draw(QGraphicsScene &scene)
{
    QTime time = QTime::currentTime();
     this->hourHand->setRotation(30.0 * ((time.hour() + time.minute() / 60.0)));
    this->minuteHand->setRotation(6.0 * ((time.minute() + time.second() / 60.0)));
    this->secondHand->setRotation(time.second());
}

int AnalogClockPlugin::refreshSpeed()
{
    return 1000;
}

PluginInterface *AnalogClockPluginFactory::getInstance()
{
    return new AnalogClockPlugin();
}
