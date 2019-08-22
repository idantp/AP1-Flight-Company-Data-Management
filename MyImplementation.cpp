//
// Created by Idan Twito 311125249 on 11/29/18.
//


#define MYCUSTOMERS_TXT_FILE "MyCustomers.txt"
#define MYEMPLOYEES_TXT_FILE "MyEmployees.txt"
#define MYPLANES_TXT_FILE "MyPlanes.txt"
#define MYFLIGHTS_TXT_FILE "MyFlights.txt"
#define MYRESERVATIONS_TXT_FILE "MyReservations.txt"
#define FLIGHTANDCREW_TXT_FILE "FlightIDAndCrew.txt"
#define EMPLOYEES_SHIFT_TXT_FILE "EmployeeShift.txt"
#define PLANES_SHIFT_TXT_FILE "PlaneShift.txt"
#define FLIGHT_CLASSES_CAPACITY_TXT "FlightClassesCap.txt"
#define JOBS_AMOUNT 5
#define FLIGHT_MAP_LEN 4
#define MAX_PRIORITY 5
#define CUSTOMER_TXT 'c'
#define EMPLOYEE_TXT 'e'
#define PLANE_TXT 'p'
#define FLIGHT_TXT 'f'
#define RESERVATION_TXT 'r'

#include "MyImplementation.h"
#include "interface.h"

using namespace std;

//checks if the given txt is available for reading.
bool MyImplementation::createNewTxtFile(const char *file) const {
    ifstream inputFile(file);
    return inputFile.good();
}

/*
 * the method gets an ID string. if this is the first get command, the
 * function load all the customers from the necessary txt file to the right
 * list. if the id exists in the list it returns that customer
 */
Customer *MyImplementation::getCustomer(string id) {
    MyCustomer *customer = nullptr;
    //reading all the info from txt in the first get command in each first
    // program running
    if (this->myCustomerList.empty() &&
        createNewTxtFile(MYCUSTOMERS_TXT_FILE)) {
        loadObjFromTxt(MYCUSTOMERS_TXT_FILE, CUSTOMER_TXT);
    }
    list<MyCustomer *>::iterator listIter;
    for (listIter = this->myCustomerList.begin();
         listIter != this->myCustomerList.end(); ++listIter) {
        if ((*listIter)->getID() == id) {
            customer = (*listIter);
            break;
        }
    }
    return customer;
}

/*
 * the method gets an ID string. if this is the first get command, the
 * function load all the employees from the necessary txt file to the right
 * list. if the id exists in the list it returns that employee.
 */
Employee *MyImplementation::getEmployee(string id) {
    MyEmployee *employee = nullptr;
    //reading all the info from txt in the first get command in each first
    // program running
    if (this->myEmployeeList.empty() &&
        createNewTxtFile(MYEMPLOYEES_TXT_FILE)) {
        loadObjFromTxt(MYEMPLOYEES_TXT_FILE, EMPLOYEE_TXT);
    }
    list<MyEmployee *>::iterator listIter;
    for (listIter = this->myEmployeeList.begin();
         listIter != this->myEmployeeList.end(); ++listIter) {
        if ((*listIter)->getID() == id) {
            employee = (*listIter);
            break;
        }
    }
    return employee;
}

/*
 * the method gets an ID string. if this is the first get command, the
 * function load all the planes from the necessary txt file to the right
 * list. if the id exists in the list it returns that plane.
 */
Plane *MyImplementation::getPlane(string id) {
    MyPlane *plane = nullptr;
    //reading all the info from txt in the first get command in each first
    // program running
    if (this->myPlaneList.empty() && createNewTxtFile(MYPLANES_TXT_FILE)) {
        loadObjFromTxt(MYPLANES_TXT_FILE, PLANE_TXT);
    }
    list<MyPlane *>::iterator listIter;
    for (listIter = this->myPlaneList.begin();
         listIter != this->myPlaneList.end(); ++listIter) {
        if ((*listIter)->getID() == id) {
            plane = (*listIter);
            break;
        }
    }
    return plane;
}

/*
 * the method gets an ID string. if this is the first get command, the
 * function load all the flights from the necessary txt file to the right
 * list. if the id exists in the list it returns that flight.
 */
Flight *MyImplementation::getFlight(string id) {
    MyFlight *flight = nullptr;
    //reading all the info from txt in the first get command in each first
    // program running
    if (this->myFlightList.empty() && createNewTxtFile(MYFLIGHTS_TXT_FILE)) {
        loadObjFromTxt(MYFLIGHTS_TXT_FILE, FLIGHT_TXT);
    }
    list<MyFlight *>::iterator listIter;
    for (listIter = this->myFlightList.begin();
         listIter != this->myFlightList.end(); ++listIter) {
        if ((*listIter)->getID() == id) {
            flight = (*listIter);
            break;
        }
    }
    return flight;
}

