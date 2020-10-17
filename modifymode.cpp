#include "modifymode.h"
#include "ui_modifymode.h"
#include <algorithm>

bool getSchemeInfo(QVector<SchemeInfo> &allSchemeInfo){  //读取信息成功返回true 否则返回false
    QFile file("Schemes.txt");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    //以只读方式打开文本文件Schemes.txt

     QTextStream inp(&file);
    if(!file.isOpen()){ //文件打开失败
        QMessageBox::about(NULL, "反馈", "数据文件打开失败");
        return false;
    }
    while(!inp.atEnd()){    //读到文件结尾

        QString name,disease,position,all_time;
        int  id,power, freq,pulse_num_oneT,rest_time,T_num,all_pulse_num;

        inp >> id >> name >> disease >> position >> power\
                >> freq >> pulse_num_oneT >> rest_time >> T_num >> all_time >> all_pulse_num;
        allSchemeInfo.push_back(SchemeInfo(id , name , disease , position , power\
                                           , freq , pulse_num_oneT , rest_time , T_num , all_time , all_pulse_num));

        //调用之前声明的构造函数实例化一个SchemeInfo对象并将其加入allSchemeInfo
    }
    allSchemeInfo.pop_back();

    //扔掉最后的无用数据
    file.close();
    //关闭文件
    return true;
}


ModifyMode::ModifyMode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModifyMode)
{
    ui->setupUi(this);


    ui->tableWidget->setColumnCount(11);
    QStringList headerLabels;
    //QStringList headerLabels用来记录表格表头数据
    headerLabels << tr("编号") << tr("方案名") << tr("适应症") << tr("位置")<< tr("功率")\
                 << tr("频率") << tr("单轮脉冲数") << tr("间歇时间") << tr("轮数") << tr("总时间") << tr("总脉冲数") ;
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
//    void setHorizontalHeaderLabels(const QStringList &labels);设置水平表头标签
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //设置根据总宽度调整列宽
    ui->tableWidget->setRowCount(1);
    //初始行数设为一行

    ui->tableWidget->clearContents();
    //清空除表头外的所有数据
    //若想清除表头可使用clear()

    QVector<SchemeInfo> allSchemeInfo;
    //数据类型为SchemeInfo的QVector容器
    if(!getSchemeInfo(allSchemeInfo)) //从文件读取数据到allSchemeInfo
        return; //读取失败直接返回
    if(allSchemeInfo.empty()){ //allSchemeInfo中没有数据
        QMessageBox::about(NULL, "错误", "没有信息");
        return;
    }

    ui->tableWidget->setRowCount(allSchemeInfo.size());
    //将表格的行数设为与学生数量相同
    //否则setItem添加单元格不会生效

    for(int i = 0; i < allSchemeInfo.size(); i++){
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(allSchemeInfo[i].getId())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(allSchemeInfo[i].getName()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(allSchemeInfo[i].getDisease()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(allSchemeInfo[i].getPosition()));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(allSchemeInfo[i].getPower())));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(allSchemeInfo[i].getFreq())));
        ui->tableWidget->setItem(i, 6, new QTableWidgetItem(QString::number(allSchemeInfo[i].getPulse_num_oneT())));
        ui->tableWidget->setItem(i, 7, new QTableWidgetItem(QString::number(allSchemeInfo[i].getRest_time())));
        ui->tableWidget->setItem(i, 8, new QTableWidgetItem(QString::number(allSchemeInfo[i].getT_num())));
        ui->tableWidget->setItem(i, 9, new QTableWidgetItem(allSchemeInfo[i].getAll_time()));
        ui->tableWidget->setItem(i, 10, new QTableWidgetItem(QString::number(allSchemeInfo[i].getAll_pulse_num())));

        //设置各单元格的数据，非QString类型的数据需要转换为QString
    }

}




ModifyMode::~ModifyMode()
{
    delete ui;
}



void ModifyMode::on_returnButton_clicked()
{
    emit display(0);
}

void ModifyMode::on_addschButton_clicked()
{
    emit display(9);
}

void ModifyMode::on_refreshButton_clicked()
{

    ui->tableWidget->clearContents();
    //清空除表头外的所有数据
    //若想清除表头可使用clear()

    QVector<SchemeInfo> allSchemeInfo;
    //数据类型为SchemeInfo的QVector容器
    if(!getSchemeInfo(allSchemeInfo)) //从文件读取数据到allSchemeInfo
        return; //读取失败直接返回
    if(allSchemeInfo.empty()){ //allSchemeInfo中没有数据
        QMessageBox::about(NULL, "错误", "没有信息");
        return;
    }

    ui->tableWidget->setRowCount(allSchemeInfo.size());
    //将表格的行数设为与学生数量相同
    //否则setItem添加单元格不会生效

    for(int i = 0; i < allSchemeInfo.size(); i++){
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(allSchemeInfo[i].getId())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(allSchemeInfo[i].getName()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(allSchemeInfo[i].getDisease()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(allSchemeInfo[i].getPosition()));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(allSchemeInfo[i].getPower())));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(allSchemeInfo[i].getFreq())));
        ui->tableWidget->setItem(i, 6, new QTableWidgetItem(QString::number(allSchemeInfo[i].getPulse_num_oneT())));
        ui->tableWidget->setItem(i, 7, new QTableWidgetItem(QString::number(allSchemeInfo[i].getRest_time())));
        ui->tableWidget->setItem(i, 8, new QTableWidgetItem(QString::number(allSchemeInfo[i].getT_num())));
        ui->tableWidget->setItem(i, 9, new QTableWidgetItem(allSchemeInfo[i].getAll_time()));
        ui->tableWidget->setItem(i, 10, new QTableWidgetItem(QString::number(allSchemeInfo[i].getAll_pulse_num())));

        //设置各单元格的数据，非QString类型的数据需要转换为QString
    }
}
