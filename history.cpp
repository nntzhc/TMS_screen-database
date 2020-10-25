#include "history.h"
#include "ui_history.h"
#include "dbPage.h"
#include "mainwidget.h"

void History::initForm()
{
    columnNames.clear();
    columnWidths.clear();

    tableName = QString("history");//LogInfo
    countName = "rowid";


    columnNames.append("编号");
    columnNames.append("姓名");
    columnNames.append("方案名");
    columnNames.append("刺激位置");
    columnNames.append("强度");

    columnNames.append("阈值");
    columnNames.append("频率");
    columnNames.append("单轮脉冲数");
    columnNames.append("间歇时间");
    columnNames.append("轮数");

    columnNames.append("总脉冲数");
    columnNames.append("总时间m:s");

    columnWidths.append(50);
    columnWidths.append(50);
    columnWidths.append(50);
    columnWidths.append(80);
    columnWidths.append(50);

    columnWidths.append(50);
    columnWidths.append(50);
    columnWidths.append(80);
    columnWidths.append(80);
    columnWidths.append(50);

    columnWidths.append(80);
    columnWidths.append(80);

    //设置需要显示数据的表格和翻页的按钮
    dbPage2 = new DbPage(this);
    //设置所有列居中显示
    dbPage2->setAllCenter(true);
    dbPage2->setControl(ui->tableMain, ui->labPageCount, ui->labPageCurrent, ui->labResultCount, ui->labResultCurrent, ui->labResult, 0,
                       ui->btnFirst, ui->btnPre, ui->btnNext, ui->btnLast, countName);
    ui->tableMain->horizontalHeader()->setStretchLastSection(true);
    ui->tableMain->verticalHeader()->setDefaultSectionSize(25);

}

void History::initTable()
{
    //打开数据库,整个应用程序可用
    QSqlDatabase dbConn = QSqlDatabase::addDatabase("QSQLITE");
    dbConn.setDatabaseName(qApp->applicationDirPath() + "/Database.db");

    if (dbConn.open()) {
        qDebug() << "连接数据库成功!";
    } else {
        qDebug() << "连接数据库失败!in history";
    }
    ui->labResult->setText("正在查询...");

    //绑定数据到表格
    QString sql = "where 1=1";
    dbPage2->setTableName(tableName);
    dbPage2->setOrderSql(QString("%1 %2").arg(countName).arg("asc"));
    dbPage2->setWhereSql(sql);
    dbPage2->setResultCurrent(20);
    dbPage2->setColumnNames(columnNames);
    dbPage2->setColumnWidths(columnWidths);
    dbPage2->select();
}

History::History(QWidget *parent) : QWidget(parent), ui(new Ui::History)
{
    ui->setupUi(this);
    this->initForm();
    this->initTable();
}

History::~History()
{
    delete ui;
}

void History::on_btnSelect_clicked()
{
    ui->labResult->setText("正在查询...");
    //绑定数据到表格
    QString sql;
    sql = "where 1=1";

    dbPage2->setTableName(tableName);
    dbPage2->setOrderSql(QString("%1 %2").arg(countName).arg("asc"));
    dbPage2->setWhereSql(sql);
    dbPage2->setResultCurrent(20);
    dbPage2->setColumnNames(columnNames);
    dbPage2->setColumnWidths(columnWidths);
    dbPage2->select();
}


void History::on_btnReturn_clicked()
{
    emit display(0);
}
