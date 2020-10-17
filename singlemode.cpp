#include "singlemode.h"
#include "ui_singlemode.h"

SingleMode::SingleMode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SingleMode)
{
    ui->setupUi(this);
}

SingleMode::~SingleMode()
{
    delete ui;
}


void SingleMode::on_returnButton_clicked()
{
    emit display(0);
}




void SingleMode::on_startButton_clicked()
{
    //PatientInfo p_info;
    //p_info.id=id;
    //p_info.name=name;
    //p_info.gender=gender;
    //p_info.age=age;
    //p_info.times=times;
    //sqlite.SigUserInsert(p_info);
}
