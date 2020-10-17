#ifndef MODIFYMODE_H
#define MODIFYMODE_H

#include <QWidget>
//#include <QButtonGroup>
#include <QVector>
#include <QFile>
#include <QDebug>
#include <QMessageBox>
#include "schemeinfo.h"

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

signals:
    void display(int number);


private slots:
    void on_returnButton_clicked();
    void on_addschButton_clicked();
    void on_refreshButton_clicked();
};

#endif // MODIFYMODE_H
