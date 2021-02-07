/***************************************************************
 * File: customer.h
 * Author: Yiqi Wang
 * Purpose: Contains the definition of the Customer class
 ***************************************************************/

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "address.h"

#include <string>
using namespace std;

class Customer
      {
      private:
         string name;
         Address address;

      public:
         //Getters
         string getName() const {return name;};
         Address getAddress() const {return address;};

         //Setters
         void setName(string name){this->name = name;};
         void setAddress(Address address){this->address = address;};
         void display();

         //Constructors
         Customer();

         Customer(string name, Address address);
         
      };

#endif