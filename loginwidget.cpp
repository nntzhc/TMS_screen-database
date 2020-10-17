#include "loginwidget.h"
#include "ui_loginwidget.h"
#include "mainwidget.h"
#include "tipsdlg.h"

//全局变量
extern QString now_user_name;
extern QString now_user_id;

LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWidget)
{
    ui->setupUi(this);
}

LoginWidget::~LoginWidget()
{
    delete ui;
}
void LoginWidget::on_returnButton_clicked(){
    emit display(0);
}

void LoginWidget::on_signupButton_clicked()
{
    emit display(5);
}

void LoginWidget::on_nameLineEdit_editingFinished()
{


}

void LoginWidget::on_idLineEdit_editingFinished()
{

}

void LoginWidget::on_loginButton_clicked()
{
    now_user_name = ui->nameLineEdit->text();
    now_user_id=ui->idLineEdit->text();

    if((now_user_id==0)/*and(now_user_name=="")*/){ //如果id未输入，进行提醒
        QMessageBox::about(NULL, "错误", "ID未输入");
        return;
    }
    else{
            QFile file(now_user_id+".txt");
            file.open(QIODevice::ReadOnly|QIODevice::Text);
            //以只读方式打开文本文件student.txt
            QTextStream inp(&file);
            if(!file.isOpen()){ //文件打开失败
                QMessageBox::about(NULL, "提示", "用户未注册");
                return ;
            }
            else{
                TipsDlg dlg(TipsType_Ok, now_user_id+" 登陆成功", this->topLevelWidget());
                dlg.setAttribute(Qt::WA_ShowModal, true);
                dlg.startTimer();
                dlg.exec();
                emit display(0);

                return ;
            }
    }
}
