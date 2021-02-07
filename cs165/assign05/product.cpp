  /***************************************************************
 * File: product.cpp
 * Author: Yiqi Wang
 * Purpose: Contains the method implementations for the Product class.
 ***************************************************************/

#include "product.h"

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;


// prompt, I spend some time upgrading my prompt so it can handle both string and double
void Product::prompt()
{
// first two is for string
   cout << "Enter name: ";
   name = getUserInput("name");

   cout << "Enter description: ";
   description = getUserInput("description");
// Second two is for double
   cout << "Enter weight: ";
   weight = getUserInput("weight", 1); // I learn this method from another student, This will pass in what is in the () to the function

   cout << "Enter price: ";
   basePrice = getUserInput("price", 1); // the one here will give the difference from double and string
}

// get input
string Product::getUserInput(string prompt)
{
   string String; //first declare a string
   bool TEST = false; // set test to false
   int length;    // and a int for the length of the string

   do
   {
      getline(cin, String);
      length = String.length();

      if(isValid(length))   // if yes turn true 
         TEST = true;
      else
      {
         cout << "Enter " << prompt << ": ";
      }
   }while (!TEST);

   return String;
}


double Product::getUserInput(string prompt, int difference)
{
   double Double;
   bool TEST = false;

   do
   {
      cin >> Double;
      if(cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');
         Double = -1;
      }

      if(isValid(Double))
      {
         TEST = true;
      } else
      {
         cout << "Enter " << prompt << ": ";
         Double = -1;
      }
   }while (!TEST);

   return Double;
}

//check of valid
bool Product::isValid(int subject)
{
   if(subject < 1)    //if the string is small than one character
   {
      return false;
   }
   else return true;
}

// check of valid 
bool Product::isValid(double subject) // if the double is at least bigger then 0
{
   if(subject <= 0.0)
   {
      return false;
   }
   else return true;
}

// here is from my assign 4 but I change the name for price so i dont get confused
//getSalesTax
double Product::getSalesTax()
{
   return (0.06 * basePrice);
}

//getShippingCost
double Product::getShippingCost()
{
   double shippingCost = 2.0;

   if(weight > 5.0)
   {
      shippingCost += ((weight - 5.0) * 
            0.1);
   }

   return shippingCost;
}

//getTotalPrice
double Product::getTotalPrice ()
{
   return (basePrice + getSalesTax () + getShippingCost ());
}

//displayAdvertisingProfile
void Product::displayAdvertisingProfile ()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << name << " - $" << basePrice << endl;
    cout << "(" << description << ")" << endl;
}

//displayInventoryLineItem
void Product::displayInventoryLineItem ()
{
   cout.precision(2);
   cout << "$" << basePrice << " - " << name;
   cout.precision(1);
   cout << " - " << weight << " lbs" << endl;
}


//displayReceipt
void Product::displayReceipt ()
{
   cout.precision(2);
   cout << name << endl;
   cout << "  " << "Price:" << setw(10) << "$" << setw(8) << basePrice << endl;
   cout << "  " << "Sales tax:"
        << setw(6) << "$" << setw(8) << getSalesTax () << endl;
   cout << "  " << "Shipping cost:"
        << setw(2) << "$" << setw(8) << getShippingCost() << endl;
   cout << "  " << "Total:" << setw(10) << "$" << setw(8) << getTotalPrice()
        << endl;
}

//Default Constructor- Set the name to "none", description to "", and the weight and the base price to 0
Product::Product()
   {
      name = "none";
      description = "";
      basePrice = 0;
      weight = 0;
   }
//Non-default - Accepts all four of these values (name, description, basePrice, weight) and sets them.
Product::Product(string name, string description, double basePrice, double weight)
   {
      setName (name);
      setDescription (description);
      setBasePrice (basePrice);
      setWeight (weight);
   }