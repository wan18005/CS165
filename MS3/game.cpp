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
#include "ship.h"
#include "point.h"
#include "flyingObject.h"
#include "velocity.h"
#include "rocks.h"
#include "bullet.h"


using namespace std;
Game:: Game(Point t1, Point br)
    :topLeft(t1), bottomRight(br)
{
    for (int i = 0; i < 5; i++)
    {
        BigRock* bigRock = new BigRock();
        bigRocks.push_back(bigRock);
    }
    ship = new Ship();
    ship->setPoint(Point(0, 0));
    ship->setVelocity(Velocity(-cos(M_PI / 180.0), (sin(M_PI / 180.0))));
}


void Game::advanceBigRock()
{   
    for (int i = 0; i < bigRocks.size(); i++)
    {
        bigRocks[i]->advance();
    }

}

void Game::advanceMediumRock()
{
    for (int i = 0; i <mediumRocks.size(); i++)
    {
       mediumRocks[i]->advance();
    }

}

void Game::advanceSmallRock()
{
    for (int i = 0; i < smallRocks.size(); i++)
    {
        smallRocks[i]->advance();
    }

}

void Game::advanceBullet()
{
    for (int i = 0; i < bullets.size(); i++)
    {
        bullets[i]->advance();
    }

}

void Game::advance()
{
    advanceBigRock();
    advanceMediumRock();
    advanceSmallRock();
    advanceBullet();
    advanceShip();
    handleCollision1();
    handleCollision2();
    handleCollision3();
    cleanUp1();
    cleanUp2();
    cleanUp3();
    cleanUp4();

}

void Game::handleCollision1()
{// big Rock Collision with Rock
    for (int i = 0; i < bigRocks.size(); i++)
    {
        float dist = getClosestDistance(*bigRocks[i], *ship);
        if (dist < bigRocks[i]->getSize())
        {
            ship->kill();
        }
        for (int b = 0; b < bullets.size(); b++)
        {
            float dist = getClosestDistance(*bigRocks[i], *bullets[b]);
            if (dist < bigRocks[i]->getSize())
            {
               
                bigRocks[i]->kill();
                bullets[b]->kill();
               
                MediumRock* medRock = new MediumRock();
                mediumRocks.push_back(medRock);
                
                medRock->setPoint(bigRocks[i]->getPoint());
                medRock->setVelocity(bigRocks[i]->getVelocity());

                Velocity* myVelocity = new Velocity();
                myVelocity->setDy(medRock->getVelocity().getDy() + 1);
                myVelocity->setDx(medRock->getVelocity().getDx());
                medRock->setVelocity(*myVelocity);

                medRock = new MediumRock();
                mediumRocks.push_back(medRock);
                medRock->setPoint(bigRocks[i]->getPoint());
                medRock->setVelocity(bigRocks[i]->getVelocity());

                
                myVelocity = new Velocity();
                myVelocity->setDy(medRock->getVelocity().getDy() - 1);
                myVelocity->setDx(medRock->getVelocity().getDx());
                medRock->setVelocity(*myVelocity);
            }
        }

    }
}
// med rock with ship
void Game::handleCollision2()
{
    
    for (int i = 0; i < mediumRocks.size(); i++)
    {
        float dist = getClosestDistance(*mediumRocks[i], *ship);
        if (dist < mediumRocks[i]->getSize())
        {
            ship->kill();
        }
        
        for (int j = 0; j < bullets.size(); j++)
        {
            float dist = getClosestDistance(*mediumRocks[i], *bullets[j]);
            if (dist < mediumRocks[i]->getSize())
            {
                
                mediumRocks.at(i)->kill();
                bullets[j]->kill();

                SmallRock* smallRockObject = new SmallRock();
                smallRocks.push_back(smallRockObject);
                
                smallRockObject->setPoint(mediumRocks[i]->getPoint());
                smallRockObject->setVelocity(mediumRocks[i]->getVelocity());

                Velocity* myVelocity = new Velocity();
                myVelocity->setDy(smallRockObject->getVelocity().getDy());
                myVelocity->setDx(smallRockObject->getVelocity().getDx() + 3);
                smallRockObject->setVelocity(*myVelocity);

                smallRockObject = new SmallRock();
                smallRocks.push_back(smallRockObject);

                smallRockObject->setPoint(mediumRocks[i]->getPoint());
                smallRockObject->setVelocity(mediumRocks[i]->getVelocity());

                myVelocity = new Velocity();
                myVelocity->setDy(smallRockObject->getVelocity().getDy());
                myVelocity->setDx(smallRockObject->getVelocity().getDx() - 3);
                smallRockObject->setVelocity(*myVelocity);
                
            }
        }
    }

}

