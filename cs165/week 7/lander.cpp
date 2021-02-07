/*************************************************************
 * File: lander.cpp
 * Author: Yiqi Wang
 *
 * Description: Contains the implementations of the
 *  method bodies for the lander class.
 *
 * This file will contain input validation for the lander set functions in
 *      the future.
 *************************************************************/
#include "lander.h"
#include "uiDraw.h"
#define HOR_THRUST  0.1  // right
#define VER_THRUST  0.3  // up 
#define HOR_FUEL  1      // Fuel cost
#define VER_FUEL  3      // Fuel cost


/***************************************
* APPLY GRAVITY
* Applies gravitational move down
***************************************/
void Lander::applyGravity(float gravity)
{
    // set the new Dy as the Dy getted - gravity
    landerVel.setDy (landerVel.getDy() - gravity);
}

/***************************************
* APPLY THRUST LEFT
* Applies thrust on the left
* ship move right
***************************************/
void Lander::applyThrustLeft()
{
   if (canThrust())
   {
     landerVel.setDx(landerVel.getDx() + HOR_THRUST);
     setFuel(getFuel() - HOR_FUEL);
     drawLanderFlames(position,false,true,false);
     //void drawLanderFlames(const Point & point,bool bottom,bool left,bool right)
   }
}

/***************************************
* APPLY THRUST RIGHT
* Applies thrust on the right 
* ship move left
***************************************/
void Lander::applyThrustRight()
{
   if (canThrust())
   {
     landerVel.setDx(landerVel.getDx() - HOR_THRUST );
     setFuel(getFuel() - HOR_FUEL);
     drawLanderFlames(position,false,false,true);
     //void drawLanderFlames(const Point & point,bool bottom,bool left,bool right)
   }

}

/***************************************
* APPLY THRUST BOTTOM
* Applies thrust on the bottom 
* ship move up
***************************************/
void Lander::applyThrustBottom()
{
   if (canThrust() && (getFuel() >= VER_FUEL ))
   {
     landerVel.setDy(landerVel.getDy() + VER_THRUST );
     setFuel(getFuel() - VER_FUEL);
     drawLanderFlames(position,true,false,false);
     //void drawLanderFlames(const Point & point,bool bottom,bool left,bool right)
   }

}

/***************************************
* ADVANCE
***************************************/
void Lander::advance()
{
  position.setX (position.getX () + landerVel.getDx ());
  position.setY (position.getY () + landerVel.getDy ());
}


/***************************************
* DRAW
***************************************/
void Lander::draw()
{
	drawLander(position);
}

/***************************************
* REST
***************************************/
void Lander::reset()
{
    setFuel(getFuel() + 500);
}