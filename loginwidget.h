#ifndef LoginWIDGET_H
#define LoginWIDGET_H

#include <QWidget>
#include <QString>

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();

private:
    Ui::LoginWidget *ui;

signals:
    void display(int number);
    void idchange(int id);//声明信号


private slots:
    void on_returnButton_clicked();
    void on_signupButton_clicked();
    void lastloginbutton_alter();
    void on_loginButton_clicked();
    void on_logoffButton_clicked();
    void on_lastloginButton_clicked();
};

#endif // ADDPatientWIDGET_H
