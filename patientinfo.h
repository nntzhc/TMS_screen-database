#ifndef PatientINFO_H
#define PatientINFO_H
#include <QString>

class PatientInfo
{
private:


public:
    QString name,gender;
    int  id,age, times;

    PatientInfo();
    PatientInfo(QString tname,int tid, QString tgender , int tage, int ttimes ){
        name = tname;
        gender= tgender;
        id = tid;
        age = tage;
        times = ttimes;

    }

    int getId(){
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

    void setId(int tid){
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
