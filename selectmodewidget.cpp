#include "selectmodewidget.h"
#include "ui_selectmodewidget.h"

SelectModeWidget::SelectModeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectModeWidget)
{
    ui->setupUi(this);
}

SelectModeWidget::~SelectModeWidget()
{
    delete ui;
}

void SelectModeWidget::on_returnButton_clicked(){
    emit display(0);
}


void SelectModeWidget::on_singleButton_clicked()
{
    emit display(6);
}

void SelectModeWidget::on_seriesButton_clicked()
{
    emit display(7);
}

void SelectModeWidget::on_modifyButton_clicked()
{
    emit display(8);
}
