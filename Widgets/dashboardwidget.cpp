#include "dashboardwidget.h"
#include "ui_dashboardwidget.h"
#include "dashboardpluginbase.h"

DashboardWidget::DashboardWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DashboardWidget)
{
    ui->setupUi(this);
}

DashboardWidget::~DashboardWidget()
{
    delete ui;
}

void DashboardWidget::addPlugin(DashboardPluginBase *plugin)
{
    int count = plugins.count();

    plugins.append(plugin);

    int row = count / 2;
    int column = count % 2;
    ui->gridLayout->addWidget(plugin, row, column);
}

