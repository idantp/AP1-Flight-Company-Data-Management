//
// Created by Idan Twito 311125249 on 11/27/18.
//

#include "MyFlight.h"
#include "MyImplementation.h"

using namespace std;

MyFlight::MyFlight(int model_number, Date date1, string source,
                   string destination, list<Reservation *> reservationsList,
                   list<Employee *> employeesList, string id) : date(date1) {
    this->model_number = model_number;
    this->date = date1;
    this->reservationsList = reservationsList;
    this->employeesList = employeesList;
    this->source = source;
    this->destination = destination;
    this->id = id;
}

//returns string that describes this class' members
string MyFlight::flightLine() {
    string line = "";
    line += (this->getID() + COMMA + to_string(this->model_number) + COMMA +
             this->getDate().getDate() + COMMA + this->getSource() +
             COMMA + this->getDestination() + COMMA + NEW_LINE);
    return line;
}

int MyFlight::getModelNumber() { return this->model_number; }

Date MyFlight::getDate() { return this->date; }

list<Reservation *> MyFlight::getReservations() {
    return this->reservationsList;
}

list<Employee *> MyFlight::getAssignedCrew() {
    return this->employeesList;
}

string MyFlight::getSource() { return this->source; }

string MyFlight::getDestination() { return this->destination; }

string MyFlight::getID() { return this->id; }

string MyFlight::operator()() {
    return this->flightLine();
}

//add new reservation one new reservation is inserted.
void MyFlight::addNewReservation(Reservation *reservation) {
    this->reservationsList.push_back(reservation);
}

MyFlight::~MyFlight() {

}