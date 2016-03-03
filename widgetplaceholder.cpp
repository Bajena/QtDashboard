#include "widgetplaceholder.h"
#include "ui_widgetplaceholder.h"

WidgetPlaceholder::WidgetPlaceholder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetPlaceholder)
{
    ui->setupUi(this);
}

WidgetPlaceholder::~WidgetPlaceholder()
{
    delete ui;
}
