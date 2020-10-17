#include "singlemode.h"
#include "ui_singlemode.h"

SingleMode::SingleMode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SingleMode)
{
    ui->setupUi(this);
}

SingleMode::~SingleMode()
{
    delete ui;
}


void SingleMode::on_returnButton_clicked()
{
    emit display(0);
}
