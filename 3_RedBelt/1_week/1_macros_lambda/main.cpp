/*
Разработать макрос - лямбда функцию
https://www.coursera.org/learn/c-plus-plus-red/programming/pLm4e/gienierator-komparatorov/submission
*/


#include <iostream>
#include <bits/stdc++.h>
#include "test_runner.h"

#include "test_runner.h"

#include <string>
#include <vector>
#include <list>
#include <forward_list>
#include <numeric>
#include <iterator>



#include "airline_ticket.h"
#include "test_runner.h"

#include <algorithm>
#include <numeric>


using namespace std;


// MY CODE
#define SORT_BY(field) \
([](const AirlineTicket& lhs, const AirlineTicket& rhs) { \
    return lhs.field < rhs.field;})

tuple<int, int, int> get_date(const Date& d) {
    return make_tuple(d.year, d.month, d.day);
}


bool operator==(const Date& lhs, const Date& rhs) {
    return get_date(lhs) == get_date(rhs);
}


bool operator<(const Date& lhs, const Date& rhs) {
    return get_date(lhs) < get_date(rhs);
}

ostream& operator<<(ostream& os, const Date& d) {
    return os << d.day;
}

bool operator<(const Time& lhs, const Time& rhs) {
    return make_pair(lhs.hours, lhs.minutes) < make_pair(rhs.hours, rhs.minutes);
}

bool operator==(const Time& lhs, const Time& rhs) {
    return make_pair(lhs.hours, lhs.minutes) == make_pair(rhs.hours, rhs.minutes);
}

// END of MY CODE


void TestSortBy() {
  vector<AirlineTicket> tixs = {
    {"VKO", "AER", "Utair",     {2018, 2, 28}, {17, 40}, {2018, 2, 28}, {20,  0}, 1200},
    {"AER", "VKO", "Utair",     {2018, 3,  5}, {14, 15}, {2018, 3,  5}, {16, 30}, 1700},
    {"AER", "SVO", "Aeroflot",  {2018, 3,  5}, {18, 30}, {2018, 3,  5}, {20, 30}, 2300},
    {"PMI", "DME", "Iberia",    {2018, 2,  8}, {23, 00}, {2018, 2,  9}, { 3, 30}, 9000},
    {"CDG", "SVO", "AirFrance", {2018, 3,  1}, {13, 00}, {2018, 3,  1}, {17, 30}, 8000},
  };

  sort(begin(tixs), end(tixs), SORT_BY(price));
  ASSERT_EQUAL(tixs.front().price, 1200);
  ASSERT_EQUAL(tixs.back().price, 9000);

  sort(begin(tixs), end(tixs), SORT_BY(from));
  ASSERT_EQUAL(tixs.front().from, "AER");
  ASSERT_EQUAL(tixs.back().from, "VKO");

  sort(begin(tixs), end(tixs), SORT_BY(arrival_date));
  ASSERT_EQUAL(tixs.front().arrival_date, (Date{2018, 2, 9}));
  ASSERT_EQUAL(tixs.back().arrival_date, (Date{2018, 3, 5}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestSortBy);
}
