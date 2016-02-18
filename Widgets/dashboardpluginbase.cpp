#include "dashboardpluginbase.h"
#include "ui_dashboardpluginbase.h"

DashboardPluginBase::DashboardPluginBase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DashboardPluginBase)
{
    ui->setupUi(this);
    graphicsScene = new QGraphicsScene(this);
    ui->graphicsView->setScene(graphicsScene);
}

DashboardPluginBase::~DashboardPluginBase()
{
    delete ui;
}
