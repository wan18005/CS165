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
using namespace std;
#define M_PI 3.1415
// Put your Ship class here
class Ship: public FlyingObject
{
   protected:
      bool thrust;
      int movementSpeed;
      int rotatation;
      float speedInitial;
      int size;
      int HP;
    
   public:
    
    
     void setThrust(bool thrust) { this->thrust = thrust; }
     bool getThrust() const { return thrust; }
    
     void setSize(int size) {this->size = size; }
     int getSize(){return size;}
    
     void setHP(int HP) { this->HP = HP; }
     int getHP() { return HP; }
     void setRotatation(int rotatation)
     { 
         this->rotatation = rotatation; 
     
     }
     int getRotatation() const 
     {   
         
         return rotatation; 
     }
    
     void draw();
     void applyThrust();
     void stopThrust();
     void rotateLeft();
     void rotateRight();
     void advance();
    
    Ship()
    {   
        alive = true;
        thrust = false;
        setSize(SHIP_SIZE);
        HP = 5;
        
    }

};

#endif /* ship_h */
