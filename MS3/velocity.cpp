/*************************************************************
 * File: velocity.cpp
 * Author: Yiqi Wang
 *
 * Description: cpp file for bullet
 *************************************************************/


// Put your velocity methods here
#include "velocity.h"


 /*********************************************
  * Velocity Class
  *********************************************/
Velocity::Velocity(float x, float y)
{
	this->x = x;
	this->y = y;
}
/*********************************************
 * Velocity Class: getter
 *********************************************/
float Velocity::getDx()
{
	return this->x;
}
/*********************************************
 * Velocity Class: getter
 *********************************************/
float Velocity::getDy()
{
	return this->y;
}
/*********************************************
 * Velocity Class: setter
 *********************************************/
void Velocity::setDx(float x)
{
	this->x = x;
}
/*********************************************
 * Velocity Class: setter
 *********************************************/
void Velocity::setDy(float y)
{
	this->y = y;
}