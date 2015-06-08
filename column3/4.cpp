#include <iostream>

using namespace std;

class Date {

public:
  int month;
  int day;
  int year;

  Date(int month, int day, int year);
  
};

Date::Date(int month, int day, int year) {
    this->month = month;
    this->day = day;
    this->year = year;
};


int numberOfDatesBetween(Date date1, Date date2) {
  int numDaysInMonths[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
  int numDays = 0;
  
  if (date1.year > date2.year) {
    cout << "dont handle this at the moment." << endl;
  }
  else if (date2.year > date1.year) {
    numDays = numDaysInMonths[date1.month]-date1.day + 1; //counting start day as 1.
    for (int month = date1.month+1; month <= 12; month++) {
      numDays += numDaysInMonths[month];
    }
    if (date1.year % 4 == 0)
      numDays++;
    for (int year = date1.year+1; year < date2.year; year++) {
      numDays += 365;
      if (year % 4 == 0)
	numDays++;
    }
    for (int month = 1; month < date2.month; month++) {
      numDays += numDaysInMonths[month];
      if ((month == 2) && (date2.year % 4 == 0))
	numDays++;
    }
    numDays += date2.day;
  }
  else {
    cout << "dont handle this at the moment either" << endl;
  }
  return numDays;
}



int main() {
  Date date1(11,28,2014), date2(6,8,2015);
  cout << "num days since then: " <<  numberOfDatesBetween( date1,  date2)  << endl;
}
