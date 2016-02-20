#include "dashboardpluginbase.h"
#include "ui_dashboardpluginbase.h"

DashboardPluginBase::DashboardPluginBase(PluginInterface *pluginInterface, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DashboardPluginBase)
{
    ui->setupUi(this);

    this->pluginInterface = pluginInterface;

    this->animationTimer = new QTimer(this);
    connect(this->animationTimer, SIGNAL(timeout()), this, SLOT(animate()));
    this->animationTimer->start(pluginInterface->refreshSpeed());

    graphicsScene = new QGraphicsScene(this);
    ui->graphicsView->setScene(graphicsScene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}

DashboardPluginBase::~DashboardPluginBase()
{
    delete ui;
}

void DashboardPluginBase::animate()
{
    pluginInterface->draw(*graphicsScene);
}
