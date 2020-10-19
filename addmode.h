#ifndef ADDMODE_H
#define ADDMODE_H

#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include "schemeinfo.h"
#include <QVector>
#include <QFile>
#include "sqlitedbaoperator.h"


namespace Ui {
class Addmode;
}

class Addmode : public QWidget
{
    Q_OBJECT

public:
    explicit Addmode(QWidget *parent = 0);
    ~Addmode();

private slots:
    void on_addmodeButton_clicked();
    void on_returnButton_clicked();

signals:
    void display(int number);

private:
    Ui::Addmode *ui;
};

#endif // ADDMODE_H