/*
 * the method gets an ID string. if this is the first get command, the
 * function load all the reservations from the necessary txt file to the right
 * list. if the id exists in the list it returns that reservation
 */
Reservation *MyImplementation::getReservation(string id) {
    MyReservation *reservation = nullptr;
    //reading all the info from txt in the first get command in each first
    // program running
    if (this->myReservationList.empty() &&
        createNewTxtFile(MYRESERVATIONS_TXT_FILE)) {
        loadObjFromTxt(MYRESERVATIONS_TXT_FILE, RESERVATION_TXT);
    }
    list<MyReservation *>::iterator listIter;
    for (listIter = this->myReservationList.begin();
         listIter != this->myReservationList.end(); ++listIter) {
        if ((*listIter)->getID() == id) {
            reservation = (*listIter);
            break;
        }
    }
    return reservation;
}

/*
 * the function gets a file and list of (Objects) information. it writes the
 * Objects to the given txt file.
 */
template<class T>
void MyImplementation::writingToTxt(string file, list<T *> infoList) {
    ofstream ofstream1;
    ofstream1.open(file);
    if (ofstream1.is_open()) {
        for (T *const pieceOfInfo: infoList) {
            ofstream1 << (*pieceOfInfo)();
        }
        ofstream1.close();
    } else {
        throw ("an error occurred while trying open a file");
    }
}

/*
 * the function writes the given map into the given file. each map pair will
 * be written in one line in such way that every Object is seperated with
 * COMMA from the next Object.
 */
void MyImplementation::writeShiftMap(string file,
                                     map<string, list<Date>> shiftMap) {
    ofstream ofstream1;
    ofstream1.open(file);
    if (ofstream1.is_open()) {
        list<Date>::iterator listIter;
        map<string, list<Date>>::iterator mapIter;
        for (mapIter = shiftMap.begin(); mapIter != shiftMap.end(); mapIter++) {
            for (listIter = mapIter->second.begin(); listIter != mapIter->second
                    .end(); ++listIter) {
                ofstream1 << (mapIter->first) << COMMA <<
                          ((*listIter).getDate()) << COMMA << NEW_LINE;
            }
        }
        ofstream1.close();
    } else {
        throw ("an error occurred while opening shift TXT file");
    }
}

/*
 * this method gets a list of employees that will work in the given flight.
 * the method writes in a line (into FLIGHTANDCREW_TXT_FILE) the flight ID
 * and each employee on the
 * flight
 * so each word is separated with COMMA.
 */
void MyImplementation::writeFlightandcrew(list<Employee *> flightCrew,
                                          string flightID) {
    ofstream outputStream;
    outputStream.open(FLIGHTANDCREW_TXT_FILE, ios::out | ios::app | ios::ate);
    if (outputStream.is_open()) {
        list<Employee *>::iterator iter1;
        //find this employee's employer
        for (iter1 = flightCrew.begin(); iter1 != flightCrew.end(); ++iter1) {
            outputStream << flightID << COMMA << ((*iter1)->getID())
                         << COMMA << NEW_LINE;
        }
        outputStream.close();
    } else {
        throw ("an error occurred while opening FlightIDAndCrew.txt");
    }
}

/*
 * the function writes the given map into FLIGHT_CLASSES_CAPACITY_TXT file,
 * so each pair in the map is written in a line, and every map's Object is
 * separated with COMMA. the file will contain the following information in
 * each line:
 * flightID,Plane's First Class Max Cap,Plane's First Class Current Cap,
 * Plane's Economy Class Max Cap,Plane's Economy Class Current Capacity.
 */
void MyImplementation::writeFlightsDetailsMap(
        map<string, vector<int>> flightsPlaneInfo) {
    ofstream outputStream;
    outputStream.open(FLIGHT_CLASSES_CAPACITY_TXT);
    if (outputStream.is_open()) {
        map<string, vector<int>>::iterator mapIter;
        for (mapIter = flightsPlaneInfo.begin(); mapIter != flightsPlaneInfo
                .end(); ++mapIter) {
            outputStream << (*mapIter).first;
            for (int vecIndex = 0; vecIndex < FLIGHT_MAP_LEN; vecIndex++) {
                outputStream << COMMA << (*mapIter).second[vecIndex];
            }
            outputStream << COMMA << NEW_LINE;
        }
        outputStream.close();
    } else { throw ("an error occurred while opening FlightClassesCap.txt"); }
}

