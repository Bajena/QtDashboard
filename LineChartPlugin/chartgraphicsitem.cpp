#include "chartgraphicsitem.h"

#include <QPainter>
#include <QDebug>

ChartGraphicsItem::ChartGraphicsItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent) : QGraphicsRectItem(x, y, width, height, parent)
{
    this->padding = 10;
    this->maxSeriesSize = 5;
    this->series = QList<ChartPoint>();
    this->setYAxisScale(3,5);
}

void ChartGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawLine(xAxis());
    painter->drawLine(yAxis());

    QPointF p1 = zero();
    QPointF p2 = zero();

    QList<ChartPoint> seriesCopy(this->series);

    for (int i = 0;i < seriesCopy.count(); i++)
    {
        qreal x = zero().x() + (i + 1) * xAxis().length() / (seriesCopy.count());
        qreal y = zero().y() - calculateY(seriesCopy[i].value);
        p2 = QPointF(x,y);
        qDebug() << "i: " << i << "val: " << seriesCopy[i].value << " zero: " << zero() << " series count: " << seriesCopy.count() << "p2: " << p2;
        painter->drawLine(p1, p2);
        p1 = p2;
    }
}

void ChartGraphicsItem::setYAxisScale(qreal min, qreal max)
{
//    if (min > max) throw std::invalid_argument("min > max");

    yAxisMin = min;
    yAxisMax = max;
}

void ChartGraphicsItem::fetchNewValue()
{
    qreal random = rand() % int((yAxisMax - yAxisMin) * 10);
    qreal val = yAxisMin + random / 10;
    qDebug() << "Random: " << random << "val: " << val;
    ChartPoint point = ChartPoint(QTime::currentTime(), val);

    if (series.count() >= maxSeriesSize)
    {
        series.removeFirst();
    }
    series.append(point);
}

qreal ChartGraphicsItem::calculateY(qreal value)
{
    return ((value - yAxisMin) / yAxisMax) * yAxis().length() + zero().y();
}

QPointF ChartGraphicsItem::zero()
{
    QRectF br = boundingRect();
    return QPointF(br.x() + padding, br.y() + br.height() - padding);
}

QLineF ChartGraphicsItem::xAxis()
{
    QRectF br = boundingRect();
    QPointF xAxisEnd(br.x() + br.width() - padding, br.y() + br.height() - padding);
    return QLineF(zero(), xAxisEnd);
}

QLineF ChartGraphicsItem::yAxis()
{
    QRectF br = boundingRect();
    QPointF yAxisEnd(br.x() + padding, br.y() + padding);
    return QLineF(zero(), yAxisEnd);
}
