#include "analogclockplugin.h"

#include <QDebug>
#include <QTime>


AnalogClockPlugin::AnalogClockPlugin()
{

    this->currentTheme = "light";

    QAction *action = new QAction(tr("Change theme"), this);
    connect(action, SIGNAL(triggered()), this, SLOT(changeTheme()));

    this->menuActions.append(action);
}

AnalogClockPlugin::~AnalogClockPlugin()
{
    foreach (QGraphicsItem *item, this->graphicsScene->items())
    {
        delete item;
    }

    foreach (QAction *action, this->contextMenuActions())
    {
        delete action;
    }
}

void AnalogClockPlugin::initializeScene(QGraphicsScene *scene)
{
    this->graphicsScene = scene;

    QColor hourColor(127, 0, 127);
    QColor minuteColor(0, 127, 127, 191);
    QColor secondColor(127, 127, 0, 140);

    QPolygonF secondPolygon;
    secondPolygon << QPointF(7, 8) << QPointF(-7, 8) << QPointF(0, -90);
    this->secondHand = new QGraphicsPolygonItem(secondPolygon);
    this->secondHand->setBrush(secondColor);
    scene->addItem(this->secondHand);

    QPolygonF minutePolygon;
    minutePolygon << QPointF(7, 8) << QPointF(-7, 8) << QPointF(0, -70);
    this->minuteHand = new QGraphicsPolygonItem(minutePolygon);
    this->minuteHand->setBrush(minuteColor);
    scene->addItem(this->minuteHand);

    QPolygonF hourPolygon;
    hourPolygon << QPointF(7, 8) << QPointF(-7, 8) << QPointF(0, -40);
    this->hourHand = new QGraphicsPolygonItem(hourPolygon);
    this->hourHand->setBrush(hourColor);
    scene->addItem(this->hourHand);

    for (int i = 0; i < 12; ++i) {
        QGraphicsLineItem *line = scene->addLine(88, 0, 96, 0);
        line->setPen(hourColor);
        line->setTransform(QTransform().rotate(30.0 * (qreal)i));
    }

    for (int i = 0; i < 60; ++i) {
        if (i % 5 == 0) continue;
        QGraphicsLineItem *line = scene->addLine(88, 0, 92, 0);
        line->setPen(minuteColor);
        line->setTransform(QTransform().rotate(6.0 * (qreal)i));
    }

    connect(scene, SIGNAL(sceneRectChanged(const QRectF &)), this, SLOT(scaleContents(const QRectF &)));

    rotateHands();
}

void AnalogClockPlugin::draw(QGraphicsScene *scene)
{
    rotateHands();
}

int AnalogClockPlugin::refreshSpeed()
{
    return 1000;
}

QList<QAction *> AnalogClockPlugin::contextMenuActions()
{
    return this->menuActions;
}

void AnalogClockPlugin::rotateHands()
{
    QTime time = QTime::currentTime();
    this->hourHand->setRotation(30.0 * ((time.hour() + time.minute() / 60.0)));
    this->minuteHand->setRotation(6.0 * ((time.minute() + time.second() / 60.0)));
    this->secondHand->setRotation(6.0 * time.second());
}

void AnalogClockPlugin::scaleContents(const QRectF &rect)
{
    qDebug() << "scaleContents:" << rect;
    qreal minDimension = rect.width() < rect.height() ? rect.width() : rect.height();
    qDebug() << "minDimension: " << minDimension;
    qDebug() << "scale: " << minDimension / BASE_SIZE;

    foreach (QGraphicsItem *item, this->graphicsScene->items())
    {
        item->setScale(minDimension / BASE_SIZE);
    }
}

void AnalogClockPlugin::changeTheme()
{
    this->currentTheme = this->currentTheme == "light" ? "dark" : "light";
    qDebug() << "ChangeTheme = " << this->currentTheme;

    if (this->currentTheme == "dark")
    {
        this->graphicsScene->setBackgroundBrush(QColor(0, 0, 0));
    }
    else
    {
        this->graphicsScene->setBackgroundBrush(QColor(255, 255, 255));
    }
}

QString AnalogClockPluginFactory::pluginName()
{
    return "Analog clock";
}

PluginInterface *AnalogClockPluginFactory::getInstance()
{
    return new AnalogClockPlugin();
}