/*
 * the function creates an employee (if the input was inserted properly), and
 * pushes it to the employees'-list member.
 */
Employee *MyImplementation::addEmployee(int seniority, int birth_year,
                                        string employer_id, Jobs title) {
    if (seniority >= ZERO &&
        (birth_year >= ZERO && birth_year <= MAX_YEAR)) {
        //load from txt file if the list is empty and such txt file was
        // already created
        if (this->myEmployeeList.empty() &&
            createNewTxtFile(MYEMPLOYEES_TXT_FILE)) {
            loadObjFromTxt(MYEMPLOYEES_TXT_FILE, EMPLOYEE_TXT);
        }
        MyEmployee *employer = nullptr;
        list<MyEmployee *>::iterator iter1;
        string id = readNewId();
        MyEmployee *myEmployee = new MyEmployee(seniority, birth_year,
                                                title, getEmployee(employer_id),
                                                id);
        myEmployeeList.push_back(myEmployee);
        return myEmployee;
    }
    throw ("invalid seniority of year birth");
}

/*
 * the function creates a plane (if the input was inserted properly), and
 * pushes it to the planes'-list member.
 */
Plane *MyImplementation::addPlane(int model_number, map<Jobs, int> crew_needed,
                                  map<Classes, int> max_passangers) {
    //load from txt file if the list is empty and such txt file was
    // already created
    if (this->myPlaneList.empty() && createNewTxtFile(MYPLANES_TXT_FILE)) {
        loadObjFromTxt(MYPLANES_TXT_FILE, PLANE_TXT);
    }
    MyPlane *myPlane = nullptr;
    string id = readNewId();
    myPlane = new MyPlane(model_number, crew_needed, max_passangers, id);
    myPlaneList.push_back(myPlane);
    return myPlane;
}

/*
 * the function gets a plane model and a date, it checks if there's
 * an existing plane which is free for flight on the the given date.
 * if the plane is free it, add this date to its schedule and returns
 * its id number. if the plane is booked it throws an exception
 */
string MyImplementation::searchAvailablePlane(int model_number, Date date) {
    //if gets 1 then the plane is booked for the given dates
    int flagBusyDate = 0;
    list<MyPlane *>::iterator planeIter;
    //find a plane with model_number model
    for (planeIter = myPlaneList.begin();
         planeIter != myPlaneList.end(); ++planeIter) {
        //if found one
        if ((*planeIter)->getModelNumber() == model_number) {
            //save the certain plane's id
            string idStr = (*planeIter)->getID();
            //save all the flights dates
            if (planeShiftsMap.find(idStr) != planeShiftsMap.end()) {
                list<Date> planeDates = planeShiftsMap.find(idStr)->second;
                list<Date>::iterator dateIter;
                //find a plane with a free date
                for (dateIter = planeDates.begin();
                     dateIter != planeDates.end(); ++dateIter) {
                    if (date == *dateIter) {
                        //marks that model_number plane with the idStr is
                        // booked for that date
                        flagBusyDate = 1;
                        break;
                    }
                }
                if (flagBusyDate == 0) {
                    return idStr;
                }

                flagBusyDate = 0;
            } else {
                return (*planeIter)->getID();
            }
        }
    }
    throw ("all the planes with the model you entered are booked, try "
           "different model plane");
}

/*
 * the function gets a plane and a date, it checks if there's
 * an existing crew which is free for flight on the the given date.
 * if the there's a crew which is available, it adds this date to to the
 * schedule of each employee in the crew, and returns a list of there
 * employees. otherwise, if there's not enough employees to man this
 * plane it throws an exception
 */
