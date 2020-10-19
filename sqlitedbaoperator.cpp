/*Sqlite数据库操作*/

#include "sqlitedbaoperator.h"
#include "patientinfo.h"
#include "schemeinfo.h"
#include <QDir>
#include "tipsdlg.h"
#include "singlemode.h"

SqliteDBAOperator::SqliteDBAOperator()
{

    QSqlDatabase database;
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        //建立和sqlite数据的连接
        db = QSqlDatabase::addDatabase("QSQLITE");
        //设置数据库文件的名字
        QString dbname = QDir::currentPath() +QString("/")+ QString("Database.db");
        db.setDatabaseName(dbname);
    }
}

/*析构函数关闭数据库连接*/
SqliteDBAOperator::~SqliteDBAOperator()
{
    db.close();
}

//打开数据库
bool SqliteDBAOperator::OpenDb(void)
{
    //打开数据库
    if(db.open() == false){
        qDebug() << "连接数据失败！";
        return false;
    }
    qDebug() << "连接数据库成功";
    return true;
}

//判断数据库中某个数据表是否存在
bool SqliteDBAOperator::IsTaBexists(QString& Tabname)
{
    QSqlDatabase db = QSqlDatabase::database();
    if(db.tables().contains(Tabname))
    {
        return true;
    }
    return false;
}


//执行语句
bool SqliteDBAOperator::execute(QString& str)
{
    //用于执行sql语句的对象
    qDebug() << str;
    QSqlQuery query;
    //构建创建数据库的sql语句字符串
    if(!query.exec(str))
        {
            qDebug() << query.lastError();
            return false;

        }
        else
        {
//            qDebug() << pos_mes;
            return true;
        }


}

void SqliteDBAOperator::addNewcolumn(QString& columnNameAndproperty)
{
}


//单条插入病人信息
bool SqliteDBAOperator::SigUserInsert(PatientInfo singledb)
{
    QSqlQuery query;
    QString str=QString("INSERT INTO patients VALUES (:id,:name,:gender,:age,:times)");
    query.prepare(str);

    query.bindValue(":id", singledb.id);
    query.bindValue(":name", singledb.name);
    query.bindValue(":gender",singledb.gender);
    query.bindValue(":age",singledb.age);
    query.bindValue(":times",singledb.times);

    if(!query.exec())
        {
            qDebug() << singledb.id<<singledb.name<<singledb.gender<<singledb.age<<singledb.times;
            qDebug() << query.lastError();
            return false;
        }
        else
        {
            qDebug() << "order executed!";
            return true;
        }
}

//单条插入方案
bool SqliteDBAOperator::SigScheInsert(SchemeInfo singledb)
{
    QSqlQuery query;
    QString str=QString("INSERT INTO schemes VALUES (:id, :name, :disease, \
                        :position, :power, :freq,\
                        :pulse_num_oneT, :rest_time, :T_num,\
                        :all_pulse_num, :all_time)");
    query.prepare(str);

    query.bindValue(":id", singledb.id);
    query.bindValue(":name", singledb.name);
    query.bindValue(":disease",singledb.disease);
    query.bindValue(":position",singledb.position);
    query.bindValue(":power",singledb.power);

    query.bindValue(":freq", singledb.freq);
    query.bindValue(":pulse_num_oneT",singledb.pulse_num_oneT);
    query.bindValue(":rest_time",singledb.rest_time);
    query.bindValue(":T_num",singledb.T_num);
    query.bindValue(":all_pulse_num",singledb.all_pulse_num);

    query.bindValue(":all_time",singledb.all_time);

    if(!query.exec())
        {
            qDebug() << query.lastError();
            return false;
        }
        else
        {
            qDebug() << "order executed!";
            return true;
        }
}

//单条插入档案
bool SqliteDBAOperator::SigFileInsert(SchemeInfo singledb,int id,QString mode)
{
    QSqlQuery query;
    QString str=QString("INSERT INTO p"+QString::number(id)+" VALUES ( \
                        :name, :position, :power, :freq,\
                        :pulse_num_oneT, :rest_time, :T_num,\
                        :all_pulse_num, :all_time)");
    query.prepare(str);

    if (singledb.name.isEmpty()) singledb.name = mode;
    else query.bindValue(":name", singledb.name);
    if (singledb.position.isEmpty()) singledb.position = "";
    else query.bindValue(":position",singledb.position);
    query.bindValue(":power",singledb.power);
    query.bindValue(":freq",singledb.freq);
    query.bindValue(":pulse_num_oneT",singledb.pulse_num_oneT);

    query.bindValue(":rest_time",singledb.rest_time);
    query.bindValue(":T_num",singledb.T_num);
    query.bindValue(":all_pulse_num",singledb.all_pulse_num);
    query.bindValue(":all_time",singledb.all_time);


    if(!query.exec())
        {
            qDebug() << str;
            qDebug() << query.lastError();
            return false;
        }
        else
        {   qDebug() << str;
            qDebug() << "order executed!"<<singledb.name<<singledb.all_time;
            return true;
        }
}

//多条插入
//void SqliteDBAOperator::Moreinsertdata(QList<PatientInfo> &moredb)
//{
//    QSqlQuery query;
//    query.prepare("insert into Database values (?,?,?,?,?)");
//    QVariantList idlist,namelist,genderlist,agelsit,timeslist;
//    for(int i=0; i< moredb.size(); i++)
//    {
//        idlist <<  moredb.at(i).id;
//        namelist << moredb.at(i).name;
//        genderlist << moredb.at(i).gender;
//        agelsit << moredb.at(i).age;
//        timeslist << moredb.at(i).times;
//    }
//    query.addBindValue(idlist);
//    query.addBindValue(namelist);
//    query.addBindValue(genderlist);
//    query.addBindValue(agelsit);
//    query.addBindValue(timeslist);

//    if (!query.execBatch())
//    {
//        qDebug() << query.lastError();
//    }
//}


//删除一条数据
void SqliteDBAOperator::deletedata()
{
    //比较简单，自行补充
}
//修改
void SqliteDBAOperator::updatedata()
{
    //比较简单，自行补充

}


void SqliteDBAOperator::closeDb(void)
{
    db.close();
}

