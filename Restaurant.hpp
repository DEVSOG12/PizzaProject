//
// Created by Greta Heiser on 11/20/22.
//

#ifndef PIZZA_RESTAURANT_HPP
#define PIZZA_RESTAURANT_HPP

#include <iostream>
#include <string>
#include <list>
#include <queue>
using namespace std;

#include "Driver.hpp"
#include "Time.hpp"
#include "Order.hpp"

class Restaurant {
private:
    vector<Driver*> drivers;
    queue<Order*> cooking;
    queue<Order*> ready;
    int grandTotalDelivered;
    float totalDeliveryTime;
public:
    Restaurant();
    void addDriver(Driver & driver);
    void addOrder(string info, Time time);
    void serveNext();
    void departNext(Driver & driver, Time & time);
    void status();
    void deliver(Driver & driver, float tip, Time time);
    void summary();
};

// Constructor
// pre: none
// post: New restaurant object is created with an empty list for drivers, empty queues for cooking
// and ready orders, and grand total delivered and total delivery time set to 0
Restaurant::Restaurant() {
    grandTotalDelivered = 0;
    totalDeliveryTime = 0;
}

// pre: none
// post: adds the given order to the system
void Restaurant::addDriver(Driver & driver) {
    drivers.push_back(&driver);
}

// pre: none
// post: adds the order to the system by enqueueing to cooking queue
void Restaurant::addOrder(std::string info, Time time) {
    Order * newOrder;
    newOrder = new Order(info, time);
    cooking.push(newOrder);
}

// pre: cooking queue is not empty
// post: removes the oldest order in the cooking queue and enqueues it to ready to depart queue
void Restaurant::serveNext() {
    if (!cooking.empty()) {
        ready.push(cooking.front());
        cooking.pop();
    }
}

// pre: ready queue is not empty
// post: removes the oldest order in the ready to depart queue and assigns it to a driver
void Restaurant::departNext(Driver & driver, Time & time) {
    if (driver.isLoggedIn() && driver.getStatus() == "Ready to take order" && !ready.empty()) {
        driver.setStatus(ready.front()->getTime().getTime() + " " + ready.front()->getName());
        driver.setOrdered(ready.front()->getTime());
        driver.setDeparted(time);
        delete ready.front();
        ready.pop();
    }
}

// pre: specified driver is on a delivery
// post: delivers the order and sets the driver to returning
void Restaurant::deliver(Driver & driver, float tip, Time time) {
    if (driver.isLoggedIn() && (driver.getStatus() != "Ready to take order" && driver.getStatus() != "Returning")) {
        grandTotalDelivered += 1;
        totalDeliveryTime += time.getDifference(driver.getOrdered());
        driver.setDeliveryTime(time.getDifference(driver.getDeparted()));
        driver.setDeliveries(1);
        driver.setStatus("Returning");
        driver.setTips(tip);
    }
}

// pre: none
// post: prints out the status information
void Restaurant::status() {
    cout << "Orders waiting to cook: " << endl;
    queue<Order*> printCooking = cooking;
    while(!printCooking.empty()) {
        cout << (printCooking.front())->getName() << endl;
        printCooking.pop();
    }

    cout << "Orders waiting to depart: " << endl;
    queue<Order*> printReady = ready;
    while(!printReady.empty()) {
        cout << printReady.front()->getName() << endl;
        printReady.pop();
    }

    cout << "Drivers: " << endl;
    for (int i = 0; i < drivers.size(); i++) {
        if(drivers[i]->isLoggedIn())
            cout <<  drivers[i]->getName() << ": " << drivers[i]->getStatus() << endl;
    }
}

// pre: none
// post: prints out the summary information
void Restaurant::summary() {

    if (grandTotalDelivered == 0)
        cout << "incomplete orders." << endl;
    else {
        cout << "Number of orders completed: " << grandTotalDelivered << endl;
        cout << "Average time per order: " << totalDeliveryTime/grandTotalDelivered << endl;
    }

    for (auto it: drivers) {
        cout << "Driver " << it->getName() << ":" << endl;
        cout << "Number of deliveries completed: " << it->getDeliveries() << endl;
        cout << "Average time per delivery: " << it->getDeliveryTime() << endl;
        cout << "Total driving time: " << it->getTripTime() << endl;
        cout << "Total tips: " << it->getTips() << endl;
    }
}

#endif //PIZZA_RESTAURANT_HPP
