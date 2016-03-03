#include "dashboardwidget.h"
#include "ui_dashboardwidget.h"
#include "dashboardpluginbase.h"
#include "widgetplaceholder.h"

DashboardWidget::DashboardWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DashboardWidget)
{
    ui->setupUi(this);
    populatePlaceholders();
}

DashboardWidget::~DashboardWidget()
{
    delete ui;
}

void DashboardWidget::addPlugin(DashboardPluginBase *plugin)
{
    int count = plugins.count();

    plugins.append(plugin);

    int row = count / columns;
    int column = count % columns;
    ui->gridLayout->addWidget(plugin, row, column);
}

void DashboardWidget::populatePlaceholders()
{
    for (int i = 0; i < maxWidgets; i++)
    {
        int row = i / columns;
        int column = i % columns;

        ui->gridLayout->addWidget(new WidgetPlaceholder(), row, column);
    }
}

