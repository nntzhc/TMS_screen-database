#ifndef SINGLEMODE_H
#define SINGLEMODE_H

#include <QWidget>

namespace Ui {
class SingleMode;
}

class SingleMode : public QWidget
{
    Q_OBJECT

public:
    explicit SingleMode(QWidget *parent = 0);
    ~SingleMode();

private:
    Ui::SingleMode *ui;

signals:
    void display(int number);


private slots:
    void on_returnButton_clicked();
};

#endif // SINGLEMODE_H
