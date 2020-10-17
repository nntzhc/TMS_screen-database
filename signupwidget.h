#ifndef SIGNUPWIDGET_H
#define SIGNUPWIDGET_H

#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class Signupwidget;
}

class Signupwidget : public QWidget
{
    Q_OBJECT

public:
    explicit Signupwidget(QWidget *parent = 0);
    ~Signupwidget();

private:
    Ui::Signupwidget *ui;


signals:
    void display(int number);

private slots:
    void on_returnButton_clicked(); //点击主菜单按钮
    void on_addButton_clicked();    //点击添加按钮
};


#endif // SIGNUPWIDGET_H
