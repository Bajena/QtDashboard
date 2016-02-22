#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QPluginLoader>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDir pluginsDir = QDir(qApp->applicationDirPath());
    pluginsDir.cdUp();
    pluginsDir.cdUp();
    pluginsDir.cd("Dashboard");
    pluginsDir.cd("plugins");

    foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
        QPluginLoader loader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = loader.instance();
        if (plugin) {
            plugins.append(plugin);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_drawButton_clicked()
{
    ui->dashboard->addPlugin(
                new DashboardPluginBase(
                    qobject_cast<PluginInterface*>(plugins[0])
                ));
}
