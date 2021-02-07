
/***************************************************************
 * File: customer.cpp
 * Author: Yiqi Wang
 * Purpose: Contains the method implementations for the Customer class.
 ***************************************************************/

#include "customer.h"
#include "address.h"

#include <iostream>
using namespace std;

//Displays the name, then calls the address's display method. Thus the format is:
void Customer::display()
{
   cout << getName() << endl;
   address.display();
}
//Default - Set the name to "unspecified" and uses the address's default constructor.
Customer::Customer()
         {
            name = "unspecified";
            address = Address();
         }
//Non-default - Accept a name and an address object.
Customer::Customer(string name, Address address)
         {
            this->name = name;
            this->address = address;
         }