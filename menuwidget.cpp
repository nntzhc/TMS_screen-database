#include "menuwidget.h"
#include "ui_menuwidget.h"
#include "mainwidget.h"
#include <QDebug>

extern int now_user_id;

MenuWidget::MenuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuWidget)
{
    ui->setupUi(this);
}

MenuWidget::~MenuWidget()
{
    delete ui;
}

void MenuWidget::on_addButton_clicked(){
    emit display(1);
}

void MenuWidget::on_modeselectButton_clicked(){
    emit display(2);
}

void MenuWidget::on_filesButton_clicked(){
    if(now_user_id==0){
        emit display(10);
        qDebug() <<"id未填写";
    }
    else{
        qDebug()<<"now_user_id:  "+QString::number(now_user_id);
        emit display(3);
    }
}

void MenuWidget::on_settingsButton_clicked(){
    emit display(4);
}

void MenuWidget::on_historyButton_clicked(){
    emit display(11);
//    QApplication::exit();
}
