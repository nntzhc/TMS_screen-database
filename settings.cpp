#include "settings.h"
#include "ui_settings.h"
#include "tipsdlg.h"
#include "dbPage.h"
#include "mainwidget.h"

int Threshold_Default;
int Noticetime_Default;
int Dirlogin_Default;

Settings::Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);

    QFile file("settings.txt");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    if(!file.isOpen()){ //如果数据文件没有打开，恢复到默认值
        Threshold_Default=100;
        Noticetime_Default=1;
        Dirlogin_Default=1;
        }
    else{
        QTextStream inp(&file);
        while(!inp.atEnd()){    //读到文件结尾
            inp >> Threshold_Default >> Noticetime_Default >> Dirlogin_Default ;
            }
        file.close();
    }
    ui->thresdefauEdit->setText(QString::number(Threshold_Default));
    ui->noticetimeEdit->setText(QString::number(Noticetime_Default));
    ui->dirloginchk->setChecked(Dirlogin_Default);

}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_returnButton_clicked()
{
    emit display(0);
}

void Settings::on_saveButton_clicked()
{
    Threshold_Default=ui->thresdefauEdit->text().toInt();
    Noticetime_Default=ui->noticetimeEdit->text().toInt();
    if(ui->dirloginchk->checkState()){
        Dirlogin_Default=1;
    }
    else{
        Dirlogin_Default=0;
    }

    QFile file("settings.txt");
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream out(&file);
    out << Threshold_Default << " " << Noticetime_Default << " " << Dirlogin_Default ;
    file.close();
    ui->thresdefauEdit->setText(QString::number(Threshold_Default));
    ui->noticetimeEdit->setText(QString::number(Noticetime_Default));
    ui->dirloginchk->setChecked(Dirlogin_Default);

    TipsDlg dlg(TipsType_Ok, "已保存设置", this->topLevelWidget());
    dlg.setAttribute(Qt::WA_ShowModal, true);
    dlg.startTimer();
    dlg.exec();
}

void Settings::on_DefaultButton_clicked()
{
    Threshold_Default=100;
    Noticetime_Default=1;
    Dirlogin_Default=1;

    ui->thresdefauEdit->setText(QString::number(Threshold_Default));
    ui->noticetimeEdit->setText(QString::number(Noticetime_Default));
    ui->dirloginchk->setChecked(Dirlogin_Default);

    TipsDlg dlg(TipsType_Ok, "已恢复默认值", this->topLevelWidget());
    dlg.setAttribute(Qt::WA_ShowModal, true);
    dlg.startTimer();
    dlg.exec();

}

void Settings::on_clchisButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "提示", "确定要清除历史记录吗?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        QSqlDatabase dbConn = QSqlDatabase::addDatabase("QSQLITE");
        dbConn.setDatabaseName(qApp->applicationDirPath() + "/Database.db");

        if (dbConn.open()) {
            qDebug() << "连接数据库成功!";
        } else {
            qDebug() << "连接数据库失败!in allpatients";
        }

        QSqlQuery qryview;
        qryview.exec("delete from history");
//      QApplication::quit();
      return;
    } else {
      qDebug() << "Yes was *not* clicked";
    }

}

void Settings::on_clcfileButton_clicked()
{
    if(now_user_id==0){
        QMessageBox::about(NULL, "错误", "未登录");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "提示", "确定要清除历史记录吗?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        QSqlDatabase dbConn = QSqlDatabase::addDatabase("QSQLITE");
        dbConn.setDatabaseName(qApp->applicationDirPath() + "/Database.db");

        if (dbConn.open()) {
            qDebug() << "连接数据库成功!";
        } else {
            qDebug() << "连接数据库失败!in allpatients";
        }

        QSqlQuery qryview;
        QString text="delete from p"+QString::number(now_user_id);
        qryview.exec(text);
    }
    else{
        qDebug() << "Yes was *not* clicked";
    }
}

void Settings::someSlot() {

}
