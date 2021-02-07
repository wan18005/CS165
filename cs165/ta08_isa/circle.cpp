/*********************************************
 * File: circle.cpp
 * Author: Yiqi Wang
 *
 * Contains the methods for the circle class.
 **********************************************/
#include "circle.h"
 
 
void Circle::setRadius(float radius)
{
   this->radius = radius;
}
float Circle::getRadius()
{
    return this->radius;
}

void Circle::promptForCircle()
{
   promptForPoint();
   cout << "Enter radius: ";
   cin >> this->radius;
}

void Circle::display()
{
   Point::display();
   cout << "- Raidus: " << getRadius() << endl;
}