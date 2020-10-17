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
            //方案信息不能有空项
            QMessageBox::about(NULL, "错误", "存在空项");
//            TipsDlg dlg(TipsType_Ok, name+"方案设置不能存在空项", this->topLevelWidget());
//            dlg.setAttribute(Qt::WA_ShowModal, true);
//            dlg.startTimer();
//            dlg.exec();

            return;
        }
    QString name = ui->nameLineEdit->text();
    QString disease = ui->diseaseEdit->text();
    QString position = ui->positionEdit->text();
    QString id = ui->idLineEdit->text();

    int power = ui->powerEdit->text().toInt();
    int freq = ui->freqEdit->text().toInt();
    int pulse_num_oneT = ui->pulse_num_oneTEdit->text().toInt();
    int rest_time = ui->rest_timeEdit->text().toInt();
    int T_num = ui->T_numEdit->text().toInt();

    QString all_time ;
    int all_pulse_num = pulse_num_oneT * T_num;
    int T_s=pulse_num_oneT/freq*T_num+rest_time*(T_num-1);
    all_time = QString::number((int)(T_s/60))+":"+QString::number(T_s%60);

    QFile file("Schemes.txt");

    //判断方案编号是否已经被注册


    QVector<SchemeInfo> allSchemeInfo;
    //QFile file1("Schemes.txt");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    //以只读方式打开文本文件Schemes.txt

     QTextStream inp(&file);
    if(!file.isOpen()){ //文件打开失败
        QMessageBox::about(NULL, "反馈", "数据文件打开失败");
        return ;
    }
    while(!inp.atEnd()){    //读到文件结尾

        QString id_temp,name_temp,disease_temp,position_temp,all_time_temp;
        int  power_temp, freq_temp,pulse_num_oneT_temp,rest_time_temp,T_num_temp,all_pulse_num_temp;

        inp >> id_temp >> name_temp >> disease_temp >> position_temp >> power_temp\
                >> freq_temp >> pulse_num_oneT_temp >> rest_time_temp >> T_num_temp >> all_time_temp >> all_pulse_num_temp;
        allSchemeInfo.push_back(SchemeInfo(id_temp , name_temp , disease_temp , position_temp , power_temp\
                                           , freq_temp , pulse_num_oneT_temp , rest_time_temp , T_num_temp , all_time_temp , all_pulse_num_temp));

        //调用之前声明的构造函数实例化一个SchemeInfo对象并将其加入allSchemeInfo
    }
    allSchemeInfo.pop_back();

    //扔掉最后的无用数据
    file.close();
    //关闭文件

    bool flag = false;
        for(auto i : allSchemeInfo){
            if(i.getId() == id){
                flag = true;
                break;
            }
        }
        if(flag){
           QMessageBox::about(NULL, "错误", "该方案Id已经存在");
           return;
        }

    //完成判断，不存在重复的Id，可以新建档案

    file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append);
    if(!file.isOpen()){ //如果数据文件没有打开，弹出对话框提示用户
            QMessageBox::about(NULL, "错误", "方案信息文件打开失败");
            return;
        }
    QTextStream out(&file);
        //QTextStream可以进行一些基本的文本读写，比如QString int char之类的数据QDataStream可以进行一个如QMap QPoint之类数据的读写。
        out <<id<<" "<<name<<" "<<disease<<" "<<position<<" "<<power<<" "<<freq<<" "\
           <<pulse_num_oneT<<" "<<rest_time<<" "<<T_num<<" "<<all_time<<" "<<all_pulse_num<<endl;
    file.close();
    TipsDlg dlg(TipsType_Ok, name+" 新建方案成功", this->topLevelWidget());
    dlg.setAttribute(Qt::WA_ShowModal, true);
    dlg.startTimer();
    dlg.exec();

    ui->nameLineEdit->clear();
    ui->idLineEdit->clear();
    ui->diseaseEdit->clear();
    ui->positionEdit->clear();
    ui->powerEdit->clear();
    ui->freqEdit->clear();
    ui->pulse_num_oneTEdit->clear();
    ui->rest_timeEdit->clear();
    ui->T_numEdit->clear();

}

void Addmode::on_returnButton_clicked()
{
    emit display(0);

}
