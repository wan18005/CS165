/*************************************************************
 * File: velocity.cpp
 * Author: Yiqi Wang
 *
 * Description: cpp file for bullet
 *************************************************************/


// Put your velocity methods here
#include "velocity.h"

/*************************************************************
* Velocity::Velocity
**********************************************/
Velocity::Velocity(float x, float y)
{
	this->x = x;
	this->y = y;
}

/*********************************************
 * Velocity :: setDX
 *********************************************/
void Velocity::setDx(float x)
{
	this->x = x;
}
/*********************************************
 * Velocity :: setDy
 *********************************************/
void Velocity::setDy(float y)
{
	this->y = y;
}
/*********************************************
 * Velocity :: getDX
 *********************************************/
float Velocity::getDx()
{
	return this->x;
}
/*********************************************
 * Velocity :: getDy
 *********************************************/
float Velocity::getDy()
{
	return this->y;
}

