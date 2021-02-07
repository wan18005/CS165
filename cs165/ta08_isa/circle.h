/******************************
 * File: circle.h
 * Author: Yiqi Wang
 *
 * Defines a circle class.
 ******************************/
#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include "point.h"
using namespace std;
 
class Circle : public Point
{
public:
//Add a radius to your class and a getter and setter for it.
       void setRadius(float radius);
       float getRadius();
//Create a blank method for promptForCircle and display.
       void promptForCircle();
       void display();
private:
       float radius;
};
#endif
 