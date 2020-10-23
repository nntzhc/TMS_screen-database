#include "selectmodewidget.h"
#include "ui_selectmodewidget.h"
#include "tipsdlg.h"
#include "mainwidget.h"

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
    if(now_user_id==0){
        TipsDlg dlg(TipsType_Ok, "未登录，不记录档案", this->topLevelWidget());
        dlg.setAttribute(Qt::WA_ShowModal, true);
        dlg.startTimer();
        dlg.exec();
    }
    emit display(6);
}

void SelectModeWidget::on_seriesButton_clicked()
{
    if(now_user_id==0){
        TipsDlg dlg(TipsType_Ok, "未登录，不会被档案记录", this->topLevelWidget());
        dlg.setAttribute(Qt::WA_ShowModal, true);
        dlg.startTimer();
        dlg.exec();
    }
    emit display(7);
}

void SelectModeWidget::on_modifyButton_clicked()
{
    if(now_user_id==0){
        TipsDlg dlg(TipsType_Ok, "未登录，不会被档案记录", this->topLevelWidget());
        dlg.setAttribute(Qt::WA_ShowModal, true);
        dlg.startTimer();
        dlg.exec();
    }
    emit display(8);
}
