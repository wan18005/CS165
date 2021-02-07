/*******************
 * smartphone.cpp
 *******************/

#include "smartphone.h"

// TODO: Put your SmartPhone methods here
#include <string>
#include <iostream>
using namespace std;



void SmartPhone::prompt()
{
   Phone::promptNumber();
   cout << "Email: ";
   cin >> email;
}

void SmartPhone::display()
{
   Phone::display();
   cout << endl
        << email
        << endl;
}