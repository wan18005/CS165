/***************************************************************
 * File: address.h
 * Author: Yiqi Wang
 * Purpose: Contains the definition of the Address class
 ***************************************************************/

#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
using namespace std;

class Address
      {
      private:
         string street;
         string city;
         string state;
         string zip;

      public:
         //Getters
         // I learn this from this week's group assigement that you can put a {} and return or do a one line code inside
         string getStreet() const {return street;};
         string getCity() const {return city;};
         string getState() const {return state;};
         string getZip() const {return zip;};

         //Setters
         void setStreet(string street){this->street = street;};
         void setCity(string city){this->city = city;};
         void setState(string state){this->state = state;};
         void setZip(string zip){this->zip = zip;};

         //Display
         void display();

         //Constructors
         Address();
         Address(string street, string city, string state, string zip);
         
      };

#endif
