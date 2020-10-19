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
    //将用户输入的姓名由nameLineEdit取出
    if(position == ""){position="未填写";}

    int threshold = ui->thresholdEdit->text().toInt();
    //将用户输入的学号由idLineEdit取出，并转换为整型

    int power = ui->powerEdit->text().toInt();
    //将用户输入的学号由enLineEdit取出，并转化为整型

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
    sqlite.SigFileInsert(singlemodeset,now_user_id,QString("单脉冲"));


}
