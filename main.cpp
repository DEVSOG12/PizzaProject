#include <iostream>
#include <string>
#include "Time.hpp"
#include "Driver.hpp"
#include "Restaurant.hpp"
#include <map>
#include <fstream>

using namespace std;


//int main()
//{
//
//        Restaurant res1, dominatos;
//        Driver dan("Dan");
//        Driver adam("Adam Sandler");
//        res1.addDriver(dan);
//        res1.addDriver(adam);
//
//        Time time1(10, 00);
//        Time time2(10, 15);
//        Time time3(10, 30);
//        Time time4(10, 45);
//        Time time5(11, 00);
//        res1.addOrder("2 cheese to 120 West Mango Lane", time1);
//        dan.login();
//
//        res1.serveNext();
//        res1.departNext(dan, time2);
//
//        res1.addOrder("7 goats to 140 Milner Avenue", time3);
//        adam.login();
//
//        res1.addOrder("12 bears to 12 Honey Badger Aquarium", time4);
//        res1.serveNext();
//
//        cout << "Report 1: "<< endl;
//        res1.status();
//        cout << endl;
//
//        res1.deliver(dan, 4.50, time4);
//        dan.arrive(time5);
//
//        cout << "Report 2: "<< endl;
//        res1.status();
//        cout << endl;
//        cout<< "\nSummary:\n";
//        res1.summary();
//
////    cout << dan.getTips() << endl;
//
//    return 0;
//}

