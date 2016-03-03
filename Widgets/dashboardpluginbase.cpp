#include "dashboardpluginbase.h"
#include "ui_dashboardpluginbase.h"

#include <QMenu>
#include <QDebug>

DashboardPluginBase::DashboardPluginBase(PluginInterface *pluginInterface, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DashboardPluginBase)
{
    ui->setupUi(this);

    graphicsScene = new QGraphicsScene(this);
    ui->graphicsView->setScene(graphicsScene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    this->setPlugin(pluginInterface);
}

DashboardPluginBase::~DashboardPluginBase()
{
    delete ui;
}

void DashboardPluginBase::animate()
{
    pluginInterface->draw(*graphicsScene);
}

void DashboardPluginBase::setPlugin(PluginInterface *plugin)
{
    if (!plugin)
    {
        ui->placeholderLabel->show();
        ui->graphicsView->hide();
        this->pluginInterface = NULL;

        if (this->animationTimer)
        {
            this->animationTimer->stop();
            delete animationTimer;
        }
    }
    else
    {
        this->pluginInterface = plugin;
        this->animationTimer = new QTimer(this);
        connect(this->animationTimer, SIGNAL(timeout()), this, SLOT(animate()));
        this->animationTimer->start(pluginInterface->refreshSpeed());
        ui->graphicsView->show();
        ui->placeholderLabel->hide();
    }
}

void DashboardPluginBase::clearPlugin()
{
    setPlugin(NULL);
}

void DashboardPluginBase::on_DashboardPluginBase_customContextMenuRequested(const QPoint &pos)
{
    QPoint globalPos = this->mapToGlobal(pos);

    QMenu contextMenu;

    if (this->pluginInterface)
    {
       QAction *action = new QAction(tr("Remove widget"), this);
       connect(action, SIGNAL(triggered()), this, SLOT(clearPlugin()));
       contextMenu.addAction(action);
       contextMenu.addAction(action);
    }
    else {
        // Change plugin action
    }

    contextMenu.exec(globalPos);
}
