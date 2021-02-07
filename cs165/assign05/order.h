  /***************************************************************
 * File: order.h
 * Author: Yiqi Wang
 * Purpose: Contains the definition of the Order class
 ***************************************************************/

#ifndef ORDER_H
#define ORDER_H

#include "product.h"
#include "customer.h"

#include <string>
using namespace std;

class Order
{
private:
   Product product;
   Customer customer;
   int quantity;

public:

//Getters
   Product getProduct() const {return product; };
   Customer getCustomer() const {return customer; };
   int getQuantity() const {return quantity; };
   string getShippingZip();
   double getTotalPrice() {return (quantity * product.getTotalPrice ());};
//Setters
   void setProduct(Product product){this->product = product;};
   void setCustomer(Customer customer){this->customer = customer;};
   void setQuantity(int quantity){this->quantity = quantity;};
//Default constructor
   Order();
//Non-Default constructor
   Order(Product product, int quantity, Customer customer);

//Display
   void displayShippingLabel() {customer.display();};
   void displayInformation();
};
#endif