#ifndef DASHBOARDPLUGINBASE_H
#define DASHBOARDPLUGINBASE_H

#include <QWidget>
#include <QGraphicsScene>

namespace Ui {
class DashboardPluginBase;
}

class DashboardPluginBase : public QWidget
{
    Q_OBJECT

public:
    explicit DashboardPluginBase(QWidget *parent = 0);
    ~DashboardPluginBase();

private:
    Ui::DashboardPluginBase *ui;
    QGraphicsScene *graphicsScene;
};

#endif // DASHBOARDPLUGINBASE_H
