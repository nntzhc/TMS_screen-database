#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class MenuWidget;
}

class MenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MenuWidget(QWidget *parent = nullptr);
    ~MenuWidget();

private:
    Ui::MenuWidget *ui;

signals:
    void display(int number);

private slots:
    void on_addButton_clicked();
    void on_modeselectButton_clicked();
    void on_filesButton_clicked();
    void on_settingsButton_clicked();
    void on_historyButton_clicked();

};

#endif // MENUWIDGET_H
