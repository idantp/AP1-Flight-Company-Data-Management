//
// Created by Idan Twito 311125249 on 11/27/18.
//

#ifndef EX2AC_MYRESERVATION_H
#define EX2AC_MYRESERVATION_H

#include "interface.h"

using namespace std;

class MyReservation : public Reservation {
private:
    Customer *resCustomer;
    Flight *resFlight;
    Classes resClass;
    int resMaxBaggage;
    string id;
public:
    MyReservation(Customer *resCustomer, Flight *resFlight, Classes resClass,
                  int resMaxBaggage, string id);

    virtual Customer *getCustomer();

    virtual Flight *getFlight();

    virtual Classes getClass();

    virtual int getMaxBaggage();

    virtual string getID();

    string resLine();

    string operator()();

    ~MyReservation();

};

#endif //EX2AC_MYRESERVATION_H
