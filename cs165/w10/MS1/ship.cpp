/*************************************************************
 * File: ship.cpp
 * Author: Yiqi Wang
 *
 * Description: All the running function for different kinds of bird
 *
 *************************************************************/
#include "ship.h"
#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5
#include <cassert>
#include "point.h"
#include "uiDraw.h"

// Put your ship methods here


void Ship::advance()
{

		point.addX(velocity.getDx());
		point.addY(velocity.getDy());
}

void Ship::draw()
{   
	drawShip(point, ROTATE_AMOUNT, THRUST_AMOUNT);
}


