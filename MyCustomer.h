//
// Created by Idan Twito 311125249 on 11/27/18.
//

#ifndef EX2AC_MYCUSTOMER_H
#define EX2AC_MYCUSTOMER_H

#include "interface.h"

using namespace std;

class MyCustomer : public Customer {
private:
    string fullName;
    int priority;
    list<Reservation *> reservations;
    string id;
public:
    MyCustomer(string fullName, int priority, string id);

    virtual string getFullName();

    virtual int getPriority();

    virtual list<Reservation *> getReservations();

    string customerLine();

    string operator()();

    virtual string getID();

    void addNewReservation(Reservation *newRes);

    ~MyCustomer();
};

#endif //EX2AC_MYCUSTOMER_H
