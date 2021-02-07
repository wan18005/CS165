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

/*********************************************
* Big Rock :: Draw
* draw the big rock according to the uidraw
* void drawLargeAsteroid( const Point & point, int rotation);
**********************************************/

void BigRock :: draw()
{ 
   drawLargeAsteroid(point, spin);
}

/*********************************************
* Big Rock :: Advance
* Advance function of the big rock
* inhert from the flying object big rock 
* Add the spin according to the size of the rock
**********************************************/
void BigRock:: advance()
{   
    FlyingObject::advance();
    spin += BIG_ROCK_SPIN;

}

/*********************************************
* Big Rock :: hit
* Hit function for the big rock
* When it is hit by the bullet it lost 1 health 
* and return the score we set for rock
**********************************************/
int BigRock::hit() 
{
    lives = lives - 1;
    if (lives <= 0)
    {
        kill();
    }
    return getScore();

}
    
/*********************************************
* Medium Rock :: Draw
* draw the medium rock according to the uidraw
* void drawMediumAsteroid(const Point & point, int rotation);
**********************************************/
    
void MediumRock :: draw()
{
    drawMediumAsteroid(point, spin);
}

/*********************************************
* Medium Rock :: Advance
* Advance function of the medium rock
* inhert from the flying object medium rock
* Add the spin according to the size of the rock
**********************************************/
void MediumRock:: advance()
{
    spin += MEDIUM_ROCK_SPIN;
    FlyingObject::advance();

    
}


/*********************************************
* Medium Rock :: hit
* Hit function for the medium rock
* When it is hit by the bullet it lost 1 health
* and return the score we set for rock
**********************************************/
int  MediumRock::hit()
{
    lives = lives - 1;
    if (lives <= 0)
    {
        kill();
    }
    return getScore();;

}

/*********************************************
* Small Rock :: Draw
* draw the small rock according to the uidraw
* void drawSmallAsteroid( const Point & point, int rotation);
**********************************************/

void SmallRock :: draw()
{
    drawSmallAsteroid(point, spin);
}

/*********************************************
* Small Rock :: Advance
* Advance function of the small rock
* inhert from the flying object small rock
* Add the spin according to the size of the rock
**********************************************/

void SmallRock:: advance()
{
    spin += SMALL_ROCK_SPIN;
    FlyingObject::advance();

    
}

/*********************************************
* Small Rock :: hit
* Hit function for the small rock
* When it is hit by the bullet it lost 1 health
* and return the score we set for rock
**********************************************/
int  SmallRock::hit()
{
    lives = lives - 1;
    if (lives <= 0)
    {
        kill();
    }
    return getScore();;

}