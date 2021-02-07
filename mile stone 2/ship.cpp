#include "ship.h"
#include <iostream>

using namespace std;
// Put your ship methods here

void Ship :: draw()
{
    drawShip(point, direction -90, thrust);
    
};

void Ship :: applyThrust()
{
        thrust = true;
    
};

void Ship :: rotateLeft()
{
    direction = (direction + 6) % 360;
    if(direction < 0)
    {
        direction = direction += 360;
    }
}

void Ship :: rotateRight()
{
    direction = (direction - 6) % 360;
    if(direction < 0)
    {
        direction = direction += 360;
    }
}

void Ship :: advance()
{
    float movementDx = velocity.getDx();
    float movementDy = velocity.getDy();
    
    float thrustStrength = 0;
    if(thrust)
    {
        thrustStrength= 0.5;
    }
    float directionDx = thrustStrength * -cos(M_PI / 180.0 * direction);
    float directionDy = thrustStrength * sin(M_PI / 180.0 * direction);

    velocity.setDx(movementDx - directionDx);
    velocity.setDy(movementDy + directionDy);
    
    
    movementDx = velocity.getDx();
    movementDy = velocity.getDy();
    
    velocity.setDx(movementDx / 1.03);
    velocity.setDy(movementDy/ 1.03);
    
    
    point.setX(point.getX() + velocity.getDx());
    point.setY(point.getY() + velocity.getDy());
    
    if(getPoint().getX() > 200)
    {
        point.setX(200 * -1);
    }
    else if (getPoint().getX() < -200)
    {
        point.setX(-200 * -1);
    }
    if(getPoint().getY() > 200)
    {
        point.setY(200 * -1);
    }
    else if (getPoint().getY() < -200)
    {
        point.setY(-200 * -1);
    }

};


/*
 cout << "Dx before was " << movementDx;
 float tempAngle = (atan(movementDy / movementDx) * 180) / M_PI;
 float hypo =  sqrt(pow(movementDy, 2) + pow(movementDx, 2));
 
 hypo = hypo - 0;
 if(hypo < 0.0)
 {
 hypo = 0.0;
 }
 float dxWithDrag = hypo * -cos(M_PI / 180.0 * tempAngle);
 float dyWithDrag = hypo * sin(M_PI / 180.0 * tempAngle);
 */
