//
// Created by linda on 11/22/22.
//
#include "PizzaRestaurant.h"
#include "../Driver.hpp"
#include "../Order.hpp"

Restaurant::Restaurant(string resName) {
    name = resName;
    totalOrderTime = 0;
    ordersCompleted = 0;

    drivers = new list<Driver*>;
    cookingOrders = new deque<Order*>;
    departingOrders = new deque<Order*>;

}

void Restaurant::status() {
    cout << "Status of restaurant: " << name << endl;

    cout << "Orders waiting to be cooked:" << endl;
    for (auto it = cookingOrders->begin() ; it != cookingOrders->end(); ++it) {
        cout << (*it)->tostring() << endl;
    }

    cout << "Orders which are waiting to depart:" << endl;
    for (auto it = departingOrders->begin() ; it != departingOrders->end(); ++it) {
        cout << (*it)->toString() << endl;
    }

    cout << "Drivers:" << endl;
    for (auto it = drivers->begin() ; it != drivers->end(); ++it) {
        cout << (*it)->toString() << endl;
    }
}

void Restaurant::summary() {
    cout << "Summarizing operations of the restaurant: " << name << endl;

    for (auto it = drivers->begin() ; it != drivers->end(); ++it) {
        totalOrderTime += (*it)->getDeliveryTime(); //
    }

    if (ordersCompleted == 0)
        cout << "incomplete orders." << endl;
    else {
        cout << "Number of orders completed: " << ordersCompleted << endl;
        cout << "Average time per order: " << totalOrderTime/ordersCompleted << endl;
    }

    cout << "Drivers:" << endl;
    for (auto it = drivers->begin() ; it != drivers->end(); ++it) {
        cout << (*it)->toString() << endl;
    }
}
void Restaurant::addDriver(Driver driver) {
    drivers->push_back(&driver);
}

void Restaurant::addOrder(Order order) {
    cookingOrders->push_back(&order);
}

void Restaurant::serveNextOrder() throw(logic_error) {
    if (cookingOrders->size() == 0)
        throw logic_error("There are zero orders waiting to be served.");

    departingOrders->push_back(cookingOrders->front());
    cookingOrders->pop_front();
}

void Restaurant::deliver(Driver *driver, Time time, float tip) throw(logic_error) {
    ordersCompleted += 1;
    driver->deliver(time, tip);
}

Order* Restaurant::departNextOrder(Driver *driver, Time time) throw(logic_error) {
    if (departingOrders->size() == 0)
        throw logic_error("There are zero orders waiting to depart.");
    driver->setDeparted(time);

    departingOrders->pop_front();
}

