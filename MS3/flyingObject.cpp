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

void FlyingObject::flipSide(const bool& isY, const bool& isX)
{
	if (isY)
		point.setY(-point.getY());
	if (isX)
		point.setX(-point.getX());
}
