#include "ship.h"
#include <iostream>

#include "uiInteract.h"
#define M_PI 3.1415
#define ROTATE_AMOUNT 6
#define StartingRotatation rotatation-85
#define FRAMES_VARIABLES_MULTIPLIER 1.03
using namespace std;
// Put your ship methods here

void Ship :: draw()
{   
    drawShip(point, StartingRotatation, thrust);
    
}
void Ship::applyThrust()
{
    thrust = true;
}

void Ship::stopThrust()
{
    thrust = false;
}
void Ship :: rotateLeft()
{
    rotatation +=ROTATE_AMOUNT;
}

void Ship :: rotateRight()
{
    rotatation -= ROTATE_AMOUNT;   
}

void Ship :: advance()
{
    
    float x = velocity.getDx();
    float y = velocity.getDy();
    float thrustA = 0;
    if (thrust)
    {
        thrustA = 0.5;
    }
    float thrustX = thrust * -cos(M_PI / 180.0 * rotatation);
    float thrustY   = thrust * sin(M_PI / 180.0 * rotatation);

        
    velocity.setDx(x - thrustX);
    velocity.setDy(y + thrustY);

    x = velocity.getDx();
    y = velocity.getDy();

    velocity.setDx(x / 1.33);
    velocity.setDy(y / 1.33);


    point.addX(velocity.getDx());
    point.addY(velocity.getDy());

    


    if (getPoint().getX() > 200)
    {
        point.setX(-200);
    }
    else if (getPoint().getX() < -200)
    {
        point.setX(200);
    }
    if (getPoint().getY() > 200)
    {
        point.setY(-200);
    }
    else if (getPoint().getY() < -200)
    {
        point.setY(200);
    }

    

}




