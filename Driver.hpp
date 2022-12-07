//
// Created by Oliver on 11/17/2022.
//

#ifndef PIZZA_DRIVER_HPP
#define PIZZA_DRIVER_HPP

#include <string>
using namespace std;

#include "Time.hpp"

class Driver {
private:
    string f_name;
    string l_name;
    bool loggedIn;
    string status;
    Time timeDeparted;
    Time timeOrdered;
    int totalDeliveries;
    float totalDeliveryTime;
    float totalTripTime;
    float totalTips;
public:
    Driver(string name);
    ~Driver();
    string getName();
    bool isLoggedIn();
    void login();
    void logout();
    void setStatus(string status);
    string getStatus();
    void setDeparted(Time time);
    Time getDeparted();
    void setOrdered(Time time);
    Time getOrdered();
    void setDeliveries(int deliveries);
    int getDeliveries();
    void setDeliveryTime(float time);
    float getDeliveryTime();
    void setTripTime(float time);
    float getTripTime();
    void setTips(float tips);
    float getTips();
    void arrive(Time time);
};

// Constructor
// @pre: None
// @post: Creates a nw Driver object with the specified name data
Driver::Driver(std::string name) {
    // Split the name into first and last name
    f_name = name.substr(0, name.find(" "));
    l_name = name.substr(name.find(" ") + 1, name.length());
    loggedIn = false;
    status = "Logged out";
    totalDeliveries = 0;
    totalDeliveryTime = 0;
    totalTripTime = 0;
    totalTips = 0;
}

// Destructor
// @pre: None
// @post: Frees the space occupied by the Driver object
Driver::~Driver() {
}

// @pre: None
// @post: Returns the name data for the Driver object
string Driver::getName() {
    return f_name;
}

// @pre: None
// @post: Returns the log in status of the Driver object
bool Driver::isLoggedIn() {
    return loggedIn;
}

// @pre: None
// @post: Sets the Driver object's log in status to true and updates the status message
void Driver::login() {
    loggedIn = true;
    status = "Ready to take order";
}

// @pre: None
// @post: Sets the Driver object's log in status to false
void Driver::logout() {
    loggedIn = false;
    status = "Logged out";
}

// @pre: None
// @post: Sets the Driver object's status message
void Driver::setStatus(std::string  k_status) {
    Driver::status =k_status;
}

// @pre: None
// @post: Returns the Driver object's status message
string Driver::getStatus() {
    return status;
}

// @pre: None
// @post: Sets the Driver object's departure time
void Driver::setDeparted(Time time) {
    timeDeparted = time;
}

// @pre: None
// @post: Returns the Driver object's departure time
Time Driver::getDeparted() {
    return timeDeparted;
}

// @pre: None
// @post: Sets the time at which the Driver's current delivery was originally ordered
void Driver::setOrdered(Time time) {
    timeOrdered = time;
}

// @pre: None
// @post: Returns the time at which the Driver's current delivery was originally ordered
Time Driver::getOrdered() {
    return timeOrdered;
}


// @pre: None
// @post: Sets the Driver object's total delivery count.
void Driver::setDeliveries(int deliveries) {
    totalDeliveries += deliveries;
}

// @pre: None
// @post: Returns the total number of deliveries attributed to the Driver object
int Driver::getDeliveries() {
    return totalDeliveries;
}


// @pre: None
// @post: Sets the Driver object's total time from departure to delivery
void Driver::setDeliveryTime(float time) {
    totalDeliveryTime += time;
}

// @pre: None
// @post: Returns the Driver object's total time from departure to delivery
float Driver::getDeliveryTime() {
    return totalDeliveryTime;
}

// @pre: None
// @post: Sets the Driver object's total time from departure to return
void Driver::setTripTime(float time) {
    totalTripTime = time;
}

// @pre: None
// @post: Returns the Driver object's total time from departure to return
float Driver::getTripTime() {
    return totalTripTime;
}

// @pre: None
// @post: Sets the Driver object's total tips
void Driver::setTips(float tips) {
    totalTips += tips;
}

// @pre: None
// @post: Returns the Driver object's total tips
float Driver::getTips() {
    return totalTips;
}

void Driver::arrive(Time time) {
    totalTripTime = totalTripTime + time.getDifference(timeDeparted);
    status = "Ready to take order";
}



#endif //PIZZA_DRIVER_HPP
