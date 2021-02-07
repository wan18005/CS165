/*****************************************************
 * File: pair.h
 *
 * Purpose: Defines a Pair template class that can hold
 *   two items of arbitrary data types.
 ******************************************************/

#ifndef PAIR_H
#define PAIR_H

// TODO: Fill in this class
// Put all of your method bodies right in this file
#include <iostream>

template<class T1 , class T2>
class Pair
{
   private:
   	T1 t1;
   	T2 t2;
   public:
   	T1 getFirst() const{return t1;}
   	void setFirst(T1 first){ t1 = first;}
   	T2 getSecond() const{return t2;}
   	void setSecond(T2 second){t2 = second;}
    
    void display()
    {
      cout << t1 << " - " << t2;
    }

};

#endif // PAIR_H
