#ifndef ModifyMode_H
#define ModifyMode_H

#include <QWidget>

class DbPage;

namespace Ui {
class ModifyMode;
}

class ModifyMode : public QWidget
{
    Q_OBJECT

public:
    explicit ModifyMode(QWidget *parent = 0);
    ~ModifyMode();

private:
    Ui::ModifyMode *ui;

    QList<QString> columnNames; //字段名集合
    QList<int> columnWidths;    //字段宽度集合
    DbPage *dbPage;             //数据库翻页类

    QString tableName;          //表名称
    QString countName;          //统计行数字段名称

signals:
    void display(int number);

private slots:
    void initForm();

private slots:
    void on_btnSelect_clicked();
    void on_btnReturn_clicked();
    void on_btnReturn_2_clicked();
    void on_btnAddMode_clicked();
};

#endif // ModifyMode_H
