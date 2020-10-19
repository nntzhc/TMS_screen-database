#ifndef FilesWidget_H
#define FilesWidget_H

#include <QWidget>

class DbPage;

namespace Ui {
class FilesWidget;
}

class FilesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FilesWidget(QWidget *parent = 0);
    ~FilesWidget();

private:
    Ui::FilesWidget *ui;

    QList<QString> columnNames; //字段名集合
    QList<int> columnWidths;    //字段宽度集合
    DbPage *dbPage1;             //数据库翻页类

    QString tableName;          //表名称
    QString countName;          //统计行数字段名称

signals:
    void display(int number);

private slots:
    void initForm();

private slots:
    void on_btnSelect_clicked();
    void on_btnReturn_clicked();

    void on_btnAddMode_clicked();
    void on_btnReturn_2_clicked();
};

#endif // FilesWidget_H
