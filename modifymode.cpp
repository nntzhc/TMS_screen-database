#include "modifymode.h"
#include "ui_modifymode.h"
#include "dbpage.h"

ModifyMode::ModifyMode(QWidget *parent) : QWidget(parent), ui(new Ui::ModifyMode)
{
    ui->setupUi(this);
    this->initForm();
    //打开数据库
    QSqlDatabase dbConn = QSqlDatabase::addDatabase("QSQLITE");
    dbConn.setDatabaseName(qApp->applicationDirPath() + "/Database.db");
    if (dbConn.open()) {
        qDebug() << "连接数据库成功!";
    } else {
        qDebug() << "连接数据库失败!";
    }
    ui->labResult->setText("正在查询...");

    //绑定数据到表格
    QString sql = "where 1=1";
    dbPage->setTableName(tableName);
    dbPage->setOrderSql(QString("%1 %2").arg(countName).arg("asc"));
    dbPage->setWhereSql(sql);
    dbPage->setResultCurrent(20);
    dbPage->setColumnNames(columnNames);
    dbPage->setColumnWidths(columnWidths);
    dbPage->select();
}

ModifyMode::~ModifyMode()
{
    delete ui;
}

void ModifyMode::initForm()
{
    columnNames.clear();
    columnWidths.clear();

    tableName = "schemes";//LogInfo
    countName = "rowid";

    columnNames.append("编号");
    columnNames.append("方案名");
    columnNames.append("适应症");
    columnNames.append("刺激位置");
    columnNames.append("强度");

    columnNames.append("阈值");
    columnNames.append("频率");
    columnNames.append("单轮脉冲数");
    columnNames.append("间歇时间");
    columnNames.append("轮数");

    columnNames.append("总脉冲数");
    columnNames.append("总时间m:s");

    columnWidths.append(70);
    columnWidths.append(120);
    columnWidths.append(120);
    columnWidths.append(120);
    columnWidths.append(70);

    columnWidths.append(70);
    columnWidths.append(70);
    columnWidths.append(120);
    columnWidths.append(120);
    columnWidths.append(70);

    columnWidths.append(120);
    columnWidths.append(120);

    //设置需要显示数据的表格和翻页的按钮
    dbPage = new DbPage(this);
    //设置所有列居中显示
    dbPage->setAllCenter(true);
    dbPage->setControl(ui->tableMain, ui->labPageCount, ui->labPageCurrent, ui->labResultCount, ui->labResultCurrent, ui->labResult, 0,
                       ui->btnFirst, ui->btnPre, ui->btnNext, ui->btnLast, countName);
    ui->tableMain->horizontalHeader()->setStretchLastSection(true);
    ui->tableMain->verticalHeader()->setDefaultSectionSize(25);
}

void ModifyMode::on_btnSelect_clicked()
{
    ui->labResult->setText("正在查询...");

    //绑定数据到表格
    QString sql = "where 1=1";
    dbPage->setTableName(tableName);
    dbPage->setOrderSql(QString("%1 %2").arg(countName).arg("asc"));
    dbPage->setWhereSql(sql);
    dbPage->setResultCurrent(20);
    dbPage->setColumnNames(columnNames);
    dbPage->setColumnWidths(columnWidths);
    dbPage->select();
}

void ModifyMode::on_btnReturn_clicked()
{
    emit display(2);
}

void ModifyMode::on_btnReturn_2_clicked()
{
    emit display(0);
}

void ModifyMode::on_btnAddMode_clicked()
{
    emit display(9);
}
