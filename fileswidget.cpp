#include "fileswidget.h"
#include "ui_fileswidget.h"
#include <algorithm>

extern QString now_user_name;
extern QString now_user_id;

bool getPatientInfo(QVector<PatientInfo> &allPatientInfo){  //读取信息成功返回true 否则返回false
    QFile file("patient.txt");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    //以只读方式打开文本文件Patient.txt

     QTextStream inp(&file);
    if(!file.isOpen()){ //文件打开失败
        QMessageBox::about(NULL, "反馈", "数据文件打开失败");
        return false;
    }
    while(!inp.atEnd()){    //读到文件结尾
        QString id,name,gender;
        int  age, times;
        inp >> name >> id >>gender>> age >> times;
        allPatientInfo.push_back(PatientInfo(name, id,gender, age, times));//这一句会出问题

        //调用之前声明的构造函数实例化一个PatientInfo对象并将其加入allPatientInfo
    }

    allPatientInfo.pop_back();


    //扔掉最后的无用数据
    file.close();
    //关闭文件
    return true;
}

FilesWidget::FilesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FilesWidget)
{
    ui->setupUi(this);



    ui->tableWidget->setColumnCount(5);
    QStringList headerLabels;
    //QStringList headerLabels用来记录表格表头数据
    headerLabels << tr("姓名") << tr("编号") << tr("性别") << tr("次数") << tr("备用");
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
//    void setHorizontalHeaderLabels(const QStringList &labels);设置水平表头标签
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //设置根据总宽度调整列宽
    ui->tableWidget->setRowCount(1);
    //初始行数设为一行

    ui->tableWidget->clearContents();
    //清空除表头外的所有数据
    //若想清除表头可使用clear()

//    while(now_user_id==""){
//        QThread::msleep(1000);
//    }

    QVector<PatientInfo> allPatientInfo;
    //数据类型为PatientInfo的QVector容器
    if(!getPatientInfo(allPatientInfo)) //从文件读取数据到allPatientInfo
        return; //读取失败直接返回
    if(allPatientInfo.empty()){ //allPatientInfo中没有数据
        QMessageBox::about(NULL, "错误", "没有信息");
        return;
    }

    ui->tableWidget->setRowCount(allPatientInfo.size());
    //将表格的行数设为与学生数量相同
    //否则setItem添加单元格不会生效
    for(int i = 0; i < allPatientInfo.size(); i++){
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(allPatientInfo[i].getName()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(allPatientInfo[i].getId()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(allPatientInfo[i].getGender()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(allPatientInfo[i].getage())));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(allPatientInfo[i].gettimes())));

//        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(allPatientInfo[i].getAvg())));
        //设置各单元格的数据，非QString类型的数据需要转换为QString
    }

}

FilesWidget::~FilesWidget()
{
    delete ui;
}

void FilesWidget::on_returnButton_clicked(){
    emit display(0);
}






void FilesWidget::on_refreshButton_clicked()
{
    QVector<PatientInfo> allPatientInfo;
    //数据类型为PatientInfo的QVector容器
    if(!getPatientInfo(allPatientInfo)) //从文件读取数据到allPatientInfo
        return; //读取失败直接返回
    if(allPatientInfo.empty()){ //allPatientInfo中没有数据
        QMessageBox::about(NULL, "错误", "没有信息");
        return;
    }

    ui->tableWidget->setRowCount(allPatientInfo.size());
    //将表格的行数设为与学生数量相同
    //否则setItem添加单元格不会生效
    for(int i = 0; i < allPatientInfo.size(); i++){
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(allPatientInfo[i].getName()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(allPatientInfo[i].getId()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(allPatientInfo[i].getGender()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(allPatientInfo[i].getage())));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(allPatientInfo[i].gettimes())));

//        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(allPatientInfo[i].getAvg())));
        //设置各单元格的数据，非QString类型的数据需要转换为QString
    }
}
