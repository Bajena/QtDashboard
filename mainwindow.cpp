#include "mainwindow.h"
#include "pluginrepository.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QPluginLoader>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionReload, SIGNAL(triggered()), this, SLOT(populatePluginsList()));
    populatePluginsList();
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::populatePluginsList()
{
    QDir pluginsDir = QDir(qApp->applicationDirPath());
    pluginsDir.cdUp();
    pluginsDir.cdUp();
    pluginsDir.cd("Dashboard");
    pluginsDir.cd("plugins");

    PluginRepository::getInstance()->loadPlugins(pluginsDir);
}
