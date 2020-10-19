#include "fileswidget.h"
#include "ui_fileswidget.h"
#include "dbPage.h"
#include "mainwidget.h"

void FilesWidget::initForm()
{
    columnNames.clear();
    columnWidths.clear();

    tableName = QString("p")+QString::number(now_user_id);//LogInfo
    countName = "rowid";
    qDebug() << "run into "+QString("p")+QString::number(now_user_id);

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

    columnWidths.append(70);
    columnWidths.append(70);
    columnWidths.append(70);
    columnWidths.append(70);
    columnWidths.append(70);

    columnWidths.append(90);
    columnWidths.append(90);
    columnWidths.append(70);
    columnWidths.append(90);
    columnWidths.append(70);


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
    //打开数据库,整个应用程序可用
    QSqlDatabase dbConn = QSqlDatabase::addDatabase("QSQLITE");
    dbConn.setDatabaseName(qApp->applicationDirPath() + "/Database.db");

    if (dbConn.open()) {
        qDebug() << "连接数据库成功!";
    } else {
        qDebug() << "连接数据库失败!in fileswidget";
    }
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
