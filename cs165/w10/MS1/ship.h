/*************************************************************
 * File: ship.h
 * Author: Yiqi Wang
 *
 * Description: header file for all kind of birds
 *
 *************************************************************/
#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10
#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5

#include "velocity.h"
#include "point.h"
#include "uiDraw.h"
#include <iostream>


#define ANGLE_MAX 90
#define ANGLE_MIN 0
#define ANGLE_START 45

// Put your Ship class here
class Ship
{

private:
	Point point;
	Velocity velocity;
	bool alive;
	float angle;
	Point getPoint()const { return this->point; }
	Velocity getVelocity()const { return this->velocity; }
	bool isAlive() { return alive; }
	void setAlive(bool alive) { this->alive = alive; }
	
	
	
	
public:
	void advance();
	void draw();
};

#endif /* ship_h */
