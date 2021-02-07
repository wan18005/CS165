#include "ship.h"
#include <iostream>
#define M_PI 3.1415
#define ROTATE_AMOUNT 6
#define rightAngle 90.0
#define fullCircle 360
using namespace std;
// Put your ship methods here

void Ship :: draw()
{   
    drawShip(point, direction-rightAngle, thrust);
    
}



void Ship :: rotateLeft()
{
    direction = (direction + ROTATE_AMOUNT) % fullCircle;
    
    
}

void Ship :: rotateRight()
{
    direction = (direction - ROTATE_AMOUNT) % fullCircle;
    
}

void Ship :: advance()
{
    point.addX(velocity.getDx());
    point.addY(velocity.getDy());
   
    
}




