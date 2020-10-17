#ifndef FILESWIDGET_H
#define FILESWIDGET_H

#include <QWidget>
#include <QButtonGroup>
#include <QVector>
#include <QFile>
#include <QDebug>
#include <QMessageBox>
#include "patientinfo.h"
#include <QThread>

namespace Ui {
class FilesWidget;
}

class FilesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FilesWidget(QWidget *parent = nullptr);
    ~FilesWidget();

private:
    Ui::FilesWidget *ui;
    QButtonGroup *sortButtonGroup;

signals:
    void display(int number);

private slots:
    void on_returnButton_clicked(); //返回菜单

    void on_refreshButton_clicked();
};

#endif // SORTWIDGET_H
