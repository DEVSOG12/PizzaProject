//
// Created by linda on 11/22/22.


#ifndef PIZZA_PIZZARESTAURANT_H
#define PIZZA_PIZZARESTAURANT_H
#include <stdexcept>
#include <iostream>
using namespace std;
#include <string>
#include <list>
#include <queue>

#include "../Order.hpp"
#include "../Time.hpp"
#include "../Driver.hpp"

class Restaurant {

private:
    string name;
    int ordersCompleted;
    int totalOrderTime;
    list<Driver*>* drivers;
    deque<Order*>* cookingOrders;
    deque<Order*>* departingOrders;
public:
    Restaurant(string restName);


    void status();
    void summary();
    // Pre: None
    // Post: Returns driver with the assigned name.
    Driver* getDriver(string name);
    // Pre: None
    // Post: Appends  driver to the  very end of the driver's List.
    void    addDriver(Driver driver);
    // Pre: None.
    // Post: Appends order to the end of the cookingOrders list.
    void addOrder(Order order);
    // Pre: The cookingOrders deque => not empty.
    // Post: Removes the oldest order in the cookingOrders queue,and adds it to the end of the departingOrders queue.
    void serveNextOrder() throw(logic_error);
    // Pre: departingOrders queue => not empty.
    // Post: Removes the initial/oldest order in the departingOrders queue, then passes it to the driver
   // In order for Driver and Order's status constant variables to be used in the Restaurant class,
   // they must be transferred from the private area to the public section.
    Order* departNextOrder(Driver *driver, Time time) throw(logic_error);
    // Pre: The driver is delivering an order.
    // Post: is Delivering driver's held order.
    void deliver(Driver* driver, Time time, float tip) throw(logic_error);

};

#endif //PIZZA_PIZZARESTAURANT_H
