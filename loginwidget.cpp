#include "loginwidget.h"
#include "ui_loginwidget.h"
#include "mainwidget.h"
#include "tipsdlg.h"

//全局变量
extern QString now_user_name;
extern int now_user_id;
int now_user_id_temp=0;
QString now_user_name_temp=QString(" ");

void LoginWidget::lastloginbutton_alter()
{
    QString text = "快捷登录: 编号:"+QString::number(now_user_id_temp)+" 姓名:"+now_user_name_temp;
    ui->lastloginButton->setText(text);
    ui->lastloginButton->setVisible(true);
}

LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWidget)
{
    ui->setupUi(this);
    ui->lastloginButton->setVisible(false);

    QFile file("logs.txt");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
        QTextStream inp(&file);
    while(!inp.atEnd()){    //读到文件结尾
        inp >> now_user_id_temp >> now_user_name_temp ;
        }

    if(now_user_id_temp!=0){
        lastloginbutton_alter();
    }
    else{
        now_user_name=" ";
    }
    file.close();
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

void LoginWidget::on_loginButton_clicked()
{
    now_user_name = ui->nameLineEdit->text();
    now_user_id= ui->idLineEdit->text().toInt();

    SqliteDBAOperator sqlite;
    sqlite.OpenDb();

    if(ui->idLineEdit->text()==""){ //如果id未输入，进行提醒
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

            TipsDlg dlg(TipsType_Ok, QString::number(now_user_id)+" "+now_user_name+" 登陆成功", this->topLevelWidget());
            dlg.setAttribute(Qt::WA_ShowModal, true);
            dlg.startTimer();
            dlg.exec();

            emit display(0);
            emit idchange(now_user_id);

            }
        }
}


void LoginWidget::on_logoffButton_clicked()
{
    now_user_id=0;
    ui->idLineEdit->clear();
    ui->nameLineEdit->clear();
    TipsDlg dlg(TipsType_Ok, "已注销", this->topLevelWidget());
    dlg.setAttribute(Qt::WA_ShowModal, true);
    dlg.startTimer();
    dlg.exec();
}

void LoginWidget::on_lastloginButton_clicked()
{
    now_user_id=now_user_id_temp;
    TipsDlg dlg(TipsType_Ok, QString::number(now_user_id)+" "+now_user_name+" 登陆成功", this->topLevelWidget());
    dlg.setAttribute(Qt::WA_ShowModal, true);
    dlg.startTimer();
    dlg.exec();

    emit display(0);
    emit idchange(now_user_id);
}
