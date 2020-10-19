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

private slots:
    void on_returnButton_clicked();
    void on_signupButton_clicked();
    void on_nameLineEdit_editingFinished();
    void on_idLineEdit_editingFinished();
    void on_loginButton_clicked();
};

#endif // ADDPatientWIDGET_H
