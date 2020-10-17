#ifndef PatientINFO_H
#define PatientINFO_H
#include <QString>

class PatientInfo
{
private:
    QString id,name,gender;
    int  age, times;

public:
    PatientInfo();
    PatientInfo(QString tname,QString tid, QString tgender , int tage, int ttimes ){
        name = tname;
        gender= tgender;
        id = tid;
        age = tage;
        times = ttimes;

    }

    QString getId(){
            return id;
        }
    QString getName(){
        return name;
    }

    QString getGender(){
        return gender;
    }
    int getage(){
        return age;
    }
    int gettimes(){
        return times;
    }

    void setId(QString tid){
        id = tid;
    }
    void setName(QString tname){
        name = tname;
    }
    void setage(int tage){
        age = tage;

    }
    void settimes(int ttimes){
        times = ttimes;

    }
    void setGender(QString tgender){
        gender = tgender;

    }

};


#endif // PatientINFO_H
