#include "widgetgraphicsview.h"

#include <QPaintEvent>
#include <QDebug>

WidgetGraphicsView::WidgetGraphicsView(QWidget *parent)
{

}

void WidgetGraphicsView::resizeEvent(QResizeEvent *event)
{
     QGraphicsView::resizeEvent(event);

     if (this->scene())
     {
         qreal width = event->size().width();
         qreal height = event->size().height();

         this->scene()->setSceneRect(-width / 2, -height / 2, width, height);
     }
}
