#ifndef WIDGETBASE_H
#define WIDGETBASE_H

#include <QWidget>
#include <QGraphicsScene>

namespace Ui {
class WidgetBase;
}

class WidgetBase : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetBase(QWidget *parent = 0);
    ~WidgetBase();

private:
    Ui::WidgetBase *ui;
    QGraphicsScene *graphicsScene;
};

#endif // WIDGETBASE_H
