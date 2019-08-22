//
// Created by Idan Twito 311125249 on 11/27/18.
//

#ifndef EX2AC_MYFLIGHT_H
#define EX2AC_MYFLIGHT_H

#include "interface.h"


using namespace std;

class MyFlight : public Flight {
private:
    int model_number;
    Date date;
    list<Reservation *> reservationsList;
    list<Employee *> employeesList;
    string source;
    string destination;
    string id;

public:
    MyFlight(int model_number, Date date1, string source,
             string destination, list<Reservation *> reservationsList,
             list<Employee *> employeesList,string id);

    virtual int getModelNumber();

    virtual list<Reservation *> getReservations();

    virtual list<Employee *> getAssignedCrew();

    virtual Date getDate();

    virtual string getSource();

    virtual string getDestination();

    virtual string getID();

    string flightLine();

    string operator()();

    void addNewReservation(Reservation* reservation);

    ~MyFlight();
};

#endif //EX2AC_MYFLIGHT_H
