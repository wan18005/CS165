/*************************************************************
 * File: ship.cpp
 * Author: Yiqi Wang
 *
 * Description: 
 * draw function
 * 
 *************************************************************/
#include "ship.h"
#include <iostream>

#include "uiInteract.h"
#define M_PI 3.1415
#define ROTATE_AMOUNT 6
#define StartingRotatation rotatation-85
#define initalSpeed 0;


using namespace std;
// Put your ship methods here
/*********************************************
* Ship :: draw
* draw the ship according to the uiDraw
*********************************************/
void Ship :: draw()
{   
   // from ui draw reference below:
   //void drawShip(const Point & point, int rotation, bool thrust = false);
    drawShip(point, StartingRotatation, false);
}

/*********************************************
* Ship :: applyThrust
* allow the ship to apply thrust
*********************************************/
void Ship::applyThrust()
{
    thrust = true;
}

/*********************************************
* Ship :: stopThrust
* allow the ship not to apply thrust
*********************************************/
void Ship::stopThrust()
{
    thrust = false;
}


/*********************************************
* Ship ::  rotateLeft
* allow the ship to rotate left
*********************************************/
void Ship :: rotateLeft()
{
    rotatation +=ROTATE_AMOUNT;
}

/*********************************************
* Ship ::  rotateRight
* allow the ship to rotate right
*********************************************/
void Ship :: rotateRight()
{
    rotatation -= ROTATE_AMOUNT;   
}

/*********************************************
* Ship ::  hit
* When the ship is hitted by the rock 
*********************************************/
int Ship::hit()
{
    HP = HP - 1;
    if (HP <= 0)
    {
        kill();
    }
    return getHP();
}

/*********************************************
* Ship ::  reset
* Restart the game where it is left
*********************************************/
void Ship::reset()
{
    alive = true;
    thrust = false;
    setSize(SHIP_SIZE);
    setPoint(Point(0, 0));
    setVelocity(Velocity(0, 0));
    setHP(5);
}

/*********************************************
* Ship ::  advance
* Basically doing calcuation of the thrust for the ship
* Also recalling the advance from flyingObjects like the rocks
*********************************************/
void Ship :: advance()
{   
    // get the initial dx and dy value
    float initialDx = velocity.getDx();
    float initialDy = velocity.getDy();
    // thrust value will be 0 at the begining
    float thrustValue = 0;
    // when thrust is true or appled
    if (thrust)
    {
        thrustValue = THRUST_AMOUNT;
    }

    // dx and dy after thrust
    float NewDx = thrustValue * -cos(M_PI / 180.0 * rotatation);
    float NewDy = thrustValue * sin(M_PI / 180.0 * rotatation);

    // add them together
    velocity.setDx(initialDx - NewDx);
    velocity.setDy(initialDy + NewDy);

    // get the result
    initialDx = velocity.getDx();
    initialDy = velocity.getDy();

    // set the result / 1.3(that is not to fast or slow)
    velocity.setDx(initialDx / 1.3);
    velocity.setDy(initialDy / 1.3);
    // advance function 
    FlyingObject::advance();
       


    }





