#ifndef SERIESMODE_H
#define SERIESMODE_H

#include <QWidget>

namespace Ui {
class SeriesMode;
}

class SeriesMode : public QWidget
{
    Q_OBJECT

public:
    explicit SeriesMode(QWidget *parent = 0);
    ~SeriesMode();

private:
    Ui::SeriesMode *ui;

signals:
    void display(int number);

private slots:
    void on_returnButton_clicked();
};

#endif // SERIESMODE_H
