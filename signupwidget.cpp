#include "signupwidget.h"
#include "ui_signupwidget.h"
#include "tipsdlg.h"
#include "mainwidget.h"


Signupwidget::Signupwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Signupwidget)
{
    ui->setupUi(this);

}

Signupwidget::~Signupwidget()
{
    delete ui;
}


void Signupwidget::on_returnButton_clicked(){   //"主菜单"按钮点击
    emit display(0);
}

void Signupwidget::on_addButton_clicked(){  //"添加"按钮点击

    QString name = ui->nameLineEdit->text();
    //将用户输入的姓名由nameLineEdit取出
    if(name == ""){name="未填写";}

    int id = ui->idLineEdit->text().toInt();
    //将用户输入的学号由idLineEdit取出，并转换为整型

    QString gender = ui->genderLineEdit->text();
    //将用户输入的学号由mathLineEdit取出，并转换为整型
    if(gender == ""){name="未填写";}

    int age = ui->ageLineEdit->text().toInt();
    //将用户输入的学号由enLineEdit取出，并转化为整型
    int times = ui->cLineEdit->text().toInt();
    //将用户输入的学号由cLineEdit取出，并转化为整型
    if(ui->idLineEdit->text() == ""){
        //id不能为空，否则在读取文件时会出现问题。
        QMessageBox::about(NULL, "提示", "未填写id");
    }

    SqliteDBAOperator sqlite;
    sqlite.OpenDb();

    PatientInfo patientinfo;
    patientinfo.id=id;
    patientinfo.name=name;
    patientinfo.gender=gender;
    patientinfo.age=age;
    patientinfo.times=times;
    QString control_str = QString("create table patients (id int primary key NOT NULL UNIQUE, name text,gender text, age int,times int)");
    sqlite.execute(control_str);
    sqlite.SigUserInsert(patientinfo);

    control_str = QString("create table p")+QString::number(id)+QString(" ( name text,position text, power int,threshold int,\
                                                                                    freq int,pulse_num_oneT int,rest_time int,\
                                                                                    T_num int,all_pulse_num int,all_time text)");
    sqlite.execute(control_str);

    TipsDlg dlg(TipsType_Ok, ui->idLineEdit->text()+" "+name+" 注册成功", this->topLevelWidget());
    dlg.setAttribute(Qt::WA_ShowModal, true);
    dlg.startTimer();
    dlg.exec();

    ui->nameLineEdit->clear();
    ui->idLineEdit->clear();
    ui->genderLineEdit->clear();
    ui->ageLineEdit->clear();
    ui->cLineEdit->clear();
    //将用户输入的数据清空
}
