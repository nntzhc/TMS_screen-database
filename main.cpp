#include <QApplication>
#include <QString>
#include "mainwidget.h"
//#include "qstring.h"

int main(int argc, char *argv[]){
//    //解决可能的中文乱码
//    QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));
//    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));
//    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB2312"));

    QApplication app(argc, argv);

//    char now_user_name=' ';
//    int now_user_id=0;

    MainWidget w;
    w.show();

    return app.exec();
}
