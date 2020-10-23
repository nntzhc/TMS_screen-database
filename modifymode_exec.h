#ifndef MODIFYMODE_EXEC_H
#define MODIFYMODE_EXEC_H

#include <QWidget>

namespace Ui {
class Modifymode_exec;
}

class Modifymode_exec : public QWidget
{
    Q_OBJECT

public:
    explicit Modifymode_exec(QWidget *parent = 0);
    ~Modifymode_exec();

private:
    Ui::Modifymode_exec *ui;
};

#endif // MODIFYMODE_EXEC_H
