//
// Created by Idan Twito 311125249 on 11/26/18.
//

#ifndef EX2AC_MYEMPLOYEE_H
#define EX2AC_MYEMPLOYEE_H

#include "interface.h"

using namespace std;

class MyEmployee : public Employee {
private:
    int seniority;
    int birth_year;
    Employee *employer;
    Jobs title;
    string id;
public:
    MyEmployee(int seniority, int birth_year, Jobs title, Employee *employer,
               string id);

    virtual int getSeniority();

    virtual int getBirthYear();

    virtual Employee *getEmployer();

    virtual Jobs getTitle();

    virtual string getID();

    string employeeLine();

    string operator()();

    ~MyEmployee();
};

#endif //EX2AC_MYEMPLOYEE_H
