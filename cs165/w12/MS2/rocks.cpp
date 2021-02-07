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
#define fullCircle 360

void BigRock :: draw()
{
   drawLargeAsteroid(point, spin);
};

void BigRock:: advance()
{   
    spin = (spin + BIG_ROCK_SPIN) % fullCircle;
    point.addX(velocity.getDx());
    point.addY(velocity.getDy());
}
    

    
void MediumRock :: draw()
{
    drawMediumAsteroid(point, spin);
};

void MediumRock:: advance()
{
    point.addX(velocity.getDx());
    point.addY(velocity.getDy());
    
}

void SmallRock :: draw()
{
    drawSmallAsteroid(point, spin);
};

void SmallRock:: advance()
{
    point.addX(velocity.getDx());
    point.addY(velocity.getDy());
    
}
