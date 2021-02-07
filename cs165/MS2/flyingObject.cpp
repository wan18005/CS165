/*************************************************************
 * File: flyingObject.cpp
 * Author: Yiqi Wang
 *
 * Description: header file for flyingObject
 *************************************************************/
#include "flyingObject.h"

void FlyingObject::advance()
{
    point.addX(velocity.getDx());
    point.addY(velocity.getDy());
}


