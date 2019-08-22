//
// Created by Idan Twito 311125249 on 11/26/18.
//

#include "MyEmployee.h"
#include <string.h>

using namespace std;

MyEmployee::MyEmployee(int seniority, int birth_year, Jobs title,
                       Employee *employer, string id) {
    this->seniority = seniority;
    this->birth_year = birth_year;
    this->title = title;
    this->employer = employer;
    this->id = id;
}

int MyEmployee::getSeniority() { return this->seniority; }

int MyEmployee::getBirthYear() { return this->birth_year; }

Employee *MyEmployee::getEmployer() { return this->employer; }

Jobs MyEmployee::getTitle() { return this->title; }

string MyEmployee::getID() { return this->id; }

//returns string that describes this class' members
string MyEmployee::employeeLine() {
    string idEmployer;
    string line = "";
    if (employer == nullptr){
        idEmployer = "null";
    } else {
        idEmployer = employer->getID();
    }
    line += (id + COMMA + to_string(seniority) + COMMA + to_string
            (birth_year) + COMMA + idEmployer + COMMA + to_string(title) +
            COMMA + NEW_LINE);

    return line;
}

string MyEmployee::operator()() {
    return this->employeeLine();
}

MyEmployee::~MyEmployee() {
}