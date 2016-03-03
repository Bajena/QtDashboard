#ifndef DASHBOARDWIDGET_H
#define DASHBOARDWIDGET_H

#include <QWidget>
#include "dashboardpluginbase.h"

namespace Ui {
class DashboardWidget;
}

class DashboardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DashboardWidget(QWidget *parent = 0);
    ~DashboardWidget();
    void addPlugin(DashboardPluginBase *plugin);

private:
    QList<DashboardPluginBase*> plugins;
    Ui::DashboardWidget *ui;
    void populatePlaceholders();
    int maxWidgets = 6;
    int columns = 2;
};

#endif // DASHBOARDWIDGET_H
