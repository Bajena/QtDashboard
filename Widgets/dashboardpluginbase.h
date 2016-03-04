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
    DashboardPluginBase(PluginInterfaceFactory *pluginInterfaceFactory, QWidget *parent = 0);
    ~DashboardPluginBase();

private:
    Ui::DashboardPluginBase *ui;
    QGraphicsScene *graphicsScene;
    PluginInterface *pluginInstance;
    QTimer *animationTimer;

    void showContextMenu(const QPoint&);
    void setPluginInstance(PluginInterface*);

private slots:
    void animate();
    void clearPluginInstance();
    void buildPluginInstance(PluginInterfaceFactory* factory);
    void buildPluginInstance(QString pluginName);
    void on_DashboardPluginBase_customContextMenuRequested(const QPoint &pos);
    void on_placeholderButton_clicked();
};

#endif // DASHBOARDPLUGINBASE_H
