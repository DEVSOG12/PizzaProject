//
// Created by Oreofe Solarin on 11/8/22.
//

#ifndef PIZZA_ORDER_HPP
#define PIZZA_ORDER_HPP

#include <string>
using namespace std;

#include "Time.hpp"

class Order {
private:
    string name;
    Time time;
public:
    Order();
    Order(string name, Time time);
    ~Order();
    string getName();
    Time getTime();
    void setName(string name);
    void setTime(Time time);
};

// Constructor
// @pre: none
// @post: name and time are set to empty string and 0
// @return: none
Order::Order() {
    name = "";
    time.setTime(0, 0);
}

// Constructor
// @pre: none
// @param: name, time
// @post: name and time are set to the values passed in as parameters
// @return: none
Order::Order(string name, Time time) {
    this->name = name;
    this->time = time;
}

// Destructor
// @pre: none
// @post: none
// @return: none
Order::~Order() = default;

// getName
// @pre: none
// @post: none
// @return: name
string Order::getName() {
    return name;
}

// getTime
// @pre: none
// @post: none
// @return: time
Time Order::getTime() {
    return time;
}

// setName
// @pre: none
// @param: name
// @post: name is set to the value passed in as parameter
// @return: none
void Order::setName(string n_name) {
    this->name = n_name;
}

// setTime
// @pre: none
// @param: time
// @post: time is set to the value passed in as parameter
// @return: none
void Order::setTime(Time n_time) {
    this->time = n_time;
}

#endif //PIZZA_ORDER_HPP
