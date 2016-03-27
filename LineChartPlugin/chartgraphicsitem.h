#ifndef CHARTGRAPHICSITEM_H
#define CHARTGRAPHICSITEM_H

#include <QContiguousCache>
#include <QGraphicsItem>
#include <QTime>

class ChartGraphicsItem : public QGraphicsRectItem
{
public:
    ChartGraphicsItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem * parent = 0);
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void setYAxisScale(qreal min, qreal max);
    void fetchNewValue();

private:
    class ChartPoint
    {
    public:
        ChartPoint() {

        }
        ChartPoint(QTime t, qreal val) { time = t; value = val; }
        QTime time;
        qreal value;
    };

    QList<ChartPoint> series;
    qreal yAxisMin;
    qreal yAxisMax;
    int   maxSeriesSize;
    qreal padding;

    qreal calculateY(qreal value);
    QPointF zero();
    QLineF xAxis();
    QLineF yAxis();
};

#endif // CHARTGRAPHICSITEM_H
