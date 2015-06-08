#include <iostream>
#include <assert.h>

using namespace std;

class Date {

public:
  int month;
  int day;
  int year;

  Date(int month=1, int day=1, int year=1980);


  
  int compareTo(Date date2);

  
};

Date::Date(int month, int day, int year) {
    this->month = month;
    this->day = day;
    this->year = year;
};

//-1 if date1 < date2.
int Date::compareTo(Date date2) {
  
  if (this->year < date2.year)
    return -1;
  else if (this->year > date2.year)
    return 1;

  if (this->month < date2.month)
    return -1;
  else if (this->month > date2.month)
    return 1;

  if (this->day  < date2.day)
    return -1;
  else if (this->day > date2.day)
    return 1;

  
  return 0;
}


int numberOfDaysInBetweenSameYear(Date date1, Date date2) {

  int numDaysInMonths[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
  
  assert (date1.year == date2.year);
  assert (date1.compareTo(date2) == -1);
  
  int numDays;

  numDays = numDaysInMonths[date1.month]-date1.day + 1; //counting start day as 1.
  if ((date1.year % 4 == 0) && (date1.month == 2))
			     numDays++;
  for (int month = date1.month+1; month < date2.month; month++) {
    numDays += numDaysInMonths[month];
    if ((date1.year % 4 == 0) && (month == 2))
			       numDays++;
  }

  numDays += date2.day;
  return numDays;
  
}

void swap(Date &date1, Date &date2) {
  Date tmp;
  tmp   = date2;
  date2 = date1;
  date1 = tmp;
}

int numberOfDaysInBetweenTheYears(int year1, int year2)
{

  assert (year1 < year2);
  int numDays = 0;
  
  for (int year = year1+1; year < year2; year++) {
    numDays += 365;
    if (year % 4 == 0)
      numDays++;
  }
  return numDays;
  
}


Date lastDayOfYear(int year) {
  return Date(12,31,year);
}

Date firstDayOfYear(int year) {
  return Date(1,1,year);
}


int numberOfDatesBetween(Date date1, Date date2) {


  int numDays = 0;

  int cmp = date1.compareTo(date2);
  if (cmp == 0) //same date
    return 0;
  if (cmp == 1)
    swap(date1, date2);
  

  if (date2.year == date1.year) {
    numDays = numberOfDaysInBetweenSameYear(date1, date2);
  }
  else {
    
    numDays = numberOfDaysInBetweenSameYear(date1, lastDayOfYear(date1.year));
    numDays += numberOfDaysInBetweenTheYears(date1.year, date2.year);
    numDays += numberOfDaysInBetweenSameYear(firstDayOfYear(date2.year), date2);
  }
  return numDays;
}



int main() {
  Date date1(11,28,2014), date2(6,8,2015);

  cout << "num days test1 : " <<  numberOfDatesBetween( date1,  date1)  << endl;
  cout << "num days since then: " <<  numberOfDatesBetween( date1,  date2)  << endl;
  cout << "num days since then: " <<  numberOfDatesBetween( date2,  date1)  << endl;

  
}
