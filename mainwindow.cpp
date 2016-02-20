#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "simpleanimationplugin.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_drawButton_clicked()
{
    ui->dashboard->addPlugin(
                new DashboardPluginBase(
                    new SimpleAnimationPlugin()
                ));
}
