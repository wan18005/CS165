/***************************************************************
 * File: rational.cpp
 * Author: (your name here)
 * Purpose: Contains the method implementations for the Rational class.
 ***************************************************************/

#include "rational.h"

#include <iostream>
using namespace std;
// put your method bodies here

void Rational::prompt()
{
	cout << "Top: ";
	cin >> top;
	cout << "Bottom: ";
	cin >> bottom;
}
//    B. Display the values in the format: "top/bottom".
void Rational::display()
{
	cout<< this->top << "/" << this->bottom << endl;
}
//    C. Display the value of the rational number in decimal format.
void Rational::displayDecimal()
{
	cout << (float)this->top / this->bottom << endl;
}
/*
void Rational::multiplyBy()
{

}

void Rational::reduce(int top, int bottom)
{

}
*/