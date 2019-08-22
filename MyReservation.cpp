//
// Created by Idan Twito 311125249 on 11/27/18.
//

#include "MyReservation.h"

using namespace std;

MyReservation::MyReservation(Customer *resCustomer, Flight *resFlight,
                             Classes resClass, int resMaxBaggage, string id) {
    this->resCustomer = resCustomer;
    this->resFlight = resFlight;
    this->resClass = resClass;
    this->resMaxBaggage = resMaxBaggage;
    this->id = id;
}

Classes MyReservation::getClass() { return this->resClass; }

Customer *MyReservation::getCustomer() { return this->resCustomer; }

Flight *MyReservation::getFlight() { return this->resFlight; }

int MyReservation::getMaxBaggage() { return this->resMaxBaggage; }

string MyReservation::getID() { return this->id; }

//returns string that describes this class' members
string MyReservation::resLine() {
    string line = "";
    line += this->getID() + COMMA;
    line += this->getFlight()->getID() + COMMA;
    line += this->getCustomer()->getID() + COMMA;
    line += to_string(this->getClass()) + COMMA;
    line += to_string(this->getMaxBaggage()) + COMMA;
    line += NEW_LINE;
    return line;
}

string MyReservation::operator()() {
    return this->resLine();
}

MyReservation::~MyReservation() {

}