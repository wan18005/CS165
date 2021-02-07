/*************************************************************
 * File: bullet.h
 * Author: Yiqi Wang
 *
 * Description: header file for bullet
 *************************************************************/
 
 /*************************************************************
 *This is in the flying objects
 *+Bullet()
 *+getPoint() : Point
 *+getVelocity() : Velocity
 *+isAlive() : bool
 *+setPoint(Point) : void
 *+setVelocity(Velocity) : void
 *+kill() : void
  *************************************************************/
  
 /*************************************************************
 * In this header file 
 *+Bullet()
 *+advance() : void
 *+draw() : void
 *+fire(point:Point, angle:float) : void
 *************************************************************/
#ifndef Bullet_h
#define Bullet_h

#include "flyingObjects.h"
#include "uiDraw.h"


class Bullet : public flyingObjects
{
public:
    Bullet();
    void fire(Point point, float angle);
    void draw();
private:

};

#endif