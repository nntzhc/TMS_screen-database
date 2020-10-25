#ifndef AllPatients_H
#define AllPatients_H

#include <QWidget>

class DbPage;

namespace Ui {
class AllPatients;
}

class AllPatients : public QWidget
{
    Q_OBJECT

public:
    explicit AllPatients(QWidget *parent = 0);
    ~AllPatients();
 

private:
    Ui::AllPatients *ui;

    QList<QString> columnNames; //字段名集合
    QList<int> columnWidths;    //字段宽度集合
    DbPage *dbPage2;             //数据库翻页类

    QString tableName;          //表名称
    QString countName;          //统计行数字段名称

signals:
    void display(int number);

public slots:
    void initForm();
    void initTable();

private slots:
    void on_btnSelect_clicked();
    void on_btnReturn_clicked();

    void on_searchEdit_textChanged(const QString &arg1);
};

#endif // AllPatients_H
