/***********************
 * File: money.cpp
 ***********************/
#include "money.h"
#include <iostream>
#include <iomanip>
using namespace std;



/*****************************************************************
 * Function: prompt
 * Purpose: Asks the user for values for dollars and cents
 *   and stores them.
 ****************************************************************/
void Money :: prompt()
{
   int dollars;
   int cents;

   cout << "Dollars: ";
   cin >> dollars;

   cout << "Cents: ";
   cin >> cents;

   setDollars(dollars);
   setCents(cents);
}

/*****************************************************************
 * Function: display
 * Purpose: Displays the value of the money object.
 ****************************************************************/
void Money :: display() const 
{
   cout << "$" << getDollars() << ".";
   cout << setfill('0') << setw(2) << getCents();
}

//getDollars
int Money ::  getDollars()const
{
return dollars;
}

//getCents
int Money ::  getCents()const
{
return cents;
}

//setDollars
void Money ::setDollars(int dollars)
{
   int absDollars = abs(dollars);
   this -> dollars = absDollars;
}

//setCents
void Money ::setCents(int cents)
{
   int absCents = abs(cents);
   this -> cents = absCents;
}