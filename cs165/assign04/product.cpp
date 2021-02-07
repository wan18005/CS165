/***************************************************************
 * File: product.cpp
 * Author: Yiqi Wang
 * Purpose: Contains the method implementations for the Product class.
 ***************************************************************/

#include "product.h"
#include <iomanip>
using namespace std;

/***************************************************************
 *  put your method bodies here
 ***************************************************************/
void Product :: prompt()
{
   cout << "Enter name: ";
   getline(cin, Name);
   cout << "Enter description: ";
   getline(cin, Description);
   cout << "Enter weight: ";
   cin >> Weight;
      do
      {
         cout << "Enter price: ";
         cin >> Price;
         if (cin.fail())
         {
            cin.clear(); // clear the error state
            cin.ignore(256, '\n');
            Price = -1;
         }
      }
      while (Price < 0);
      return;
}

/*Create a getSalesTax method to that returns 6% of the base price.*/
float Product :: getSalesTax()
{
   salesTax = Price * 0.06;
   return salesTax;
}

/*Create a getShippingCost method that returns a flat rate of $2.00 
if the item is less than 5 lbs, and $2.00 + $0.10 per pound over 5 lbs.*/
float Product :: getShippingCost()
{
   if (Weight <= 5)
   {
      shippingCost = 2;
   }
   else
   {
      shippingCost = 2 + (Weight - 5)*0.10;
   }
   return shippingCost;
}

/*Advertising Profile: Should display the name, base price, and description in this format*/
void Product :: displayAds()
{
   cout << Name << " - " << "$" << Price << endl;
   cout << "(" << Description << ")" << endl;
   return;
}

/*Inventory Line Item: Should display the base price, name, and weight in this format*/
void Product :: displayInv()
{
   cout << "$" << Price << " - " << Name;
   cout << " - " << Weight << " lbs" << endl;
   return;
}

/*Receipt: Should display the name, base price, sales tax, shipping cost, and total price, in this format*/
void Product :: displayRec()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
// call sales tax and shipping cost
   getSalesTax();
   getShippingCost();

   cout << Name << "\n"
        << "  Price:"
        << setw(10) << "$"
        << setw(8) << Price << "\n";
   cout << "  Sales tax:"
        << setw(6) << "$"
        << setw(8) << salesTax << endl;
   cout << "  Shipping cost:"
        << setw(2) << "$"
        << setw(8) << shippingCost << endl;
   cout << "  Total:"
        << setw(10) << "$"
        << setw(8) << Price + salesTax + shippingCost << endl;

   return;
}


