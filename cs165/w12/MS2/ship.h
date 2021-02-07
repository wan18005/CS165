/*************************************************************
 * File: ship.h
 * Author: Yiqi Wang
 *
 * Description: header file for ship
 *************************************************************/
#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5

#include "flyingObject.h"
#include "uiDraw.h"
#include "velocity.h"
#include "point.h"
#include "uiDraw.h"
#include <iostream>
#define M_PI 3.1415
// Put your Ship class here
class Ship: public FlyingObject
{
   protected:
      bool thrust;
      int movementSpeed;
      int direction;
      float speedInitial;
      int size;
    
   public:
    
    
     void setThrust(bool thrust) { this->thrust = thrust; }
     bool getThrust() const { return thrust; }
    
     void setSize(int size) {this->size = size; }
     int getSize(){return size;}
    
     void setDirection(int direction) { this->direction = direction; }
     int getDirection() const { return direction; }
    
     void draw();
     
     void rotateLeft();
     void rotateRight();
     void advance();
    
    Ship()
    {    

        //hard code right now
        movementSpeed = 60;
        speedInitial = 0;
        alive = true;
        thrust = false;
        //velocity
        velocity.setDx(speedInitial * -cos(M_PI / 180.0 * movementSpeed));
        velocity.setDy(speedInitial * sin(M_PI / 180.0 * movementSpeed));
        //location
        point.setX(0);
        point.setY(0);
        setSize(SHIP_SIZE);
        
    }

};

#endif /* ship_h */
