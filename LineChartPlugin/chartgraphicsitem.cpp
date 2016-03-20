#include "chartgraphicsitem.h"

#include <QPainter>

void ChartGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->fillRect(boundingRect(), Qt::blue);
}
