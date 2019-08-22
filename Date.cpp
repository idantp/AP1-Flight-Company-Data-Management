//
// Created by Idan Twito 311125249 on 11/26/18.
//
#include <string.h>
#include "interface.h"

#define YEAR_INDEX 0
#define YEAR_LEN 4
#define MONTH_INDEX 5
#define DAY_INDEX 8
#define MONTH_DAY_LEN 2
#define DATE_LEN 10
#define FIRST_COMMA 4
#define SECOND_COMMA 7
#define MIN_YEAR 0
#define MAX_YEAR 9999
#define MAX_MONTH 12
#define MIN_MONTH 1
#define MIN_DAY 1
#define MAX_DAY 31
using namespace std;

// returns true for valid date, false otherwise
bool isDateValid(string date) {
    int flag = 0;
    if ((date.length() != DATE_LEN) || (date.at(FIRST_COMMA) != '-') ||
        (date.at(SECOND_COMMA) != '-')) {
        flag = 1;
    }
    string yearStr = date.substr(YEAR_INDEX, YEAR_LEN);
    string monthStr = date.substr(MONTH_INDEX, MONTH_DAY_LEN);
    string dayStr = date.substr(DAY_INDEX, MONTH_DAY_LEN);
    if (stoi(yearStr) < MIN_YEAR || stoi(yearStr) > MAX_YEAR ||
        stoi(monthStr) > MAX_MONTH || stoi(monthStr) < MIN_MONTH ||
        stoi(dayStr) > MAX_DAY || stoi(dayStr) < MIN_DAY) {
        flag = 1;
    }
    if (flag == 0) { return true; }
    return false;
}

Date::Date(string date) {
    if (isDateValid(date)) {
        this->date = date;
    } else {
        throw ("invalid date pattern ");
    }
}

bool Date::operator>(const Date &d) const {
    if (this->getDate().substr(YEAR_INDEX, YEAR_LEN) > d.getDate().substr
            (YEAR_INDEX, YEAR_LEN)) {
        return true;
    } else if (this->getDate().substr(YEAR_INDEX, YEAR_LEN) ==
               d.getDate().substr(YEAR_INDEX, YEAR_LEN)) {
        if (this->getDate().substr(MONTH_INDEX, MONTH_DAY_LEN) > d.getDate()
                .substr
                        (MONTH_INDEX, MONTH_DAY_LEN)) {
            return true;
        } else if (this->getDate().substr(MONTH_INDEX, MONTH_DAY_LEN) ==
                   d.getDate().substr
                           (MONTH_INDEX, MONTH_DAY_LEN)) {
            if (this->getDate().substr(DAY_INDEX, MONTH_DAY_LEN) >
                d.getDate().substr(DAY_INDEX, MONTH_DAY_LEN)) {
                return true;
            }
        }
    }
    return false;
}

bool Date::operator==(const Date &d) const {
    if (this->getDate().substr(YEAR_INDEX, YEAR_LEN) ==
        d.getDate().substr(YEAR_INDEX, YEAR_LEN) &&
        this->getDate().substr(MONTH_INDEX, MONTH_DAY_LEN) == d.getDate().substr
                (MONTH_INDEX, MONTH_DAY_LEN) &&
        this->getDate().substr(DAY_INDEX, MONTH_DAY_LEN) ==
        d.getDate().substr(DAY_INDEX, MONTH_DAY_LEN)) { return true; }
    return false;
}

bool Date::operator<(const Date &d) const {
    return (!((*this > d) || (*this == d)));
}