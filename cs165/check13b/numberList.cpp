#include "numberList.h"

#include <iostream>
using namespace std;

/******************************************************
 * Function: getNumber
 * Description: Returns the number at the given index.
 ******************************************************/
int NumberList::getNumber(int index) const
{
   int number = -1;

   if (index >= 0 && index < size)
   {
      number = array[index];
   }

   return number;
}

/******************************************************
 * Function: setNumber
 * Description: Sets the value to the array at the given index.
 ******************************************************/
void NumberList::setNumber(int index, int value)
{
   if (index >= 0 && index < size)
   {
      array[index] = value;
   }
}

/******************************************************
 * Function: displayList
 * Description: displays the list
 ******************************************************/
void NumberList::displayList() const
{
   for (int i = 0; i < size; i++)
   {
      cout << array[i] << endl;
   }

   cout << endl;
}

NumberList::NumberList(const NumberList& rhs)
{  
   // Set the size of the new list to be the same as the other one
   size = rhs.size;
   // Dynamically allocate an array of that size.
   array = new int[size];
   //Dynamically allocate an array of that size.
   for (int i = 0; i < size; i++)
   {
      array[i] = rhs.array[i];
   }
}


NumberList& NumberList::operator=(const NumberList& rhs)
{  
   //Check to see if the array is already allocated, and if so, delete it.
   if (this->array != NULL)
   {
      delete this->array;
      this->array = NULL;
   }
   // Then, do the exact same things as the copy constructor
   this->size = rhs.size;
   this->array = new int[size];
   // Finally return a reference to the current object.
   for (int i = 0; i < size; i++)
   {
      this->array[i] = rhs.array[i];
   }
   
   return *this;
}