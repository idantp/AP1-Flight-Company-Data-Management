//
// Created by Idan Twito 311125249 on 11/27/18.
//

#ifndef EX2AC_MYIMPLEMENTATION_H
#define EX2AC_MYIMPLEMENTATION_H
#define OBJECTSID_TXT_FILE "objectsID.txt"

#include "MyCustomer.h"
#include "MyEmployee.h"
#include "MyFlight.h"
#include "MyPlane.h"
#include "MyReservation.h"
#include "interface.h"
#include <iostream>
#include <list>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class MyImplementation : public Ex2 {
private:
    map<string, vector<int>> flightsDetailsMap;
    map<string, list<Date>> employeeShiftsMap;
    map<string, list<Date>> planeShiftsMap;
    list<MyEmployee *> myEmployeeList;
    list<MyCustomer *> myCustomerList;
    list<MyPlane *> myPlaneList;
    list<MyFlight *> myFlightList;
    list<MyReservation *> myReservationList;
public:

    /*
     * the function writes to a txt file a number which indicates to ID
     * numbers. the function returns the ID string which is written in the
     * txt, and then writes (by overriding) and same number +1. thus is makes
     * sure each object will get a different ID. if the txt is not exist, the
     * function creates that file and writes "2".
     */
    static string readNewId() {
        int idNumber;
        string strIdNumber;
        const char *txtFileName = OBJECTSID_TXT_FILE;
        FILE *file = fopen(txtFileName, "r");
        //if such file exists
        if (file != nullptr) {
            //read an available id from it.
            ifstream in(OBJECTSID_TXT_FILE);
            in >> idNumber;
            strIdNumber = to_string(idNumber + 1);
            idNumber++;
            in.close();
            ofstream out(OBJECTSID_TXT_FILE);
            out << idNumber;
            out.close();
            fclose(file);
        } else {
            ofstream out(OBJECTSID_TXT_FILE);
            idNumber = 1;
            //gets 1.
            strIdNumber = to_string(idNumber);
            out << idNumber;
            out.close();
        }
        return strIdNumber;
    }

    bool createNewTxtFile(const char *file) const;

    void loadObjFromTxt(string file, char sign);

    template<class T>
    void writingToTxt(string file, list<T *> infoList);

    void writeShiftMap(string file, map<string, list<Date>> shiftMap);

    void writeFlightsDetailsMap(map<string, vector<int>> flightsPlaneInfo);

    void writeFlightandcrew(list<Employee *> flightCrew, string flightID);

    virtual Employee *
    addEmployee(int seniority, int birth_year, string employer_id,
                Jobs title);

    virtual Employee *getEmployee(string id);

    virtual Plane *addPlane(int model_number, map<Jobs, int> crew_needed,
                            map<Classes, int> max_passangers);

    virtual Plane *getPlane(string id);

    string searchAvailablePlane(int model_number, Date date);


    list<Employee *> searchEmployees(MyPlane *myPlane, Date date);

    virtual Flight *addFlight(int model_number, Date date, string source,
                              string destination);

    virtual Flight *getFlight(string id);

    virtual Customer *addCustomer(string full_name, int priority);

    virtual Customer *getCustomer(string id);

    bool isPlaneFull(string flightId, Classes cls);

    virtual Reservation *addResevation(string customerId, string flightId,
                                       Classes cls, int max_baggage);

    virtual Reservation *getReservation(string id);

    virtual void exit();

    virtual void addEmployeeToList(string line);

    virtual void addCustomerToList(string line);

    virtual void addPlaneToList(string line);

    virtual void addFlightToList(string line);

    virtual void addReservationToList(string line);

    map<string, list<Date>> readShiftMap(string file);

    map<string, vector<int>> readFlightsDetailMap(string file);

    vector<string> stringToVector(string line);

    virtual ~MyImplementation();
};

#endif //EX2AC_MYIMPLEMENTATION_H
