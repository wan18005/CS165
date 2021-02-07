/*************************************************************
 * File: bullet.h
 * Author: Yiqi Wang
 *
 * Description: header file for bullet
 *************************************************************/
#ifndef bullet_h
#define bullet_h

#define BULLET_SPEED 5
#define BULLET_LIFE 40



// Put your Bullet class here

#include "flyingObjects.h"
#include "uiDraw.h"

 /*********************************************
  * Bullet Class from flyingObjects
  *********************************************/
class Bullet : public flyingObjects
{
public:
    Bullet();
    void fire(Point point, float angle);
    void  draw();
private:

};




#endif /* bullet_h */
