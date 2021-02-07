/*********************************************************************
 * File: check04b.cpp
 * Purpose: contains the main method to exercise the Date class.
 *********************************************************************/

#include "date.h"

#include <iostream>
using namespace std;

int main()
{
// prompt for month, day, year
  int month,day,year;
  cout << "Month: ";
  cin >> month;
  cout << "Day: ";
  cin >> day;
  cout << "Year: ";
  cin >> year;
  cout << endl;
// create a Date object
// set its values
   Date date;
// call each display function
  date.set(month,day,year);
	date.displayAmerican();
	date.displayEuropean();
	date.displayISO();



   return 0;
}
