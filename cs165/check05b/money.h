/******************
 * File: money.h
 ******************/
#ifndef MONEY_H
#define MONEY_H

class Money
{
private:
   int dollars;
   int cents;

   


public:
   void prompt();
   void display() const;

   int getDollars() const;
   int getCents() const;
   void setDollars(int dollars);
   void setCents(int cents);
   Money () //Default - Set the values to 0
   {
      setDollars (0);
      setCents (0);
   }

   Money (int dollars)//Non-default that accepts 1 integer - Sets the dollar amount to that integer, sets the cents to 0.
   {
      setDollars (dollars);//Non-default that accepts 2 integers - Sets the dollar amount to the first, and the cents to the second.
      setCents (0);
   }

   Money (int dollars, int cents)
   {
      setDollars (dollars);
      setCents (cents);
   }
};

#endif