void Game::handleCollision3()
{
            // small 
            for (int i = 0; i < smallRocks.size(); i++)
            {
                float dist = getClosestDistance(*smallRocks[i], *ship);
                if (dist < smallRocks[i]->getSize())
                {
                    ship->kill();
                }

                // this handles collisions between bullets and asteroids and creates the new
                // asteroids after killing the medium asteroids
                for (int j = 0; j < bullets.size(); j++)
                {
                    float dist = getClosestDistance(*smallRocks[i], *bullets[j]);
                    if (dist < smallRocks[i]->getSize())
                    {
                        // kills the rocks and the bullets
                        smallRocks[i]->kill();
                        bullets[j]->kill();

                    }
                }
            }     
}

//Clean up for big rock
void Game::cleanUp1()
{
    vector<BigRock*>::iterator bigIt = bigRocks.begin();

    while (bigIt != bigRocks.end())
    {
        if (!(*bigIt)->isAlive())
        {
            delete* bigIt;
            bigIt = bigRocks.erase(bigIt);

        }
        else
        {
            bigIt++;
        }
    }
}
//Clean up mid rock
void Game::cleanUp2()
{

    vector<MediumRock*>::iterator medIt = mediumRocks.begin();

    while (medIt != mediumRocks.end())
    {
        if (!(*medIt)->isAlive())
        {
            delete* medIt;
            medIt = mediumRocks.erase(medIt);

        }
        else
        {
            medIt++;
        }
    }

}
//Clean up small rock
    void Game::cleanUp3()
    {
        vector<SmallRock*>::iterator smallIt = smallRocks.begin();

        while (smallIt != smallRocks.end())
        {
            if (!(*smallIt)->isAlive())
            {
                delete* smallIt;
                smallIt = smallRocks.erase(smallIt);
            }
            else
            {
                smallIt++;
            }
        }
    }

    //Clean up bullet
    void Game::cleanUp4()
    {
      vector<Bullet*>::iterator bulletIt = bullets.begin();

      while (bulletIt != bullets.end())
      {
        if ((*bulletIt)->getHP() < 0 || !(*bulletIt)->isAlive())
        {
            delete* bulletIt;
            bulletIt = bullets.erase(bulletIt);
        }
        else
        {
            bulletIt++;
        }
      }
    }



void Game::advanceShip()
{
    ship->advance();
}
        
/**********************************************************
* Function: draw
* Description: Actually draws on screen all of the objects
**********************************************************/
        
void Game :: draw(const Interface& ui)
{
    ship->draw();

    for (int i = 0; i < bigRocks.size(); i++)
    {
        bigRocks[i]->draw();
    }
    for (int i = 0; i < bullets.size(); i++)
    {
        bullets[i]->draw();
    }
    for (int i = 0; i <mediumRocks.size(); i++)
    {
       mediumRocks[i]->draw();
    }
    for (int i = 0; i < smallRocks.size(); i++)
    {
        smallRocks[i]->draw();
    }

    Point scoreLocation;
    scoreLocation.setX(topLeft.getX() + 5);
    scoreLocation.setY(topLeft.getY() - 5);
    drawNumber(scoreLocation, score);
    
    
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
            ship->applyThrust();
        }
        
        if (ui.isLeft())
        {
            ship->rotateLeft();
        }
        
        if (ui.isRight())
        {
            ship->rotateRight();
        }
        if (ui.isDown())
        {
            ship->stopThrust();
        }

    if (ui.isSpace())
    {   
         //MediumRock* medRock = new MediumRock();
        Bullet* newBullet = new Bullet(ship->getPoint(), ship->getRotatation(), ship->getVelocity());
        bullets.push_back(newBullet);
    }
}

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
