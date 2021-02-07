/*************************************************************
 * File: flyingObject.cpp
 * Author: Yiqi Wang
 *
 * Description: header file for flyingObject
 *************************************************************/
#include "flyingObject.h"
 /*********************************************
   * FlyingObject :: advance
   * add x and y and make sure it is "wrap"
   **********************************************/
void FlyingObject::advance()
{   
    // copy from last project
    point.addX(velocity.getDx());
    point.addY(velocity.getDy());
    
    // wrap the screen
    if (point.getX() > 200)
    {
        point.setX(-200);
    }
    else if (point.getX() < -200)
    {
        point.setX(200);
    }
    else if (point.getY() > 200)
    {
        point.setY(-200);
    }
    else if (point.getY() < -200)
    {
        point.setY(200);
    }
}