list<Employee *> MyImplementation::searchEmployees(MyPlane *myPlane,
                                                   Date date) {
    list<Employee *> fullCrewList;
    int flagBusyDate = 0;
    //initialize the Array with the amount of employees in each job.
    int jobsArray[JOBS_AMOUNT];
    jobsArray[MANAGER] = myPlane->getCrewNeeded().at(MANAGER);
    jobsArray[NAVIGATOR] = myPlane->getCrewNeeded().at(NAVIGATOR);
    jobsArray[FLY_ATTENDANT] = myPlane->getCrewNeeded().at(FLY_ATTENDANT);
    jobsArray[PILOT] = myPlane->getCrewNeeded().at(PILOT);
    jobsArray[OTHER] = myPlane->getCrewNeeded().at(OTHER);
    //running through all the employees
    list<MyEmployee *>::iterator employeeIter;
    MyEmployee *tempEmployee = nullptr;
    for (employeeIter = myEmployeeList.begin();
         employeeIter != myEmployeeList.end(); ++employeeIter) {
        tempEmployee = *employeeIter;
        //if there's a need of this kind of job
        if (jobsArray[tempEmployee->getTitle()] > 0) {
            //if the employee isn't in the map
            if (employeeShiftsMap.find(tempEmployee->getID()) !=
                employeeShiftsMap.end()) {
                //save all the employee's work dates
                list<Date> employeeDates = employeeShiftsMap.find
                        (tempEmployee->getID())->second;
                //check if on the desired date if free for tempEmployee
                list<Date>::iterator dateIter;
                //find a plane with a free date
                for (dateIter = employeeDates.begin();
                     dateIter != employeeDates.end(); ++dateIter) {
                    if (date == *dateIter) {
                        //marks that employee is already busy on the date
                        flagBusyDate = 1;
                        break;
                    }
                }
            }//then the employee is free on that date.
            if (flagBusyDate == 0) {
                jobsArray[tempEmployee->getTitle()]--;
                fullCrewList.push_back(tempEmployee);
            }
        }
        flagBusyDate = 0;
        if (jobsArray[MANAGER] == 0 && jobsArray[NAVIGATOR] == 0 &&
            jobsArray[FLY_ATTENDANT] == 0 && jobsArray[PILOT] == 0 &&
            jobsArray[OTHER] == 0) {
            return fullCrewList;
        }
    }
    throw ("there's no available crew to man the flight on that date!");
}

/*
 * the function creates a flight (if the input was inserted properly), and
 * pushes it to the flights'-list member.
 */
Flight *MyImplementation::addFlight(int model_number, Date date, string source,
                                    string destination) {
    //load from the relevant txt files if the lists are empty and such txt
    // files were already created
    if (this->myFlightList.empty() &&
        createNewTxtFile(MYFLIGHTS_TXT_FILE)) {
        loadObjFromTxt(MYFLIGHTS_TXT_FILE, FLIGHT_TXT);
    }
    if (this->myEmployeeList.empty() &&
        createNewTxtFile(MYEMPLOYEES_TXT_FILE)) {
        loadObjFromTxt(MYEMPLOYEES_TXT_FILE, EMPLOYEE_TXT);
    }
    if (this->myPlaneList.empty() && createNewTxtFile(MYPLANES_TXT_FILE)) {
        loadObjFromTxt(MYPLANES_TXT_FILE, PLANE_TXT);
    }
    if (this->employeeShiftsMap.empty() &&
        createNewTxtFile(EMPLOYEES_SHIFT_TXT_FILE)) {
        this->employeeShiftsMap = readShiftMap(EMPLOYEES_SHIFT_TXT_FILE);
    }
    if (this->planeShiftsMap.empty() &&
        createNewTxtFile(PLANES_SHIFT_TXT_FILE)) {
        this->planeShiftsMap = readShiftMap(PLANES_SHIFT_TXT_FILE);
    }
    if (this->flightsDetailsMap.empty() &&
        createNewTxtFile(FLIGHT_CLASSES_CAPACITY_TXT)) {
        this->flightsDetailsMap = readFlightsDetailMap(
                FLIGHT_CLASSES_CAPACITY_TXT);
    }
    MyFlight *myFlight = nullptr;
    //if searchAvailablePlane didn't throw an exception, then this string
    //gets the id of an available plane for this Flight.
    string myPlaneID = searchAvailablePlane(model_number, date);
    //match myPlane  to the plane with myPlaneID plane
    MyPlane *myPlane = nullptr;
    list<MyPlane *>::iterator planeIter;
    //find the plane with myFlightID id
    for (planeIter = myPlaneList.begin();
         planeIter != myPlaneList.end(); ++planeIter) {
        //if found one
        if ((*planeIter)->getID() == myPlaneID) {
            myPlane = *planeIter;
            break;
        }
    }
    //check if there are as much employees to man the plane with
    // myFlightID id as it requires.
    list<Employee *> crewList = searchEmployees(myPlane, date);
    list<Reservation *> reservationsList;
    string flightID = readNewId();
    myFlight = new MyFlight(model_number, date, source, destination,
                            reservationsList, crewList, flightID);
    myFlightList.push_back(myFlight);
    writeFlightandcrew(crewList, myFlight->getID());
    //update flightsDetailsMap with this new Flight:
    vector<int> tempVector;
    tempVector.push_back(myPlane->getMaxFirstClass());
    tempVector.push_back(0);
    tempVector.push_back(myPlane->getMaxEconomyClass());
    tempVector.push_back(0);
    flightsDetailsMap.insert(make_pair(myFlight->getID(), tempVector));
    //update planeShiftsMap:
    //if the plane exists already add this date to its shifts
    if (planeShiftsMap.find(myPlane->getID()) != planeShiftsMap.end()) {
        (planeShiftsMap.find(myPlane->getID())->second).push_back
                (myFlight->getDate());
    } else {
        //otherwise, add a new plane with its new date to the map
        list<Date> newDateList;
        newDateList.push_back(myFlight->getDate());
        planeShiftsMap.insert(make_pair(myPlane->getID(), newDateList));
    }

    //update all the crew's dates in the MAP:
    list<Employee *>::iterator employeeIterator;
    //for every employee in the crew
    for (employeeIterator = crewList.begin();
         employeeIterator != crewList.end();
         ++employeeIterator) {
        //if the employee exists already add his date shift to its dates
        if (employeeShiftsMap.find((*employeeIterator)->getID()) !=
            employeeShiftsMap.end()) {
            (employeeShiftsMap.find((*employeeIterator)->getID())->second)
                    .push_back(date);
        }
            //if the employee is not in the map
        else {
            list<Date> oneDateEmpList;
            oneDateEmpList.push_back(date);
            employeeShiftsMap.insert(
                    make_pair((*employeeIterator)->getID(), oneDateEmpList));
        }
    }
    return myFlight;
}

