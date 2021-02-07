/*************************************************************
 * File: rock.cpp
 * Author: Yiqi Wang
 *
 * Description: header file for flyingObject
 *************************************************************/
#include "rocks.h"
#include <iostream>
// Put your Rock methods here
#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10


void BigRock :: draw()
{
   drawLargeAsteroid(point, spin);
};

void BigRock:: advance()
{   
    spin += BIG_ROCK_SPIN;
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
    

    
void MediumRock :: draw()
{
    drawMediumAsteroid(point, spin);
};

void MediumRock:: advance()
{
    spin += MEDIUM_ROCK_SPIN;
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

void SmallRock :: draw()
{
    drawSmallAsteroid(point, spin);
};

void SmallRock:: advance()
{
    spin += SMALL_ROCK_SPIN;
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
int Rock::hit()
{
    lives = lives - 1;
    if (lives == 0)
    {
        kill();
    }

    return getScore();


}