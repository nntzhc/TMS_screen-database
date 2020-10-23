#include "seriesmode.h"
#include "ui_seriesmode.h"
#include "schemeinfo.h"
#include <QDateTime>
#include <QTimer>
#include "sqlitedbaoperator.h"
#include "mainwidget.h"
#include "tipsdlg.h"

clock_t  time_kp;

QTimer *timer;
int msec = 0;
int all_time_sec=0;
int time_ispaused=0;
float now_bar_pos=0;
int time_interval=0;
int now_pulses = 0;         //已经发送的脉冲信号数
int all_pulses = 0;         //总脉冲数
SchemeInfo seriesmodeset;
SqliteDBAOperator sqlite;

SeriesMode::SeriesMode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SeriesMode)
{
    ui->setupUi(this);
    ui->progressBar->setRange(0, 100);
    ui->progressBar->setValue(0);


}

SeriesMode::~SeriesMode()
{
    delete ui;
}


void SeriesMode::on_returnButton_clicked()
{
    emit display(0);
}

void SeriesMode::on_startButton_clicked()
{
    time_kp = clock();
    now_bar_pos=0;
    msec=0;
    timer = new QTimer(this);

    if(ui->powerEdit->text() == "" or ui->pulsesEdit->text() == "" or ui->freqEdit->text() == ""){
        //power不能为空，否则在读取文件时会出现问题。
        QMessageBox::about(NULL, "提示", "未填写power");
        return;
    }

    QString position = ui->positionEdit->text();
    if(ui->positionEdit->text() == ""){position=" ";}
    int threshold = ui->thresholdEdit->text().toInt();
    if(ui->thresholdEdit->text() == ""){threshold=100;}//备注：这里好像是可以加到设置里面，默认的阈值
    int power = ui->powerEdit->text().toInt();
    int pulse_num_oneT = ui->pulsesEdit->text().toInt();
    int freq = ui->freqEdit->text().toInt();


    seriesmodeset.power=power;
    seriesmodeset.threshold=threshold;
    seriesmodeset.position=position;
    seriesmodeset.pulse_num_oneT=pulse_num_oneT;
    seriesmodeset.freq=freq;

    //全局变量，脉冲数
    all_pulses=pulse_num_oneT;
    now_pulses=0;

    //计算两个百分比之间的毫秒数和百分比数
    all_time_sec=1000*pulse_num_oneT/freq;
    time_interval=1000/freq;


    //建立计时器，发送脉冲信号和改变bar值
    connect(timer, SIGNAL(timeout()), this, SLOT(emit_pulse())); // SLOT填入一个槽函数
    timer->start(time_interval); //每隔1%对应的时间发送一个信号给bar


}

void SeriesMode::on_stopButton_clicked()
{

    if(ui->stopButton->text()=="暂停"){
        time_ispaused=1;

        msec+= (clock() - time_kp) / (double)CLOCKS_PER_SEC;
        ui->stopButton->setText("继续");
        TipsDlg dlg(TipsType_Ok,"已暂停", this->topLevelWidget());
        dlg.setAttribute(Qt::WA_ShowModal, true);
        dlg.startTimer();
        dlg.exec();
    }
    else{
        time_ispaused=0;
        time_kp = clock();
        ui->stopButton->setText("暂停");
    }
}

void SeriesMode::on_endButton_clicked()
{
    timer->stop();
//    msec+= (clock() - time_kp) / (double)CLOCKS_PER_SEC;

    QString all_time = QString::number(msec%60000)+":"+QString::number(msec/1000-msec%60000);
    seriesmodeset.all_time=all_time;

    this->end_procedure();

    TipsDlg dlg(TipsType_Ok,"已停止", this->topLevelWidget());
    dlg.setAttribute(Qt::WA_ShowModal, true);
    dlg.startTimer();
    dlg.exec();
}

//用于发送脉冲信号
void SeriesMode::emit_pulse(){
    //仅在不暂停的时候计数
    if(!time_ispaused){
        now_pulses+=1;
        if(now_pulses==all_pulses){
            ui->progressBar->setValue(100);
            this->end_procedure();
            QMessageBox::about(NULL, "提示", "已完成");
            return;
        }
        now_bar_pos+=100.0/(float)all_pulses;
        ui->progressBar->setValue(now_bar_pos);
    }
}

void SeriesMode::end_procedure(){
    timer->stop();
    msec+= (clock() - time_kp) / (double)CLOCKS_PER_SEC;
    qDebug() << "time passed "<< msec;

    QString all_time = QString::number(msec/60)+":"+QString::number(msec-msec/60);
    seriesmodeset.all_time=all_time;

    //在未登录状态也可以使用，不会记录。在未登陆下使用插入应该会有问题
    if(now_user_id!=0){
        sqlite.SigFileInsert(seriesmodeset,now_user_id,QString("series"));
    }

    all_time_sec=0;
    time_ispaused=0;
    time_interval=0;
    msec=0;
    ui->progressBar->setValue(0);
}