/*
 * the function creates a customer (if the input was inserted properly), and
 * pushes it to the customers'-list member.
 */
Customer *MyImplementation::addCustomer(string full_name, int priority) {
    if (priority <= MAX_PRIORITY && priority >= MIN_PRIORITY) {
        //load from txt file if the list is empty and such txt file was
        // already created
        if (this->myCustomerList.empty() &&
            createNewTxtFile(MYCUSTOMERS_TXT_FILE)) {
            loadObjFromTxt(MYCUSTOMERS_TXT_FILE, CUSTOMER_TXT);
        }
        MyCustomer *myCustomer = nullptr;
        string id = readNewId();
        myCustomer = new MyCustomer(full_name, priority, id);
        myCustomerList.push_back(myCustomer);
        return myCustomer;
    }
    throw ("priority must be between 1 to 5");
}

/*
 * checks if the plane's class is full or not. return true if it's full,
 * otherwise increase the given class capacity by one.
 */
bool MyImplementation::isPlaneFull(string flightId, Classes cls) {
    /*
     * match to the maps voctor's indexes:
     * index 0 - FirstClass Max Capacity
     * index 1 - FirstClass current Capacity
     * index 2 - EconomyClass Max Capacity
     * index 3 - EconomyClass current Capacity
     */
    int planeClass = cls * 2;
    int classCapacity = planeClass + 1;
    //check if there's a room on the plane for this customer
    for (auto &flightDetail :flightsDetailsMap) {
        if (flightId == flightDetail.first) {
            if (flightDetail.second[planeClass] >
                flightDetail.second[classCapacity]) {
                flightDetail.second[classCapacity]++;
                return false;
            }
        }
    }
    return true;
}

/*
 * the function creates a Resevation (if the input was inserted properly), and
 * pushes it to the Resevations'-list member.
 */
