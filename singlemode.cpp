#include "singlemode.h"
#include "ui_singlemode.h"
#include "schemeinfo.h"
#include "mainwidget.h"
#include "settings.h"

SingleMode::SingleMode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SingleMode)
{
    ui->setupUi(this);
    ui->thresholdEdit->setText(QString::number(Threshold_Default));
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
    if(now_user_id!=0){
        sqlite.SigFileInsert(singlemodeset,now_user_id,QString("single"));
    }
    else{
        now_user_name="-";
    }
    QString control_str = QString("create table history ( id int,name text,scheme text,\
                                                position text, power int,threshold int,\
                                                freq int,pulse_num_oneT int,rest_time int,\
                                                T_num int,all_pulse_num int,all_time text)");
    sqlite.execute(control_str);
    //创建history表，如果已经存在在qdebug输出错误信息，但不影响继续运行
    sqlite.SigHisInsert(singlemodeset,now_user_id,now_user_name,QString("single"));

}
