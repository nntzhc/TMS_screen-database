#include "allpatients.h"
#include "ui_allpatients.h"
#include "dbPage.h"
#include "mainwidget.h"

void AllPatients::initForm()
{
    columnNames.clear();
    columnWidths.clear();

    tableName = QString("patients");//LogInfo
    countName = "rowid";


    columnNames.append("编号");
    columnNames.append("姓名");
    columnNames.append("性别");
    columnNames.append("年龄");
    columnNames.append("备用");

    columnWidths.append(70);
    columnWidths.append(70);
    columnWidths.append(70);
    columnWidths.append(70);
    columnWidths.append(70);

    //设置需要显示数据的表格和翻页的按钮
    dbPage2 = new DbPage(this);
    //设置所有列居中显示
    dbPage2->setAllCenter(true);
    dbPage2->setControl(ui->tableMain, ui->labPageCount, ui->labPageCurrent, ui->labResultCount, ui->labResultCurrent, ui->labResult, 0,
                       ui->btnFirst, ui->btnPre, ui->btnNext, ui->btnLast, countName);
    ui->tableMain->horizontalHeader()->setStretchLastSection(true);
    ui->tableMain->verticalHeader()->setDefaultSectionSize(25);

}

void AllPatients::initTable()
{
    //打开数据库,整个应用程序可用
    QSqlDatabase dbConn = QSqlDatabase::addDatabase("QSQLITE");
    dbConn.setDatabaseName(qApp->applicationDirPath() + "/Database.db");

    if (dbConn.open()) {
        qDebug() << "连接数据库成功!";
    } else {
        qDebug() << "连接数据库失败!in allpatients";
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

AllPatients::AllPatients(QWidget *parent) : QWidget(parent), ui(new Ui::AllPatients)
{
    ui->setupUi(this);
    this->initForm();
    this->initTable();
}

AllPatients::~AllPatients()
{
    delete ui;
}

void AllPatients::on_btnSelect_clicked()
{
    ui->labResult->setText("正在查询...");
    //绑定数据到表格
    QString sql;
    if(ui->searchEdit->text()==""){
        sql = "where 1=1";
    }
    else{
        QString c=ui->searchEdit->text();
        if(c >='0' && c<='9'){
            sql = "where id="+ui->searchEdit->text();
        }
        else{
            sql = "where name='"+ui->searchEdit->text()+"'";
        }

    }

    dbPage2->setTableName(tableName);
    dbPage2->setOrderSql(QString("%1 %2").arg(countName).arg("asc"));
    dbPage2->setWhereSql(sql);
    dbPage2->setResultCurrent(20);
    dbPage2->setColumnNames(columnNames);
    dbPage2->setColumnWidths(columnWidths);
    dbPage2->select();
}

void AllPatients::on_btnReturn_clicked()
{
    emit display(0);
}

void AllPatients::on_searchEdit_textChanged(const QString &arg1)
{
    if(arg1!=""){
        ui->btnSelect->setText("查询");
    }
}
