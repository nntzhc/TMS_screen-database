#include "singlemode.h"
#include "ui_singlemode.h"
#include "schemeinfo.h"
#include "mainwidget.h"


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

void SingleMode::on_startButton_clicked()
{
    QString position = ui->positionEdit->text();
    if(ui->positionEdit->text() == ""){position=" ";}

    int threshold = ui->thresholdEdit->text().toInt();
    if(ui->thresholdEdit->text() == ""){threshold=100;}//备注：这里好像是可以加到设置里面，默认的阈值

    int power = ui->powerEdit->text().toInt();


    if(ui->powerEdit->text() == ""){
        //power不能为空，否则在读取文件时会出现问题。
        QMessageBox::about(NULL, "提示", "未填写power");
        return;
    }

    SchemeInfo singlemodeset;

    singlemodeset.power=power;
    singlemodeset.threshold=threshold;
    singlemodeset.position=position;

    SqliteDBAOperator sqlite;
    sqlite.SigFileInsert(singlemodeset,now_user_id,QString("single"));


}
