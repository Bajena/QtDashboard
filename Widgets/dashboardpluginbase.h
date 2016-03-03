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
    DashboardPluginBase(QWidget *parent = 0);
    DashboardPluginBase(PluginInterface *pluginInterface, QWidget *parent = 0);
    ~DashboardPluginBase();
    void setPlugin(PluginInterface*);

private:
    Ui::DashboardPluginBase *ui;
    QGraphicsScene *graphicsScene = 0;
    PluginInterface *pluginInterface = 0;
    QTimer *animationTimer = 0;

private slots:
    void animate();
    void clearPlugin();
    void on_DashboardPluginBase_customContextMenuRequested(const QPoint &pos);
};

#endif // DASHBOARDPLUGINBASE_H
