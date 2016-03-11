#ifndef WIDGETGRAPHICSVIEW_H
#define WIDGETGRAPHICSVIEW_H

#include <QGraphicsView>

class WidgetGraphicsView : public QGraphicsView
{
public:
    WidgetGraphicsView(QWidget *parent = 0);
    // QWidget interface
protected:
    virtual void resizeEvent(QResizeEvent *);
};

#endif // WIDGETGRAPHICSVIEW_H
