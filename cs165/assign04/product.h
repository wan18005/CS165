/***************************************************************
 * File: product.h
 * Author: Yiqi Wang
 * Purpose: Contains the definition of the Product class
 ***************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H
// dont need space std here in header
#include <iostream> 
#include <iomanip>  
#include <string>   
using namespace std;

// put your class definition here
class Product
{
public:
double shippingCost;
double salesTax;
//Create a prompt function
   void prompt();
//Create a getSalesTax method
   float getSalesTax();
//Create a getShippingCost method
   float getShippingCost();
//Create a getTotalPrice method   
   float getTotalPrice();
//Create three display methods   
   void displayAds();
   void displayInv();
   void displayRec();
private:
   std::string Name;
   std::string Description;
   double Price;
   double Weight;
};
#endif
