#include "rocks.h"
#include <iostream>
// Put your Rock methods here


void BigRock :: draw()
{
   drawLargeAsteroid(point, spin);
};

void BigRock:: advance()
{
    spin = (spin + 2) % 360;
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
    
}
void MediumRock :: draw()
{
    drawMediumAsteroid(point, spin);
};

void MediumRock:: advance()
{
    spin = (spin + 2) % 360;
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
    
}

void SmallRock :: draw()
{
    drawSmallAsteroid(point, spin);
};

void SmallRock:: advance()
{
    spin = (spin + 2) % 360;
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
    
}
