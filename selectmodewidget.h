#ifndef SELECTMODEWIDGET_H
#define SELECTMODEWIDGET_H

#include <QWidget>

namespace Ui {
class SelectModeWidget;
}

class SelectModeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SelectModeWidget(QWidget *parent = nullptr);
    ~SelectModeWidget();

private:
    Ui::SelectModeWidget *ui;

signals:
    void display(int number);

private slots:
    void on_returnButton_clicked();
    void on_singleButton_clicked();
    void on_seriesButton_clicked();
    void on_modifyButton_clicked();
};

#endif // SELECTMODEWIDGET_H
