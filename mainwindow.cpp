#include "mainwindow.h"
#include "pluginrepository.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QPluginLoader>
#include <QDebug>

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
#ifdef QT_DEBUG
    qDebug() << "Running a debug build";
    pluginsDir.cdUp();
    pluginsDir.cdUp();
    pluginsDir.cd("Dashboard");
#endif
    pluginsDir.cd("plugins");
    qDebug() << "Plugins dir: " << pluginsDir.path();

    PluginRepository::getInstance()->loadPlugins(pluginsDir);
}
