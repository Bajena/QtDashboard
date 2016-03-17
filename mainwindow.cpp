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

    foreach (QString filename, pluginsDir.entryList(QDir::Files)) {
        QString filepath = pluginsDir.absoluteFilePath(filename);
        QPluginLoader loader(filepath);
        QObject *plugin = loader.instance();
        if (plugin) {
            PluginInterfaceFactory* instanceFactory = qobject_cast<PluginInterfaceFactory*>(plugin);
            PluginRepository::getInstance()->addPlugin(instanceFactory, filepath, instanceFactory->pluginName());
        }
    }
}
