//
// Created by Idan Twito 311125249 on 11/27/18.
//

#ifndef EX2AC_MYPLANE_H
#define EX2AC_MYPLANE_H

#include "interface.h"

using namespace std;

class MyPlane : public Plane {
private:
    int model_number;
    map<Jobs, int> crew_needed;
    map<Classes, int> max_passangers;
    string id;
public:

    MyPlane(int model_number, map<Jobs, int> crew_needed,
            map<Classes, int> max_passangers, string id);

    virtual int getModelNumber();

    virtual map<Jobs, int> getCrewNeeded();

    virtual int getMaxFirstClass();

    virtual int getMaxEconomyClass();

    virtual string getID();

    string planeLine();

    string operator()();

    ~MyPlane();
};

#endif //EX2AC_MYPLANE_H