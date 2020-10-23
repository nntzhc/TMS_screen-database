#include "modifymode_exec.h"
#include "ui_modifymode_exec.h"

Modifymode_exec::Modifymode_exec(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Modifymode_exec)
{
    ui->setupUi(this);
}

Modifymode_exec::~Modifymode_exec()
{
    delete ui;
}
