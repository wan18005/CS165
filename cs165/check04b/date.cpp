/********************************************************************
 * File: date.cpp
 * Purpose: Holds the implementation of the Date class methods.
 ********************************************************************/
#include "date.h"
#include <iostream>
using namespace std;
// Put your method bodies here...

/**********************************************************************
*  Set Date
***********************************************************************/
void Date::set(int month,int day, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

/**********************************************************************
* Display in American style
***********************************************************************/
void Date::displayAmerican()
{
    cout << month << "/" << day << "/" << year << endl;
}

/**********************************************************************
* Display in European style
***********************************************************************/
void Date::displayEuropean()
{
   cout << day << "/" << month << "/" << year << endl;
}

/**********************************************************************
Displays in the format yyyy-mm-dd
***********************************************************************/
void Date::displayISO()
{
   cout << year << "-" << month << "-" << day << endl;
}