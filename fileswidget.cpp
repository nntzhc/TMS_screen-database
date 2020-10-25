#include "fileswidget.h"
#include "ui_fileswidget.h"
#include "dbPage.h"
#include "mainwidget.h"

//**********************************************************************************
//这个函数是在login界面中登录，id改变的槽函数，用这种方法使得fileswidget界面不会在id未输入的条件下加载
//**********************************************************************************

void FilesWidget::initForm()
{
    //**********************************************************************************
    //这里是为了建立一个病人的简短的信息标签
    //**********************************************************************************

    QSqlDatabase dbConn;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      dbConn = QSqlDatabase::database("qt_sql_default_connection");
    else
      dbConn = QSqlDatabase::addDatabase("QSQLITE");
    dbConn.setDatabaseName(qApp->applicationDirPath() + "/Database.db");

    if (dbConn.open()) {
        qDebug() << "连接数据库成功!";
    } else {
        qDebug() << "连接数据库失败!in fileswidget";
    }

    QSqlQuery qryview;
    qryview.first();
    qryview.exec("SELECT * FROM patients where id="+QString::number(now_user_id));
    QString gender_temp;
    int age_temp;
    int times_temp;

    while(qryview.next()) {
        now_user_name = qryview.value(1).toString();
        gender_temp = qryview.value(2).toString();
        age_temp = qryview.value(3).toInt();
        times_temp = qryview.value(4).toInt();
    }

    QString text;
    text="编号:"+QString::number(now_user_id)+"\n"+\
         "姓名:"+now_user_name+"\n"+\
         "性别:"+gender_temp+"\n"+\
         "年龄:"+QString::number(age_temp)+"\n"+\
         "治疗次数:"+QString::number(times_temp);
    ui->infolabel->setText(text);

    //**********************************************************************************
    //将这次登陆的病人写入logs.txt，使得下次登陆的时候可以选择上次登录按钮一键登录
    //**********************************************************************************

    QFile file("logs.txt");
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream out(&file);
    out << now_user_id << " " << now_user_name;
    file.close();

    //**********************************************************************************
    //建立表格
    //**********************************************************************************

    columnNames.clear();
    columnWidths.clear();

    tableName = QString("p")+QString::number(now_user_id);//LogInfo
    countName = "rowid";

    columnNames.append("方案名");
    columnNames.append("位置");
    columnNames.append("强度");
    columnNames.append("阈值");
    columnNames.append("频率");

    columnNames.append("单轮脉冲数");
    columnNames.append("间歇时间");
    columnNames.append("轮数");
    columnNames.append("总脉冲数");
    columnNames.append("总时间");
    columnNames.append("操作");


    columnWidths.append(50);
    columnWidths.append(50);
    columnWidths.append(50);
    columnWidths.append(50);
    columnWidths.append(50);

    columnWidths.append(50);
    columnWidths.append(50);
    columnWidths.append(50);
    columnWidths.append(50);
    columnWidths.append(50);

    columnWidths.append(50);



    //设置需要显示数据的表格和翻页的按钮
    dbPage1 = new DbPage(this);
    //设置所有列居中显示
    dbPage1->setAllCenter(true);
    dbPage1->setControl(ui->tableMain, ui->labPageCount, ui->labPageCurrent, ui->labResultCount, ui->labResultCurrent, ui->labResult, 0,
                       ui->btnFirst, ui->btnPre, ui->btnNext, ui->btnLast, countName);
    ui->tableMain->horizontalHeader()->setStretchLastSection(true);
    ui->tableMain->verticalHeader()->setDefaultSectionSize(25);

}

void FilesWidget::initTable()
{

    ui->labResult->setText("正在查询...");

    //绑定数据到表格
    QString sql = "where 1=1";
    dbPage1->setTableName(tableName);
    dbPage1->setOrderSql(QString("%1 %2").arg(countName).arg("asc"));
    dbPage1->setWhereSql(sql);
    dbPage1->setResultCurrent(20);
    dbPage1->setColumnNames(columnNames);
    dbPage1->setColumnWidths(columnWidths);
    dbPage1->select();
}

FilesWidget::FilesWidget(QWidget *parent) : QWidget(parent), ui(new Ui::FilesWidget)
{
    ui->setupUi(this);
//    this->initForm();

}

FilesWidget::~FilesWidget()
{
    delete ui;
}

void FilesWidget::on_btnSelect_clicked()
{
    ui->labResult->setText("正在查询...");

    //绑定数据到表格
    QString sql = "where 1=1";
    dbPage1->setTableName(tableName);
    dbPage1->setOrderSql(QString("%1 %2").arg(countName).arg("asc"));
    dbPage1->setWhereSql(sql);
    dbPage1->setResultCurrent(20);
    dbPage1->setColumnNames(columnNames);
    dbPage1->setColumnWidths(columnWidths);
    dbPage1->select();
}

void FilesWidget::on_btnReturn_clicked()
{
    emit display(0);
}

void FilesWidget::on_allpatientsButton_clicked()
{
    emit display(10);
}


void FilesWidget::on_testButton_clicked()
{
    qDebug()<<dbPage1->queryModel->record(1).value("power").toString();//(dbPage1->pageCurrent-1)*dbPage1->resultCurrent+
}
