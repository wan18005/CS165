/***************************************************************
 * File: order.cpp
 * Author: Yiqi Wang
 * Purpose: Contains the method implementations for the Order class.
 ***************************************************************/

#include "order.h"
#include "customer.h"
#include "address.h"

#include <string>
#include <iostream>
using namespace std;

//Displays the customer's name, the product's name, and the total price of the order in this format (substituting for the correct values):
void Order::displayInformation()
{
   cout << customer.getName() << endl;
   cout << product.getName() << endl;
   cout << "Total Price: $" << getTotalPrice() << endl;
}

//Returns the Zip from the customer's address
string Order::getShippingZip()
{
   Address temp = customer.getAddress();
   return temp.getZip();
}
//Default - Set the quantity to 0 and uses the product and customer's default constructors.
Order::Order()
   {
      product = Product ();
      customer = Customer ();
      quantity = 0;
   }
//Non-default - Accepts a Product, quantity, and Customer
Order::Order(Product product, int quantity, Customer customer)
   {
      this->product = product;
      this->customer = customer;
      this->quantity = quantity;
   }