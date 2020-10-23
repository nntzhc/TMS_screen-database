#include <QApplication>
#include <QString>
#include "mainwidget.h"
#include "sqlitedbaoperator.h"

int main(int argc, char *argv[]){
//    //解决可能的中文乱码
//    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));
//    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));
//    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));

    QApplication app(argc, argv);

//    int now_user_id=0;
//    char now_user_name=' ';
//    int now_user_id=0;

    MainWidget w;
    w.setWindowTitle("TMS桌面控制程序");
    w.show();

    return app.exec();
}