Reservation *MyImplementation::addResevation(string customerId, string flightId,
                                             Classes cls, int max_baggage) {
    //load from the relevant txt files if the lists are empty and such txt
    // files were already created
    if (this->myCustomerList.empty() &&
        createNewTxtFile(MYCUSTOMERS_TXT_FILE)) {
        loadObjFromTxt(MYCUSTOMERS_TXT_FILE, CUSTOMER_TXT);
    }
    if (this->myFlightList.empty() && createNewTxtFile(MYFLIGHTS_TXT_FILE)) {
        loadObjFromTxt(MYFLIGHTS_TXT_FILE, FLIGHT_TXT);
    }
    if (this->myReservationList.empty() &&
        createNewTxtFile(MYRESERVATIONS_TXT_FILE)) {
        loadObjFromTxt(MYRESERVATIONS_TXT_FILE, RESERVATION_TXT);
    }
    int customerFlag = 0;
    int flightFlag = 0;
    MyCustomer *myCustomer = nullptr;
    MyFlight *myFlight = nullptr;
    //check if the given customer' id exists
    list<MyCustomer *>::iterator customerIter;
    //find this employee's employer
    for (customerIter = myCustomerList.begin();
         customerIter != myCustomerList.end(); ++customerIter) {
        if ((*customerIter)->getID() == customerId) {
            myCustomer = *customerIter;
            customerFlag++;
            break;
        }
    }
    if (customerFlag == 0) {
        throw ("customer id wasn't found in the system, reservation wasn't "
               "completed");
    }
    //check if the given flight id exists
    list<MyFlight *>::iterator flightIter;
    //find this flight
    for (flightIter = myFlightList.begin();
         flightIter != myFlightList.end(); ++flightIter) {
        if ((*flightIter)->getID() == flightId) {
            myFlight = *flightIter;
            flightFlag++;
            break;
        }
    }
    if (flightFlag == 0) {
        throw ("flight id wasn't found in the system, reservation wasn't "
               "completed");
    }
    //check if there's space on the plane for this customer,update the
    //class' capacity by one if its not full.
    if (isPlaneFull(flightId, cls)) {
        throw ("this flight has reached it's capacity, try another flight");
    }
    MyReservation *myReservation = nullptr;
    string id = readNewId();
    myReservation = new MyReservation(myCustomer, myFlight, cls,
                                      max_baggage, id);
    myReservationList.push_back(myReservation);
    return myReservation;
}

/*
 * the function gets a string of words(each word is separated with COMMA) .it
 * returns a vector so the i'TH Element in the vector describes the i'TH word
 * in the given string.
 */
vector<string> MyImplementation::stringToVector(string line) {
    vector<string> infoVec;
    int firstLetter = 0;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == COMMA) {
            infoVec.push_back(line.substr(firstLetter, i - firstLetter));
            firstLetter = i + 1;
        }
    }
    return infoVec;
}

/*
 * the method gets a line (each word is separated with COMMA) which
 * represents a customer, it converts it to a vector of string
 * (each element is a word). then it creates a customer and adds it to the
 * customers list.
 */
void MyImplementation::addCustomerToList(string line) {
    MyCustomer *myCustomer;
    vector<string> infoVector = stringToVector(line);
    list<Reservation *> reservations;
    string id = infoVector.at(0);
    string fullName = infoVector.at(1);
    int priority = stoi(infoVector.at(2));
    myCustomer = new MyCustomer(fullName, priority, id);
    this->myCustomerList.push_back(myCustomer);
}

/*
 * the method gets a line (each word is separated with COMMA) which
 * represents an employee, it converts it to a vector of string
 * (each element is a word). then it creates an employee and adds it to the
 * employees list.
 */
void MyImplementation::addEmployeeToList(string line) {
    Jobs employeeTitle;
    MyEmployee *myEmployer = nullptr;
    MyEmployee *myEmployee = nullptr;
    vector<string> infoVector = stringToVector(line);
    string id = infoVector.at(0);
    int seniority = stoi(infoVector.at(1));
    int birth_year = stoi(infoVector.at(2));
    string employerID = infoVector.at(3);
    int num = stoi(infoVector.at(4));
    if (num == 0) { employeeTitle = MANAGER; }
    else if (num == 1) { employeeTitle = NAVIGATOR; }
    else if (num == 2) { employeeTitle = FLY_ATTENDANT; }
    else if (num == 3) { employeeTitle = PILOT; }
    else { employeeTitle = OTHER; }
    list<MyEmployee *>::iterator employeeIter;
    for (employeeIter = this->myEmployeeList.begin();
         employeeIter != this->myEmployeeList.end(); ++employeeIter) {
        if ((*employeeIter)->getID() == employerID) {
            myEmployer = *(employeeIter);
            break;
        }
    }
    myEmployee = new MyEmployee(seniority, birth_year, employeeTitle,
                                myEmployer, id);
    this->myEmployeeList.push_back(myEmployee);
}

/*
 * the method gets a line (each word is separated with COMMA) which
 * represents a plane, it converts it to a vector of string
 * (each element is a word). then it creates a plane and adds it to the
 * planes list.
 */
