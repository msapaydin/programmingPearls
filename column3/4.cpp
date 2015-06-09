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


int numDaysInMonths[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int numberOfDaysInBetweenSameYear(Date date1, Date date2) {

  
  
  assert (date1.year == date2.year);
  int cmp = date1.compareTo(date2);
  
  assert ( cmp <= 0);
  if (cmp == 0) return 0;
  
  int numDays;

  if (date1.month == date2.month) {
    numDays = date2.day - date1.day;
    assert (numDays > 0);
  }
  else {
    numDays = numDaysInMonths[date1.month]-date1.day + 1; //counting start day as 1.
    if ((date1.year % 4 == 0) && (date1.month == 2))
      numDays++;
    for (int month = date1.month+1; month < date2.month; month++) {
      numDays += numDaysInMonths[month];
      if ((date1.year % 4 == 0) && (month == 2))
	numDays++;
    }

    numDays += date2.day-1; // not including last day
  }
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


int numberOfDaysBetween(Date date1, Date date2) {


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
    
    numDays = numberOfDaysInBetweenSameYear(date1, lastDayOfYear(date1.year)) + 1; // there is a day between the last day of date1.year and the next year's first day.
    numDays += numberOfDaysInBetweenTheYears(date1.year, date2.year);
    numDays += numberOfDaysInBetweenSameYear(firstDayOfYear(date2.year), date2);
  }
  return numDays;
}

string  dayOfTheWeek (Date date) {
  Date today (6,8,2015);
  
  int numberOfDaysInBetween = numberOfDaysBetween(today, date);
  string daysOfTheWeekBackwards[] = {"M","N","S","F","H","W","T"};
  string daysOfTheWeekForwards[] = {"M","T","W","R","F","S","N"};
  if (today.compareTo(date)  >= 0)
    return daysOfTheWeekBackwards[numberOfDaysInBetween % 7];
  else
    return daysOfTheWeekForwards[numberOfDaysInBetween % 7];
}

void generateCalendar (int month, int year) {
  Date date(month, 1 , year);
  string dayString = dayOfTheWeek (date);
  string daysOfTheWeek[] = {"M","T","W","R","F","S","N"};
  int i;
  for (i = 0; i < 7; i++) {
    if (daysOfTheWeek[i] == dayString)
      break;
  }
  assert((daysOfTheWeek[i] == dayString));
  int dayCounter = i;
  int numDaysInWeek = 0;
  for (i = 1; i <= numDaysInMonths  [month]; i++) {
    numDaysInWeek++;
    cout << i << " ";
    if ((i % 7 == 0) || (i == numDaysInMonths[month])) {
      cout << endl;
      for (int j = i - numDaysInWeek; j < i; j++) {
	cout << daysOfTheWeek[(dayCounter + j) % 7] << " ";
	if ((j+1) /10 > 0)
	  cout << " ";
      }
      numDaysInWeek = 0;
      cout << endl;
    }
  }
}

int main() {
  Date date1(11,28,2014), date2(6,8,2015);
  Date yesterday (6,7,2015);
  Date date3(2,1,2000), date4(3,1,2000);
  Date date5(2,1,2001);
  Date date6(7,4,2015);
  
  cout << "num days test1 : " <<  numberOfDaysBetween( date1,  date1)  << endl;
  cout << "num days test2 leap year (should be 29): " <<  numberOfDaysBetween( date3,  date4)  << endl;
  cout << "num days test3 leap year (should be 366): " <<  numberOfDaysBetween( date3,  date5)  << endl;
  cout << "num days since then: " <<  numberOfDaysBetween( date1,  date2)  << endl;
  cout << "day of the week : " << dayOfTheWeek(date2) << endl;
  cout << "day of the week yesterday: " << dayOfTheWeek(yesterday) << endl;
  cout << "day of the week July 4: " << dayOfTheWeek(date6) << endl;
  generateCalendar(6, 2015);
  generateCalendar(7, 2015);
  cout << "this should be 1: " << numberOfDaysBetween(lastDayOfYear(2000), firstDayOfYear(2001)) << endl;
}
