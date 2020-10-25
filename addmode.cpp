#include "addmode.h"
#include "ui_addmode.h"
#include "tipsdlg.h"

Addmode::Addmode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Addmode)
{
    ui->setupUi(this);

}

Addmode::~Addmode()
{
    delete ui;
}

void Addmode::on_addmodeButton_clicked()
{
    if(ui->nameLineEdit->text() == "" || ui->idLineEdit->text() == ""|| ui->diseaseEdit->text() == ""|| ui->positionEdit->text() == ""\
            || ui->powerEdit->text() == ""|| ui->freqEdit->text() == ""|| ui->pulse_num_oneTEdit->text() == ""|| ui->rest_timeEdit->text() == ""\
            || ui->T_numEdit->text() == ""){
            //方案信息除了阈值不能有空项
            QMessageBox::about(NULL, "错误", "存在空项");
            return;
        }
    QString name = ui->nameLineEdit->text();
    QString disease = ui->diseaseEdit->text();
    QString position = ui->positionEdit->text();
    int id = ui->idLineEdit->text().toInt();
    int power = ui->powerEdit->text().toInt();

    int threshold = ui->thresholdEdit->text().toInt();
    int freq = ui->freqEdit->text().toInt();
    int pulse_num_oneT = ui->pulse_num_oneTEdit->text().toInt();
    int rest_time = ui->rest_timeEdit->text().toInt();
    int T_num = ui->T_numEdit->text().toInt();

    QString all_time ;
    int all_pulse_num = pulse_num_oneT * T_num;
    int T_s=pulse_num_oneT/freq*T_num+rest_time*(T_num-1);
    all_time = QString::number((int)(T_s/60))+":"+QString::number(T_s%60);

    SqliteDBAOperator sqlite;
    sqlite.OpenDb();

    QString control_str = QString("create table schemes (id int primary key, name text,disease text, \
                                                        position text, power int,threshold int,\
                                                        freq int,pulse_num_oneT int,rest_time int,\
                                                        T_num int,all_pulse_num int, all_time text)");
    sqlite.execute(control_str);
    //创建schemes表，如果已经存在在qdebug输出错误信息，但不影响继续运行

    SchemeInfo s_info;

    s_info.id=id;
    s_info.name=name;
    s_info.disease=disease;
    s_info.position=position;
    s_info.power=power;

    s_info.threshold=threshold;
    s_info.freq=freq;
    s_info.pulse_num_oneT=pulse_num_oneT;
    s_info.rest_time=rest_time;
    s_info.T_num=T_num;

    s_info.all_pulse_num=all_pulse_num;
    s_info.all_time=all_time;

    QString pos_msg=QString("新建方案成功:");
    QString neg_msg=QString("该方案Id已经存在");

    if(sqlite.SigScheInsert(s_info)) {  TipsDlg dlg(TipsType_Ok, pos_msg+name, this->topLevelWidget());
            dlg.setAttribute(Qt::WA_ShowModal, true);
            dlg.startTimer();
            dlg.exec();
        }
    else QMessageBox::about(NULL, "错误", neg_msg);

    ui->nameLineEdit->clear();
    ui->idLineEdit->clear();
    ui->diseaseEdit->clear();
    ui->positionEdit->clear();
    ui->powerEdit->clear();
    ui->thresholdEdit->clear();
    ui->freqEdit->clear();
    ui->pulse_num_oneTEdit->clear();
    ui->rest_timeEdit->clear();
    ui->T_numEdit->clear();
}

void Addmode::on_returnButton_clicked()
{
    emit display(0);
}
