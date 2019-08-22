//
// Created by Idan Twito 311125249 on 11/27/18.
//

#include "MyCustomer.h"

using namespace std;

MyCustomer::MyCustomer(string fullName, int priority, string id) {
    this->fullName = fullName;
    this->priority = priority;
    this->id = id;
    list<Reservation *> resList;
    this->reservations = resList;
}

string MyCustomer::getFullName() { return this->fullName; }


int MyCustomer::getPriority() { return this->priority; }

list<Reservation *> MyCustomer::getReservations() { return this->reservations; }

string MyCustomer::getID() { return this->id; }

//returns string that describes this class' members
string MyCustomer::customerLine() {
    string line = "";
    line += this->getID() + COMMA;
    line += this->getFullName() + COMMA;
    line += to_string(this->getPriority()) + COMMA;
    line += NEW_LINE;
    return line;
}

string MyCustomer::operator()() {
    return this->customerLine();
}

//add new reservation one new reservation is inserted
void MyCustomer::addNewReservation(Reservation *newRes) {
    this->getReservations().push_back(newRes);
}

MyCustomer::~MyCustomer() {
}