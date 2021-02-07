/***********************************************************************
 * Header File:
 *    Lander : The representation of lander for the game
 * Author:
 *    Yiqi Wang
 * Summary:
 *    Contains all the various state variables the lander object
 *    REQUIRED FILES INCLUDED:
 *          POINT.H
 *          VELOCITY.H
 ************************************************************************/

#ifndef LANDER_H
#define LANDER_H

#include "point.h"
#include "velocity.h"

class Lander
{
private:
   Point position;
   Velocity landerVel;
   bool alive;
   bool landed;
   bool thrust;
   int fuel;

public:
   //getters
   Point getPoint() const { return position;};
   Velocity getVelocity() const { return landerVel;};

   int getFuel(){ return fuel;}
   bool isAlive(){ return alive;}
   bool isLanded(){ return landed;}
   bool canThrust(){ return thrust;}

   //setters
   void setPoint(Point point){position=point;}
   void setVelocity(Velocity velocity){landerVel = velocity;}
   void setFuel(int fuel){this->fuel = fuel;}
   void setAlive(bool alive){this->alive = alive;}
   void setLanded(bool landed){this->landed = landed;}
   void setCanThrust(bool thrust){this->thrust = thrust;}

   //constructors
   Lander()
   {
      setVelocity(Velocity());
      setPoint(Point());
      setAlive(true);
      setLanded(false);
      setCanThrust(true);
      setFuel(500);
   }

   Lander(Point point, Velocity velocity, bool alive, bool landed, bool
   thrust, int fuel)
   {
      setPoint(point);
      setVelocity(velocity);
      setAlive(alive);
      setLanded(landed);
      setCanThrust(thrust);
      setFuel(fuel);
   }

   //functions in cpp
   void applyGravity(float gravity);
   void applyThrustLeft();
   void applyThrustRight();
   void applyThrustBottom();
   void advance();
   void reset();
   void draw();
};


#endif
