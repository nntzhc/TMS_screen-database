#ifndef SQLITEDBAOPERATOR_H
#define SQLITEDBAOPERATOR_H

#include "patientinfo.h"
#include "schemeinfo.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>
class SqliteDBAOperator
{
public:
    SqliteDBAOperator();
    ~SqliteDBAOperator();
public:
    //创建数据库并建立连接
    bool OpenDb(void);
    //创建数据表（student）
//    void createTable(void);
    //在表格中增加新的字段
    void addNewcolumn(QString &columnNameAndproperty);
    //查询和显示结果
    bool execute(QString& str);
    //判断数据表是否存在
    bool IsTaBexists(QString& Tabname);
    //插入数据
    bool SigUserInsert(PatientInfo singledb);//插入单条数据
    bool SigScheInsert(SchemeInfo singledb);
//    void MulUserInsert(QList<PatientInfo> &moredb);//插入多条数据
    //删除数据
    void deletedata();
    //修改数据
    void updatedata();
    //关闭数据库
    void closeDb(void);
private:
    QSqlDatabase db;//用于建立和数据库的连接
};



#endif // SQLITEDBAOPERATOR_H
