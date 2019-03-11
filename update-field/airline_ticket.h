#pragma once

#include <string>

using namespace std;

struct Date {
    Date(int new_year, int new_month, int new_day) {
        year = new_year;
        month = new_month;
        day = new_day;
    }

    Date() = default;

  int year, month, day;
};

struct Time {
    Time(int new_hour, int new_minute) {
        hours = new_hour;
        minutes = new_minute;
    }

    Time() = default;
  int hours, minutes;
};

struct AirlineTicket {
  string from;
  string to;
  string airline;
  Date departure_date;
  Time departure_time;
  Date arrival_date;
  Time arrival_time;
  int price;
};
