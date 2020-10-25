#ifndef Settings_H
#define Settings_H

#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QDebug>

extern int Threshold_Default;
extern int Noticetime_Default;
extern int Dirlogin_Default;

namespace Ui {
class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

private:
    Ui::Settings *ui;

signals:
    void display(int number);

private slots:

    void on_returnButton_clicked();
    void on_saveButton_clicked();
    void on_DefaultButton_clicked();
    void on_clchisButton_clicked();
    void on_clcfileButton_clicked();
    void someSlot();
};

#endif // Settings_H
