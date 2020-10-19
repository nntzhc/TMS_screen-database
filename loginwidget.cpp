#include "loginwidget.h"
#include "ui_loginwidget.h"
#include "mainwidget.h"
#include "tipsdlg.h"

//全局变量
extern QString now_user_name;
extern int now_user_id;

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
    now_user_id= ui->idLineEdit->text().toInt();

    SqliteDBAOperator sqlite;
    sqlite.OpenDb();

    if(ui->idLineEdit->text()=="")/*and(now_user_name=="")*/{ //如果id未输入，进行提醒
        QMessageBox::about(NULL, "错误", "ID未输入");
        return;
    }
    else{
            QString p_id=QString("p")+QString::number(now_user_id);
            if(!sqlite.IsTaBexists(p_id))
            {
                QMessageBox::about(NULL, "提示", "用户未注册");
                now_user_name="";
                now_user_id=0;
                return ;
            }
            else
            {

                TipsDlg dlg(TipsType_Ok, QString::number(now_user_id)+now_user_name+" 登陆成功", this->topLevelWidget());
                dlg.setAttribute(Qt::WA_ShowModal, true);
                dlg.startTimer();
                dlg.exec();
                emit display(0);

                return ;
                }
            }
}

