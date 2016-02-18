#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "widgetbase.h"

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
    ui->gridLayout->addWidget(new WidgetBase());
//    ui->graphicsView->scene()->addLine(0,0,100,100);
}
