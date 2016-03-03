#include "mainwindow.h"
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

    foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
        QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = loader.instance();
        if (plugin) {
            ui->pluginsList->addItem(new QListWidgetItem(pluginsDir.absoluteFilePath(fileName)));
            plugins.append(plugin);
        }
    }
}

void MainWindow::on_addPluginButton_clicked()
{
    int widgetIndex = ui->pluginsList->currentRow();
    if (widgetIndex == -1) return;

    PluginInterfaceFactory* pluginFactory = qobject_cast<PluginInterfaceFactory*>(plugins[widgetIndex]);
    PluginInterface* plugin = pluginFactory->getInstance();
    ui->dashboard->addPlugin(
                new DashboardPluginBase(
                    plugin
                ));
}

void MainWindow::on_pluginsList_currentRowChanged(int currentRow)
{
    ui->addPluginButton->setDisabled(currentRow == -1);
}