void MyImplementation::addPlaneToList(string line) {
    vector<string> infoVector = stringToVector(line);
    MyPlane *myPlane = nullptr;
    map<Jobs, int> crew_needed;
    map<Classes, int> max_passangers;
    string planeID = infoVector.at(0);
    int model_num = stoi(infoVector.at(1));
    int maxFirstClass = stoi(infoVector.at(7));
    int maxEconClass = stoi(infoVector.at(8));
    max_passangers.insert(make_pair(FIRST_CLASS, maxFirstClass));
    max_passangers.insert(make_pair(SECOND_CLASS, maxEconClass));
    crew_needed.insert(make_pair(MANAGER, stoi(infoVector.at(2))));
    crew_needed.insert(make_pair(NAVIGATOR, stoi(infoVector.at(3))));
    crew_needed.insert(make_pair(FLY_ATTENDANT, stoi(infoVector.at(4))));
    crew_needed.insert(make_pair(PILOT, stoi(infoVector.at(5))));
    crew_needed.insert(make_pair(OTHER, stoi(infoVector.at(6))));
    myPlane = new MyPlane(model_num, crew_needed, max_passangers, planeID);
    this->myPlaneList.push_back(myPlane);
}

/*
 * the method gets a line (each word is separated with COMMA) which
 * represents a flight, it converts it to a vector of string
 * (each element is a word). then it creates a flight and adds it to the
 * flights list.
 */
void MyImplementation::addFlightToList(string line) {
    vector<string> infoVector = stringToVector(line);
    list<Reservation *> resList;
    MyFlight *myFlight = nullptr;
    ifstream inputStream;
    string flightID = infoVector.at(0);
    int model_num = stoi(infoVector.at(1));
    Date flightDate(infoVector.at(2));
    string source = infoVector.at(3);
    string destination = infoVector.at(4);
    //parsing the flight's crew:
    list<Employee *> parsedCrewList;
    vector<string> idAndCrewLine;
    inputStream.open(FLIGHTANDCREW_TXT_FILE);
    if (inputStream.is_open()) {
        int flightIdIndex = 0;
        int crewInfoIndex = 1;
        //reading each text line and parsing it
        for (string str; getline(inputStream, str);) {
            idAndCrewLine = stringToVector(str);
            //push all the crew to MyEmployee* List
            if (idAndCrewLine.at(flightIdIndex) == flightID) {
                parsedCrewList.push_back(
                        getEmployee(idAndCrewLine.at(crewInfoIndex)));
            }
        }
        inputStream.close();
    } else {
        throw ("an error occurred while reading flight's crew from "
               "FlightIDAndCrew.txt");
    }
    myFlight = new MyFlight(model_num, flightDate, source, destination, resList,
                            parsedCrewList, flightID);
    this->myFlightList.push_back(myFlight);
}

/*
 * the method gets a line (each word is separated with COMMA) which
 * represents a reservation, it converts it to a vector of string
 * (each element is a word). then it creates a reservation and adds it to the
 * reservations list.
 */
void MyImplementation::addReservationToList(string line) {
    vector<string> infoVector = stringToVector(line);
    string resID = infoVector.at(0);
    Flight *flight = getFlight(infoVector.at(1));
    Customer *customer = getCustomer(infoVector.at(2));
    int flightClass = stoi(infoVector.at(3));
    Classes enumClass;
    if (flightClass == 0) { enumClass = FIRST_CLASS; }
    else { enumClass = SECOND_CLASS; }
    int maxBaggage = stoi(infoVector.at(4));
    MyReservation *myReservation = new MyReservation(customer, flight,
                                                     enumClass, maxBaggage,
                                                     resID);
    list<MyFlight *>::iterator flightIter;
    for (flightIter = this->myFlightList.begin();
         flightIter != this->myFlightList.end(); ++flightIter) {
        if ((*flightIter)->getID() == flight->getID()) {
            (*flightIter)->addNewReservation(myReservation);
        }
    }
    list<MyCustomer *>::iterator customerIter;
    for (customerIter = this->myCustomerList.begin();
         customerIter != this->myCustomerList.end(); ++customerIter) {
        if ((*customerIter)->getID() == customer->getID()) {
            (*customerIter)->addNewReservation(myReservation);
        }
    }
    this->myReservationList.push_back(myReservation);
}

/*
 * the method gets a file that in each line all the words are separated with
 * COMMAs. the first word is plane/employee ID and the other words in the
 * same line describe dates in which the plane has scheduled flights/the
 * employee works and that day. each file refers to one Object only -
 * employee or plane.
 */
