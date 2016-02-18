#include "widgetbase.h"
#include "ui_widgetbase.h"

WidgetBase::WidgetBase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetBase)
{
    ui->setupUi(this);
    graphicsScene = new QGraphicsScene(this);
    ui->graphicsView->setScene(graphicsScene);
}

WidgetBase::~WidgetBase()
{
    delete ui;
}
