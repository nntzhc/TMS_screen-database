#ifndef SCHEMEINFO_H
#define SCHEMEINFO_H
#include <QString>

class SchemeInfo
{
private:
    QString id,name,disease,position,all_time;
    int  power, freq,pulse_num_oneT,rest_time,T_num,all_pulse_num;

public:
    SchemeInfo();
    SchemeInfo (QString tid ,QString tname , QString tdisease , QString tposition  , int tpower\
                , int tfreq , int tpulse_num_oneT , int trest_time , int tT_num, QString tall_time , int tall_pulse_num){
        name = tname;
        disease= tdisease;
        position = tposition;
        all_time = tall_time;
        id = tid;
        power= tpower;
        freq = tfreq;
        pulse_num_oneT = tpulse_num_oneT;
        rest_time = trest_time;
        T_num = tT_num;
        all_pulse_num = tall_pulse_num;

    }


    QString getName(){
        return name;
    }
    QString getDisease(){
        return disease;
    }
    QString getPosition(){
        return position;
    }

    QString getAll_time(){
        return all_time;
    }
    QString getId(){
            return id;
        }
    int getPower(){
        return power;
    }
    int getFreq(){
        return freq;
    }
    int getPulse_num_oneT(){
            return pulse_num_oneT;
        }
    int getRest_time(){
        return rest_time;
    }
    int getT_num(){
        return T_num;
    }
    int getAll_pulse_num(){
        return all_pulse_num;
    }


//    void setId(int tid){
//        id = tid;
//    }
//    void setName(QString tname){
//        name = tname;
//    }


};



#endif // SCHEMEINFO_H
