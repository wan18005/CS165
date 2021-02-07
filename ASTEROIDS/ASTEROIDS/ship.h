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
      int rotatation;
      int size;
      int HP;
      bool thrust;
   public:

       Ship()
       {
           alive = true;
           thrust = false;
           setSize(SHIP_SIZE);
           setHP(5);
       }
    
    
/*********************************************
* Ship :: setSize
* setSize for the ship
*********************************************/
void setSize(int size) 
{
   this->size = size; 
}

/*********************************************
* Ship :: getSize
* getSize for the ship
*********************************************/
 int getSize()
{
    return size;
}

/*********************************************
* Ship :: setHP
* set the HP for the ship
*********************************************/
void setHP(int HP) 
{ 
   this->HP = HP; 
}

/*********************************************
* Ship :: getHP
* get the HP for the ship
*********************************************/
int getHP() 
{ 
   return HP; 
}

/*********************************************
* Ship :: setRotatation angle
* set the Rotatation angle for the ship
*********************************************/
void setRotatation(int rotatation)
{ 
   this->rotatation = rotatation; 
}

/*********************************************
* Ship :: getRotatation angle
* get the Rotatation angle for the ship
*********************************************/
int getRotatation() const 
{         
   return rotatation; 
}


/*********************************************
* Ship :: cpp file run function
*********************************************/
    
void applyThrust();
void stopThrust();
void rotateLeft();
void rotateRight();
     
void draw();
void advance();
int hit();
void reset();

};

#endif 
