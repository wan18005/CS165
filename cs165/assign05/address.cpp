/***************************************************************
 * File: address.cpp
 * Author: Yiqi Wang
 * Purpose: Contains the method implementations for the Address class.
 ***************************************************************/
#include "address.h"

#include <iostream>
using namespace std;

// display 
void Address::display()
{
   cout << street << endl;
   cout << city << ", " << state << " " << zip << endl;
}
//Constructors 
//Default - Set the street to "unknown", the zip to "00000", and the other data members to "".
Address::Address()
         {
            street ="unknown";
            city ="";
            state="";
            zip="00000";
         }
//Non-default - Accept 4 strings (street, city, state, zip) and set each of the values.
Address::Address(string street, string city, string state, string zip)
         {
            setStreet(street);
            setCity(city);
            setState(state);
            setZip(zip);
         }