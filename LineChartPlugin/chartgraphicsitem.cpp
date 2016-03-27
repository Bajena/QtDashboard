#include "chartgraphicsitem.h"

#include <QPainter>
#include <QDebug>

ChartGraphicsItem::ChartGraphicsItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent) : QGraphicsRectItem(x, y, width, height, parent)
{
    this->padding = 30;
    this->maxSeriesSize = 10;
    this->series = QList<ChartPoint>();
    this->setYAxisScale(3,5);
}

void ChartGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawLine(xAxis());
    painter->drawLine(yAxis());

    drawSeries(painter);
    drawYTicks(painter, 5, true);
}

void ChartGraphicsItem::setYAxisScale(qreal min, qreal max)
{
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
    return zero().y() - ((value - yAxisMin) / (yAxisMax - yAxisMin)) * yAxis().length();
}

qreal ChartGraphicsItem::calculateX(qreal value, int seriesSize, int index)
{
    return zero().x() + (index) * xAxis().length() / (seriesSize - 1);
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

void ChartGraphicsItem::drawSeries(QPainter *painter)
{
    QList<ChartPoint> seriesCopy(this->series);

    QPointF p1 = zero();
    QPointF p2 = zero();

    for (int i = 0;i < seriesCopy.count(); i++)
    {
        qreal x = calculateX(seriesCopy[i].value, seriesCopy.count(), i);
        qreal y = calculateY(seriesCopy[i].value);
        p2 = QPointF(x,y);
        qDebug() << "i: " << i << "val: " << seriesCopy[i].value << " zero: " << zero() << " series count: " << seriesCopy.count() << "p2: " << p2;
        if (i > 0) painter->drawLine(p1, p2);
        painter->drawText(p2, QString::number(seriesCopy[i].value));
        drawXTick(painter, x, seriesCopy[i]);
        p1 = p2;
    }
}

void ChartGraphicsItem::drawYTicks(QPainter *painter, int ticksCount, bool drawZeroTick)
{
    qreal tickLength = 10;
    qreal textWidth = 50;
    qreal textHeight = 20;
    qreal iterY = yAxisMin;

    for (int i = 0; i <= ticksCount; i++)
    {
        qreal x = zero().x();
        qreal y = calculateY(iterY);
        QPointF p1(x - tickLength / 2, y);
        QPointF p2(x + tickLength / 2, y);
        qDebug() << "Tick: " << iterY << "tick_step: " << yAxis().length() / ticksCount;
        if (i > 0 || drawZeroTick)
        {
            painter->drawLine(p1, p2);

            painter->drawText(QRectF(x - textWidth - tickLength, y - 0.5 * textHeight, textWidth, textHeight), QString::number(iterY), QTextOption(Qt::AlignRight));
        }
        iterY += (yAxisMax - yAxisMin) / ticksCount;
    }
}

void ChartGraphicsItem::drawXTick(QPainter *painter, qreal x, ChartPoint &point)
{
    qreal tickLength = 10;
    qreal textWidth = 50;
    qreal textHeight = 20;

    QPointF p1(x, zero().y() - tickLength / 2);
    QPointF p2(x, zero().y() + tickLength / 2);
    painter->drawLine(p1, p2);

    painter->drawText(QRectF(x - textWidth / 2, zero().y() + 0.75 * tickLength, textWidth, textHeight), point.time.toString());
//    painter->drawText(x, zero().y() + tickLength, point.time.toString());
}
