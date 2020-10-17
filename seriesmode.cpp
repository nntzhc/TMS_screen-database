#include "seriesmode.h"
#include "ui_seriesmode.h"

SeriesMode::SeriesMode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SeriesMode)
{
    ui->setupUi(this);
}

SeriesMode::~SeriesMode()
{
    delete ui;
}


void SeriesMode::on_returnButton_clicked()
{
    emit display(0);
}
