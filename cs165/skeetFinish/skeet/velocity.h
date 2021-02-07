/*************************************************************
 * File: velocity.h
 * Author: Yiqi Wang
 *
 * Description: header file for bullet
 *************************************************************/


#ifndef VELOCITY_H
#define VELOCITY_H
#include <iostream>
 /*********************************************
  * Velocity Class
  *********************************************/
class Velocity
{
private:
    float x;
    float y;

public:

	Velocity() {};
	Velocity(float x, float y);
	float getDx()const;
	float getDy()const;
	void setDx(float x);
	void setDy(float y);
};



#endif