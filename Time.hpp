//
// Created by Oreofe Solarin on 11/7/22.
//

#ifndef PIZZA_TIME_HPP
#define PIZZA_TIME_HPP

using namespace std;

class Time {

private:
    int hour;
    int minute;
public:
    Time();
    Time(int hour, int minute);
    ~Time() = default;
    void setTime(int hour, int minute);
    string getTime() const;
    float getDifference(Time time) const; // in minutes
    // overload - operator
    Time operator-(const Time &time) ; // return the difference between two times
};


// Constructor
// @pre: none
// @post: hour and minute are set to 0
// @return: none
Time::Time() {
    hour = 0;
    minute = 0;
}

// Constructor
// @pre: none
// @param: hour, minute
// @post: hour and minute are set to the values passed in as parameters
// @return: none
Time::Time(int hour, int minute) {
    this->hour = hour;
    this->minute = minute;
}

// Destructor
// @pre: none
// @post: none
// @return: none


// setTime
// @pre: none
// @param: hour, minute
// @post: hour and minute are set to the values passed in as parameters
// @return: none
void Time::setTime(int n_hour, int n_minute) {
    this->hour = n_hour;
    this->minute = n_minute;
}

// getDifference
// @pre: none
// @param: [Time] object
// @post: none
// @return: the difference between the time passed in as a parameter and the time object
float Time::getDifference(Time time) const {
    return (hour - time.hour) * 60 + (minute - time.minute);
}

// operator-
// @pre: none
// @param: [Time] object
// @post: none
// @return: the difference between the time passed in as a parameter and the time object
Time Time::operator-(const Time &time)  {
     hour = this->hour - time.hour;
     minute = this->minute - time.minute;
    return {hour, minute};
}

// getTime
// @pre: none
// @post: none
// @return: the time in the format HH:MM
std::string Time::getTime() const {
    std::string time;
    if (hour < 10) {
        time += "0";
    }
    time += std::to_string(hour) + ":";
    if (minute < 10) {
        time += "0";
    }
    time += std::to_string(minute);
    return time;
}
#endif //PIZZA_TIME_HPP
