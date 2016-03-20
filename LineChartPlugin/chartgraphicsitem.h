#ifndef CHARTGRAPHICSITEM_H
#define CHARTGRAPHICSITEM_H

#include <QGraphicsItem>



class ChartGraphicsItem : public QGraphicsRectItem
{
public:
    ChartGraphicsItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem * parent = 0) : QGraphicsRectItem(x, y, width, height, parent)
    {

    }

    // QGraphicsItem interface
public:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // CHARTGRAPHICSITEM_H