map<string, list<Date>> MyImplementation::readShiftMap(string file) {
    ifstream inputStream;
    inputStream.open(file);
    if (inputStream.is_open()) {
        list<Date> flightsDatesList;
        vector<string> linesVector;
        map<string, list<Date>> shiftsMap;
        for (string lineStr; getline(inputStream, lineStr);) {
            linesVector = stringToVector(lineStr);
            flightsDatesList.push_back(linesVector.at(1));
            //if such flightID exists in the map then add its date
            if (shiftsMap.find(linesVector.at(0)) != shiftsMap.end()) {
                shiftsMap.find(linesVector.at(0))->second.push_back
                        (linesVector.at(1));
            } else {
                //else insert new pair to the map
                shiftsMap.insert(
                        make_pair(linesVector.at(0), flightsDatesList));
            }
        }
        inputStream.close();
        return shiftsMap;
    } else { throw ("couldn't open Shift TXT file for reading."); }
}

/*
 * the method gets a file that in each line all the 5 words are separated with
 * COMMAs. the first word is a flight ID and the other 4 words in the
 * same line describe:
 * Plane's First Class Max Cap,Plane's First Class Current Cap,
 * Plane's Economy Class Max Cap,Plane's Economy Class Current Capacity.
 */
map<string, vector<int>> MyImplementation::readFlightsDetailMap(string file) {
    ifstream inputStream;
    inputStream.open(file);
    if (inputStream.is_open()) {
        vector<string> linesVector;
        vector<int> capacityVector;
        map<string, vector<int>> flightsDetailsReturn;
        for (string lineStr; getline(inputStream, lineStr);) {
            linesVector = stringToVector(lineStr);
            string flightId = linesVector.at(0);
            for (int i = 1; i <= FLIGHT_MAP_LEN; i++) {
                capacityVector.push_back(stoi(linesVector.at(i)));
            }
            flightsDetailsReturn.insert(make_pair(flightId, capacityVector));
        }
        return flightsDetailsReturn;
    } else { throw ("couldn't open FlightClassCap.txt for reading."); }
}

/*
 * the function gets a file and a char which represents the file.
 * it reads each line from the text, creates an object from it and then add
 * it to its list.
 */
void MyImplementation::loadObjFromTxt(string file, char sign) {
    ifstream inputStream;
    inputStream.open(file);
    if (!inputStream.is_open()) {
        throw ("an error occurred while trying open a file");
    }
    switch (sign) {
        case CUSTOMER_TXT:
            for (string str; getline(inputStream, str);) {
                addCustomerToList(str);
            }
            break;
        case EMPLOYEE_TXT:
            for (string str; getline(inputStream, str);) {
                addEmployeeToList(str);
            }
            break;
        case PLANE_TXT:
            for (string str; getline(inputStream, str);) {
                addPlaneToList(str);
            }
            break;
        case FLIGHT_TXT:
            for (string str; getline(inputStream, str);) {
                addFlightToList(str);
            }
            break;
        case RESERVATION_TXT:
            for (string str; getline(inputStream, str);) {
                addReservationToList(str);
            }
            break;
        default:
            return;
    }
    inputStream.close();
}

/*
 * the function writes back all the not-empty lists and maps to their own
 * files that describe each list/map.
 */
void MyImplementation::exit() {
    if (!(this->myCustomerList.empty())) {
        writingToTxt(MYCUSTOMERS_TXT_FILE, this->myCustomerList);
    }
    if (!(this->myEmployeeList.empty())) {
        writingToTxt(MYEMPLOYEES_TXT_FILE, this->myEmployeeList);
    }
    if (!(this->employeeShiftsMap.empty())) {
        writeShiftMap(EMPLOYEES_SHIFT_TXT_FILE, this->employeeShiftsMap);
    }
    if (!(this->myPlaneList.empty())) {
        writingToTxt(MYPLANES_TXT_FILE, this->myPlaneList);
    }
    if (!(this->planeShiftsMap.empty())) {
        writeShiftMap(PLANES_SHIFT_TXT_FILE, this->planeShiftsMap);
    }
    if (!(this->myFlightList.empty())) {
        writingToTxt(MYFLIGHTS_TXT_FILE, this->myFlightList);
    }
    if (!(this->flightsDetailsMap.empty())) {
        writeFlightsDetailsMap(this->flightsDetailsMap);
    }
    if (!(this->myReservationList.empty())) {
        writingToTxt(MYRESERVATIONS_TXT_FILE, this->myReservationList);
    }
}

//destructor.
MyImplementation::~MyImplementation() {
    for (MyCustomer *myObject:myCustomerList) {
        delete myObject;
    }
    for (MyEmployee *myObject:myEmployeeList) {
        delete myObject;
    }
    for (MyPlane *myObject:myPlaneList) {
        delete myObject;
    }
    for (MyFlight *myObject:myFlightList) {
        delete myObject;
    }
    for (MyReservation *myObject:myReservationList) {
        delete myObject;
    }
}