int main () {

    Restaurant res;
    bool repeat = true;
    cout << "--------------------------------------------------------" << endl;
    cout << "?  :  View Instructions\n+  :  Add New Driver\n>  : Add Driver to Restaurant\nI  :  Log In Driver In\nO  :  Log Out Driver\nA  :  Add Order\nS  :  Serve Order\nD  :  Depart Order\n!  :  Deliver Order\nR  :  Return Driver\nT  :  View Status\nU  :  View Summary\nQ  :  Quit\n";
//    Driver dan("Dan");
//    Driver ada("Ada");
    map<string, Driver*> drivers;
//    drivers["Dan"] = &dan;
//    drivers["Ada"] = &ada;
    while (repeat) {
        char selection;
        cout << "Enter Selection: ";
        basic_string<char, char_traits<char>, allocator<char>> initial;
        cin >> selection;
        cin.ignore(); // ignore the newline character
        switch (selection) {
            // Fix White Space Issue
            case ' ':
                break;
            case '?':
                cout << "?  :  View Instructions\n+  :  Add New Driver\n>  : Add Driver to Restaurant\nI  :  Log In Driver In\nO  :  Log Out Driver\nA  :  Add Order\nS  :  Serve Order\nD  :  Depart Order\n!  :  Deliver Order\nR  :  Return Driver\nT  :  View Status\nU  :  View Summary\nQ  :  Quit\n";
                break;
            case '+': {
                string name;
                cout << "Enter Driver Name: ";
                cin >> name;
                // Check if driver already exists
                if (drivers.find(name) != drivers.end()) {
                    cout << "Driver already exists\n";
                } else {
                    auto * newDriver = new Driver(name);
                    drivers[name] = newDriver;
                    cout << "Driver added\n";

                }
                break;
            }
            case '>':{
                // Adding specified driver to restaurant
                cout << "Enter Driver's First Name: ";
                cin >> initial;
                if (drivers.find(initial) != drivers.end()) {
                    res.addDriver(*drivers[initial]);
                    cout << "Driver added to restaurant\n";
                } else {
                    cout << "Driver does not exist\n";
                }
                break;
            }
            case 'I':{
                string name;
                cout << "Enter Driver Name: ";
                cin >> name;
                if (drivers.find(name) != drivers.end()) {
                    drivers[name]->login();
                    cout << "Driver " << name << " logged in\n";
                }
                else {
                    Driver newDriver(name);
                    drivers[name] = &newDriver;
                    drivers[name]->login();
                    cout << "New Driver " << name << " logged in\n";
                }
                break;
            }
            case 'O':{
                string name;
                cout << "Enter Driver Name: ";
                cin >> name;
                if (drivers.find(name) != drivers.end()) {
                    drivers[name]->logout();
                    cout << "Driver " << name << " logged out\n";
                }
                else {
                    cout << "Driver does not exist\n";
                }
                break;
            }

            case 'A': {
                // Add order to restaurant
                string order;
                int hour, minute;
                cout << "Enter Order Name: \n";
                // Input order into string
                cin.ignore();
                getline(cin, order);
                cout << "Enter Time as follows \"hour\" \"min\": \n";
                cin >> hour >> minute;

                Time time(hour, minute);
                res.addOrder(order, time);
                cout << "Order added\n";
                break;



            }
            case 'S':{
                // Get current order about to serve
                res.serveNext();
                cout << "Order served\n";
                break;
            }
            case 'D':{
                // Select driver to depart order
                // List drivers
                cout << "Drivers: ";
                // Print List of Drivers and their status with initial
                for (auto it = drivers.begin(); it != drivers.end(); it++) {
                    cout << it->first << " : " << it->second->getStatus() << endl;
                }
                cout << "Enter Driver First Name: ";
                cin >> initial;
                if (drivers.find(initial) != drivers.end()) {
                    int hour, minute;
                    cout << "Enter Time: ";
                    cout << "Hour: ";
                    cin >> hour;
                    cout << "Minute: ";
                    cin >> minute;
                    Time time(hour, minute);
                    res.departNext(*drivers[initial], time);
                    cout << "Order departed\n";
                }
                else {
                    cout << "Driver does not exist\n";
                }
                break;
            }

            case '!':{
                // Deliver order
                cout << "Drivers: ";
                // Print List of Drivers and their status with initial
                for (auto it = drivers.begin(); it != drivers.end(); it++) {
                    cout << it->first << " : " << it->second->getStatus() << endl;
                }
                cout << "Enter Driver First Name: ";
                cin >> initial;
                if (drivers.find(initial) != drivers.end()) {
                    double tips;
                    int hour, minute;
                    cout << "Enter Tips: ";
                    cin >> tips;
                    cout << "Enter Time: ";
                    cout << "Hour: ";
                    cin >> hour;
                    cout << "Minute: ";
                    cin >> minute;
                    Time time(hour, minute);
                    res.deliver(*drivers[initial], tips, time);
                    cout << "Order delivered\n";
                    break;
                }
                else {
                    cout << "Driver does not exist\n";
                    break;
                }
            }

            case 'R': {
                // Return driver
                cout << "Drivers: ";
                // Print List of possible drivers to return by checking their status
                for (auto it = drivers.begin(); it != drivers.end(); it++) {
                    if (it->second->getStatus() == "Delivering") {
                        cout << it->first << " : " << it->second->getStatus() << endl;
                    }
                }
                cout << "Enter Driver First Name: ";
                cin >> initial;
                if (drivers.count(initial) != 0) {
                    int hour, minute;
                    cout << "Enter Time: ";
                    cout << "Hour: ";
                    cin >> hour;
                    cout << "Minute: ";
                    cin >> minute;
                    Time time(hour, minute);
                    drivers[initial]->arrive(time);
                    cout << "Driver returned\n";
                }
                else {
                    cout << "Driver does not exist\n";

                }

                break;
            }
            case 'T':{
                // View status
                res.status();
                break;
            }

            case 'U':{
                // View summary
                res.summary();
                // write summary to file output.txt
                // Create output file in current project directory if it does not exist
                ofstream output;
                // in current project directory
                // ios::app appends to file
                output.open("output.txt", ios::app);
                // Write summary to file

                output << res.Insummary();
                output.close();
                break;
            }

            case 'Q':{
                // Quit
                repeat = false;
                break;
            }

            default:
                cout << "Invalid Input\n";
                break;

        }
        cout << "--------------------------------------------------------" << endl;

    }

    return 0;
}
