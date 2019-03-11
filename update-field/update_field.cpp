#include "airline_ticket.h"
#include "test_runner.h"

#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <map>

using namespace std;

bool operator<(const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.year, lhs.month, lhs.day} <
        vector<int>{rhs.year, rhs.month, rhs.day};
}

bool operator==(const Date& lhs, const Date& rhs) {
    return lhs.year == rhs.year && lhs.month == rhs.month && lhs.day == rhs.day;
}

bool operator==(const Time& lhs, const Time& rhs) {
    return lhs.hours == rhs.hours && lhs.minutes == rhs.minutes;
}



ostream& operator<<(ostream& os, const Date& d) {
    os << d.year << "-" << d.month << "-" << d.day << endl;
    return os;
}


istream& operator>>(istream& is, Date& d) {
    int year;
    int month;
    int day;
    is >> year;
    is.ignore(1);
    is >> month;
    is.ignore(1);
    is >> day;
    d.year = year;
    d.month = month;
    d.day = day;
    return is;
}

istream& operator>>(istream& is, Time& t) {
    int hours;
    int minutes;
    is >> hours;
    is.ignore(1);
    is >> minutes;
    t.hours = hours;
    t.minutes = minutes;
    return is;
}

bool operator<(const Time& lhs, const Time& rhs) {
    return vector<int>{lhs.hours, lhs.minutes} <
        vector<int>{rhs.hours, rhs.minutes};
}



ostream& operator<<(ostream& os, const Time& t) {
    os << t.hours << " " << t.minutes << endl;
    return os;
}



#define UPDATE_FIELD(ticket, field, values) { \
    map<string, string>::const_iterator it;   \
    it = values.find(#field);                 \
    if (it != values.end()) {                 \
        istringstream s(it->second);          \
        s >> ticket.field;                    \
    }                                         \
}


// Реализуйте этот макрос, а также необходимые операторы для классов Date и Time

void TestUpdate() {
    AirlineTicket t;
    t.price = 0;

    const map<string, string> updates1 = {
        {"departure_date", "2018-2-28"},
        {"departure_time", "17:40"},
    };

    UPDATE_FIELD(t, departure_date, updates1);
    UPDATE_FIELD(t, departure_time, updates1);
    UPDATE_FIELD(t, price, updates1);

    ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
    ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
    ASSERT_EQUAL(t.price, 0);

    const map<string, string> updates2 = {
        {"price", "12550"},
        {"arrival_time", "20:33"},
    };
    UPDATE_FIELD(t, departure_date, updates2);
    UPDATE_FIELD(t, departure_time, updates2);
    UPDATE_FIELD(t, arrival_time, updates2);
    UPDATE_FIELD(t, price, updates2);

    // updates2 не содержит ключей "departure_date" и "departure_time", поэтому
    // значения этих полей не должны измениться
    ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
    ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
    ASSERT_EQUAL(t.price, 12550);
    ASSERT_EQUAL(t.arrival_time, (Time{20, 33}));
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestUpdate);
}
