#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QStackedLayout>
#include "menuwidget.h"
#include "loginwidget.h"
#include "fileswidget.h"
#include "selectmodewidget.h"
#include "sortwidget.h"
#include "signupwidget.h"
#include "modifymode.h"
#include "singlemode.h"
#include "seriesmode.h"
#include "addmode.h"
#include <qdebug.h>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "sqlitedbaoperator.h"
#include <QString>

extern int now_user_id;

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:

    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    QSqlQuery sql_query;


private:
    Ui::MainWidget *ui;

    MenuWidget *menuwidget;	//菜单窗口
    LoginWidget *loginwidget;	//登陆窗口
    Signupwidget *signupwidget; //注册
    FilesWidget *fileswidget;	//查询窗口
    SelectModeWidget *selectmodewidget;	//修改窗口
    SortWidget *sortwidget;	//排序窗口

    SingleMode *singlemode;
    SeriesMode *seriesmode;
    ModifyMode *modifymode;
    Addmode *addmode;

    QStackedLayout *stackLayout;	//QStackedLayout布局


};

#endif // MAINWIDGET_H
