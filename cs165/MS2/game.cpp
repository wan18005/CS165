/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"

// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;


/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
    ship->advance();
    
    for (int i = 0; i < bigRocks.size(); i++)
    {
        bigRocks.at(i)->advance();
    }

    
    for (int i = 0; i < bullets.size(); i++)
    {
        bullets.at(i)->advance();
    }
    
   
}




   
            
/**********************************************************
* Function: draw
* Description: Actually draws on screen all of the objects
**********************************************************/
        
void Game :: draw(const Interface& ui)
{
    for (int i = 0; i < bigRocks.size(); i++)
    {
        bigRocks.at(i)->draw();
    }
    ship->draw();


    for (int i = 0; i < bullets.size(); i++)
    {
        bullets.at(i)->draw();
    }

    
    
}



/**********************************************************
 * Function: handleInput
 * Description: Handles user input to control the ship and
 * bullets.
 **********************************************************/

void Game :: handleInput(const Interface& ui)
{
    
        if (ui.isUp())
        {
           
        }
        if (ui.isLeft())
        {
            ship->rotateLeft();
        }
        
        if (ui.isRight())
        {
            ship->rotateRight();
        }

    // Check for "Spacebar
    if (ui.isSpace())
    {
        Bullet* newBullet = new Bullet(ship->getPoint(), ship->getDirection(), ship->getVelocity());
        bullets.push_back(newBullet);
    }
}


// You may find this function helpful...

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/

float Game::getClosestDistance(const FlyingObject& obj1, const FlyingObject& obj2) const
{
    // find the maximum distance traveled
    float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
    dMax = max(dMax, abs(obj2.getVelocity().getDx()));
    dMax = max(dMax, abs(obj2.getVelocity().getDy()));
    dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.

    float distMin = std::numeric_limits<float>::max();
    for (float i = 0.0; i <= dMax; i++)
    {
        Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
            obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
        Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
            obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));

        float xDiff = point1.getX() - point2.getX();
        float yDiff = point1.getY() - point2.getY();

        float distSquared = (xDiff * xDiff) + (yDiff * yDiff);

        distMin = min(distMin, distSquared);
    }


    return sqrt(distMin);
}
