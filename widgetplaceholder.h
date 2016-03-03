#ifndef WIDGETPLACEHOLDER_H
#define WIDGETPLACEHOLDER_H

#include <QWidget>

namespace Ui {
class WidgetPlaceholder;
}

class WidgetPlaceholder : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetPlaceholder(QWidget *parent = 0);
    ~WidgetPlaceholder();

private:
    Ui::WidgetPlaceholder *ui;
};

#endif // WIDGETPLACEHOLDER_H
