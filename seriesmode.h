#ifndef SERIESMODE_H
#define SERIESMODE_H

#include <QWidget>
#include <QMessageBox>

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
    void on_startButton_clicked();
    void on_stopButton_clicked();
    void on_endButton_clicked();
    void emit_pulse();
    void end_procedure();
};

#endif // SERIESMODE_H
