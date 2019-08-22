//
// Created by Idan Twito 311125249 on 11/27/18.
//

#include "MyPlane.h"

using namespace std;

MyPlane::MyPlane(int model_number, map<Jobs, int> crew_needed,
                 map<Classes, int> max_passangers, string id) {
    this->model_number = model_number;
    this->crew_needed = crew_needed;
    this->max_passangers = max_passangers;
    this->id = id;
}

//returns string that describes this class' members
string MyPlane::planeLine() {
    string line = "";
    line += this->getID() + COMMA;
    line += to_string(this->getModelNumber()) + COMMA;
    //writes all the jobs
    for (auto &crewJob:crew_needed) {
        line += to_string(crewJob.second) + COMMA;
    }
    //writes max capacity of first class, then the second calss' capacity.
    for (auto &maxPas:max_passangers) {
        line += to_string(maxPas.second) + COMMA;
    }
    line += NEW_LINE;
    return line;
}

int MyPlane::getMaxEconomyClass() {
    return this->max_passangers.find(SECOND_CLASS)->second;
}

int MyPlane::getMaxFirstClass() {
    return this->max_passangers.find(FIRST_CLASS)->second;
}

int MyPlane::getModelNumber() { return this->model_number; }

map<Jobs, int> MyPlane::getCrewNeeded() { return this->crew_needed; }

string MyPlane::getID() { return this->id; }

string MyPlane::operator()() {
    return this->planeLine();
}

MyPlane::~MyPlane() {

}