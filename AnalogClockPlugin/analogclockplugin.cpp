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
    QColor hourColor(127, 0, 127);
    QColor minuteColor(0, 127, 127, 191);
    QColor secondColor(127, 127, 0, 140);

    QPolygonF secondPolygon;
    secondPolygon << QPointF(7, 8) << QPointF(-7, 8) << QPointF(0, -90);
    this->secondHand = new QGraphicsPolygonItem(secondPolygon);
    this->secondHand->setBrush(secondColor);
    scene.addItem(this->secondHand);

    QPolygonF minutePolygon;
    minutePolygon << QPointF(7, 8) << QPointF(-7, 8) << QPointF(0, -70);
    this->minuteHand = new QGraphicsPolygonItem(minutePolygon);
    this->minuteHand->setBrush(minuteColor);
    scene.addItem(this->minuteHand);

    QPolygonF hourPolygon;
    hourPolygon << QPointF(7, 8) << QPointF(-7, 8) << QPointF(0, -40);
    this->hourHand = new QGraphicsPolygonItem(hourPolygon);
    this->hourHand->setBrush(hourColor);
    scene.addItem(this->hourHand);

    for (int i = 0; i < 12; ++i) {
        QGraphicsLineItem *line = scene.addLine(88, 0, 96, 0);
        line->setPen(hourColor);
        line->setTransform(QTransform().rotate(30.0 * (qreal)i));
    }

    for (int i = 0; i < 60; ++i) {
        if (i % 5 == 0) continue;
        QGraphicsLineItem *line = scene.addLine(88, 0, 92, 0);
        line->setPen(minuteColor);
        line->setTransform(QTransform().rotate(6.0 * (qreal)i));
    }

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

