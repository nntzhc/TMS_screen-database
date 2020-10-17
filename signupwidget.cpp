#include "signupwidget.h"
#include "ui_signupwidget.h"
#include "tipsdlg.h"

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

    QString id = ui->idLineEdit->text();
    //将用户输入的学号由idLineEdit取出，并转换为整型

    QFile file_(id+".txt");
    file_.open(QIODevice::ReadOnly|QIODevice::Text);
    if(file_.isOpen()){
        QMessageBox::about(NULL, "错误", "用户已经注册");
        return ;
    }

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
    QFile file1("patient.txt");
    QFile file(ui->idLineEdit->text()+".txt");
    //实例化一个QFile file为我们的数据文件Patient.txt
    file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append);
    file1.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append);
    //open()可以用来打开文件这里QIODevice::WriteOnly代表将文件以只写的方式打开
    //QIODevice::Text代表我们打开的是文本文件，QIODevice::Text会对end-of-line结束符进行转译
    //QIODevice::Append以追加的方式打开，新增加的内容将被追加到文件末尾
    if((!file.isOpen())||(!file1.isOpen())){ //如果数据文件没有打开，弹出对话框提示用户
        QMessageBox::about(NULL, "错误", "数据文件打开失败");
        return;
    }
    QTextStream out(&file);
    //QTextStream可以进行一些基本的文本读写，比如QString int char之类的数据QDataStream可以进行一个如QMap QPoint之类数据的读写。
    out << name << " " <<  id << " " << gender << " " << age << " " << times << endl;
    //将我们刚刚获取的数据写入文件
    file.close();
    QTextStream out1(&file1);
    //QTextStream可以进行一些基本的文本读写，比如QString int char之类的数据QDataStream可以进行一个如QMap QPoint之类数据的读写。
    out1 << name << " " <<  id << " " << gender << " " << age << " " << times << endl;
    //将我们刚刚获取的数据写入文件
    file1.close();

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
