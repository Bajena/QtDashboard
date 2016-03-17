#include "dashboardpluginbase.h"
#include "ui_dashboardpluginbase.h"

#include <QMenu>
#include <QDebug>
#include <pluginrepository.h>
#include <QSignalMapper>
#include <QPaintEvent>

DashboardPluginBase::DashboardPluginBase(PluginInterfaceFactory *pluginInterfaceFactory, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DashboardPluginBase)
{
    this->pluginInstance = NULL;
    this->animationTimer = NULL;
    this->graphicsScene = NULL;

    ui->setupUi(this);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    if (pluginInterfaceFactory) {
        this->buildPluginInstance(pluginInterfaceFactory);
    }
    else {
        this->clearPluginInstance();
    }
}

DashboardPluginBase::~DashboardPluginBase()
{
    delete ui;
}

void DashboardPluginBase::animate()
{
    this->pluginInstance->draw(graphicsScene);
}

void DashboardPluginBase::setPluginInstance(PluginInterface *instance)
{
    if (this->pluginInstance)
    {
        delete this->pluginInstance;
    }
    this->pluginInstance = instance;

    if (this->animationTimer)
    {
        this->animationTimer->stop();
        delete animationTimer;
    }
    this->animationTimer = NULL;

    if (!instance)
    {
        ui->placeholderButton->show();
        ui->graphicsView->hide();
    }
    else
    {
        graphicsScene = new QGraphicsScene(this);
        this->pluginInstance->initializeScene(graphicsScene);
        ui->graphicsView->setScene(graphicsScene);
        graphicsScene->setSceneRect(-ui->graphicsView->width()/2, -ui->graphicsView->height()/2, ui->graphicsView->width(), ui->graphicsView->height());
        this->animationTimer = new QTimer(this);
        connect(this->animationTimer, SIGNAL(timeout()), this, SLOT(animate()));
        this->animationTimer->start(pluginInstance->refreshSpeed());
        ui->graphicsView->show();
        ui->placeholderButton->hide();
    }
}

void DashboardPluginBase::buildPluginInstance(PluginInterfaceFactory *factory)
{
    this->setPluginInstance(factory->getInstance());
}

void DashboardPluginBase::buildPluginInstance(QString pluginName)
{
    PluginInterfaceFactory *factory = PluginRepository::getInstance()->findFactoryByPluginName(pluginName);
    this->buildPluginInstance(factory);
}


void DashboardPluginBase::clearPluginInstance()
{
    this->setPluginInstance(NULL);
}

void DashboardPluginBase::on_DashboardPluginBase_customContextMenuRequested(const QPoint &pos)
{
    const QPoint globalPos = this->mapToGlobal(pos);
    showContextMenu(globalPos);
}

void DashboardPluginBase::on_placeholderButton_clicked()
{
    const QPoint globalPos = QCursor::pos();
    showContextMenu(globalPos);
}

void DashboardPluginBase::showContextMenu(const QPoint &globalPos)
{
    QMenu contextMenu;

    if (this->pluginInstance)
    {
       QAction *action = new QAction(tr("Remove widget"), this);
       connect(action, SIGNAL(triggered()), this, SLOT(clearPluginInstance()));
       contextMenu.addAction(action);
       foreach( QAction* pluginAction, this->pluginInstance->contextMenuActions() )
       {
           contextMenu.addAction(pluginAction);
       }
    }
    else {
        QMenu* pluginPickerSubMenu = new QMenu("Add widget");

        foreach (PluginData *pluginData, PluginRepository::getInstance()->plugins)
        {
            QAction *action = new QAction(pluginData->name, this);
            QSignalMapper* mapper = new QSignalMapper(this);

            mapper->setMapping(action, pluginData->name);
            connect(action, SIGNAL(triggered()), mapper, SLOT(map()));
            connect(mapper, SIGNAL(mapped(QString)), this, SLOT(buildPluginInstance(QString)));
            pluginPickerSubMenu->addAction(action);
        }
        contextMenu.addMenu(pluginPickerSubMenu);
    }

    contextMenu.exec(globalPos);
}
