#ifndef DASHBOARDPLUGINBASE_H
#define DASHBOARDPLUGINBASE_H

#include <QWidget>
#include <QTimer>
#include <QGraphicsScene>

#include "plugininterface.h"

namespace Ui {
class DashboardPluginBase;
}

class DashboardPluginBase : public QWidget
{
    Q_OBJECT

public:
    explicit DashboardPluginBase(PluginInterface *pluginInterface = 0, QWidget *parent = 0);
    ~DashboardPluginBase();

private:
    Ui::DashboardPluginBase *ui;
    QGraphicsScene *graphicsScene;
    PluginInterface *pluginInterface;
    QTimer *animationTimer;

private slots:
    void animate();
};

#endif // DASHBOARDPLUGINBASE_H
