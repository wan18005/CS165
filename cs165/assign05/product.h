/***************************************************************
 * File: product.h
 * Author: Yiqi Wang
 * Purpose: Contains the definition of the Product class
 ***************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class Product
{
private:
   string name;
   string description;
   double basePrice;
   double weight;

   string getUserInput(string prompt);
   double getUserInput(string prompt, int difference);
   bool isValid(int subject);
   bool isValid(double subject);

public:
   // assigin 04
   void prompt();
   double getSalesTax();
   double getShippingCost();
   double getTotalPrice();
   void displayAdvertisingProfile();
   void displayInventoryLineItem();
   void displayReceipt();

   //Setter
   void setName(string name){this->name = name;}
   void setDescription(string description){this->description = description;}
   void setBasePrice(double basePrice){this->basePrice = basePrice;}
   void setWeight(double weight){this->weight = weight;}
   //Getter
   string getName() const {return name;}
   string getDescription() const {return description;}
   double getBasePrice() const {return basePrice;}
   double getWeight() const {return weight;}
   //Constructor
   Product();
   Product(string name, string description, double basePrice, double weight);
   
};

#endif