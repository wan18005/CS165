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
    for (int i = 0; i < mediumRocksVector.size(); i++)
    {
        mediumRocksVector.at(i)->advance();
    }
    for (int i = 0; i < smallRocksVector.size(); i++)
    {
        smallRocksVector.at(i)->advance();
    }
    
    for (int i = 0; i < bullets.size(); i++)
    {
        bullets.at(i)->advance();
    }
    std::cout << smallRocksVector.size() << " ";
    
///////////////////////////////////////////////////////////////////////
    // this handles what to do if there is a collision between the ship
    // and the big asteroids
    // ship->getSize()
    
    for (int i = 0; i < bigRocks.size(); i++)
    {
        float dist  = getClosestDistance(*bigRocks.at(i), *ship);
        if (dist < bigRocks.at(i)->getSize())
        {
            ship->kill();
        }

        // this handles collisions between bullets and big asteroids and creates the new
        // asteroids after killing the big asteroids
        for (int j = 0; j < bullets.size(); j++)
        {
            float dist  = getClosestDistance(*bigRocks.at(i), *bullets.at(j));
            if (dist < bigRocks.at(i)->getSize())
            {
                // kills the rocks and the bullets
                bigRocks.at(i)->kill();
                bullets.at(j)->kill();
                
                
                
                // First medium rock made from the big rcok
                ///////////////////////////////////////////////////////////
                // here we are creating a new medium rock object
                MediumRock *medRock = new MediumRock();
                mediumRocksVector.push_back(medRock);
                
                // here we are giving the new objects we created and
                // giving it the same velocity as the big rock
                medRock->setPoint(bigRocks.at(i)->getPoint());
                medRock->setVelocity(bigRocks.at(i)->getVelocity());
                
                // here we create a velocity object
                Velocity*  myVelocity = new Velocity();
                myVelocity->setDy(medRock->getVelocity().getDy() + 1);
                myVelocity->setDx(medRock->getVelocity().getDx());
                medRock->setVelocity(*myVelocity);
                /////////////////////////////////////////////////////////////
                
                
                // Second medium rock made from the big rcok
                ///////////////////////////////////////////////////////////
                // here we are creating a new medium rock object
                medRock = new MediumRock();
                mediumRocksVector.push_back(medRock);
                
                // here we are giving the new objects we created and
                // giving it the same velocity as the big rock
                medRock->setPoint(bigRocks.at(i)->getPoint());
                medRock->setVelocity(bigRocks.at(i)->getVelocity());
                
                // here we create a velocity object
                myVelocity = new Velocity();
                myVelocity->setDy(medRock->getVelocity().getDy() - 1);
                myVelocity->setDx(medRock->getVelocity().getDx());
                medRock->setVelocity(*myVelocity);
                /////////////////////////////////////////////////////////////
                
                
                // Small rock made from the big rcok
                ///////////////////////////////////////////////////////////
                // here we are creating a new small rock object
                SmallRock *smallRockObject = new SmallRock();
                smallRocksVector.push_back(smallRockObject);
                
                // here we are giving the new objects we created and
                // giving it the same velocity as the big rock
                smallRockObject->setPoint(bigRocks.at(i)->getPoint());
                smallRockObject->setVelocity(bigRocks.at(i)->getVelocity());
                
                // here we create a velocity object
                myVelocity = new Velocity();
                myVelocity->setDy(smallRockObject->getVelocity().getDy());
                myVelocity->setDx(smallRockObject->getVelocity().getDx() + 1);
                smallRockObject->setVelocity(*myVelocity);
                /////////////////////////////////////////////////////////////
            }
        }
    }
///////////////////////////////////////////////////////////////////////////
    
    // this is the code to determine the collision between the medium rocks and the ship
    for (int i = 0; i < mediumRocksVector.size(); i++)
    {
        float dist  = getClosestDistance(*mediumRocksVector.at(i), *ship);
        if (dist < mediumRocksVector.at(i)->getSize())
        {
            ship->kill();
        }
        
        // this handles collisions between bullets and medium asteroids
        for (int j = 0; j < bullets.size(); j++)
        {
            float dist  = getClosestDistance(*mediumRocksVector.at(i), *bullets.at(j));
            if (dist < mediumRocksVector.at(i)->getSize())
            {
                // kills the rocks and the bullets
                mediumRocksVector.at(i)->kill();
                bullets.at(j)->kill();
                
                // First rock made from the medium rock
                ///////////////////////////////////////////////////////////
                // here we are creating a new object
                SmallRock *smallRockObject = new SmallRock();
                smallRocksVector.push_back(smallRockObject);
                std::cout << "Push basck";

                
                // here we are giving the new objects we created and
                // giving it the same velocity as the big rock
                smallRockObject->setPoint(mediumRocksVector.at(i)->getPoint());
                smallRockObject->setVelocity(mediumRocksVector.at(i)->getVelocity());
                
                // here we create a velocity object
                Velocity* myVelocity = new Velocity();
                myVelocity->setDy(smallRockObject->getVelocity().getDy());
                myVelocity->setDx(smallRockObject->getVelocity().getDx() + 3);
                smallRockObject->setVelocity(*myVelocity);
                /////////////////////////////////////////////////////////////
                
                
                
                
                // second small asteroid from the medium rock
                /////////////////////////////////////////////////////////////
                // here we are creating a new object
                smallRockObject = new SmallRock();
                smallRocksVector.push_back(smallRockObject);
                std::cout << "Push basck";
                
                // here we are giving the new objects we created and
                // giving it the same velocity as the medium rock
                smallRockObject->setPoint(mediumRocksVector.at(i)->getPoint());
                smallRockObject->setVelocity(mediumRocksVector.at(i)->getVelocity());
                
                // here we create a velocity object
                myVelocity = new Velocity();
                myVelocity->setDy(smallRockObject->getVelocity().getDy());
                myVelocity->setDx(smallRockObject->getVelocity().getDx() - 3);
                smallRockObject->setVelocity(*myVelocity);
                /////////////////////////////////////////////////////////////
            }
        }
    }
    // we are deleting the bullets that have been killed here
    //////////////////////////////////////////////////////////
    vector<Bullet*>::iterator myBulletIt = bullets.begin();
    while (myBulletIt != bullets.end())
    {
        if((*myBulletIt)->getLifePoints() < 0 || !(*myBulletIt)->isAlive())
        {
            delete *myBulletIt;
            myBulletIt = bullets.erase(myBulletIt);
        }
        else
        {
            myBulletIt++;
        }
    }
    /////////////////////////////////////////////////////////////
    
    for (int i = 0; i < smallRocksVector.size(); i++)
    {
        float dist  = getClosestDistance(*smallRocksVector.at(i), *ship);
        if (dist < smallRocksVector.at(i)->getSize())
        {
            ship->kill();
        }
        
        // this handles collisions between bullets and asteroids and creates the new
        // asteroids after killing the medium asteroids
        for (int j = 0; j < bullets.size(); j++)
        {
            float dist  = getClosestDistance(*smallRocksVector.at(i), *bullets.at(j));
            if (dist < smallRocksVector.at(i)->getSize())
            {
                // kills the rocks and the bullets
                smallRocksVector.at(i)->kill();
                bullets.at(j)->kill();

            }
        }
    }
    // if you die the program exits
    if (!ship->isAlive())
    {
        exit(0);
    }
    
    
    // the code below goes through all the rocks that have been killed and deletes them
    vector<BigRock*>::iterator myIter = bigRocks.begin();
    
    while (myIter != bigRocks.end())
    {
        if(!(*myIter)->isAlive())
        {
            delete *myIter;
            myIter = bigRocks.erase(myIter);
            
        }
        else
        {
            myIter++;
        }
    }
    
    
    // does same code as above but for the medium rocks
    vector<MediumRock*>::iterator medIter = mediumRocksVector.begin();
    
    while (medIter != mediumRocksVector.end())
    {
        if(!(*medIter)->isAlive())
        {
            delete *medIter;
             medIter = mediumRocksVector.erase(medIter);
            
        }
        else
        {
            medIter++;
        }
    }
    
    // the code below goes through all the rocks that have been killed and deletes them
    vector<SmallRock*>::iterator smallIter = smallRocksVector.begin();
    
    while (smallIter != smallRocksVector.end())
    {
        if(!(*smallIter)->isAlive())
        {
            delete *smallIter;
            smallIter = smallRocksVector.erase(smallIter);
        }
        else
        {
            smallIter++;
        }
    }
    
    // The code below go through every bullet created to see
    // if it has been alive for 40 frames and if it finds it
    // to be true it deletes it or if its dead.

    vector<Bullet*>::iterator myIt = bullets.begin();
    
    while (myIt != bullets.end())
    {
        if((*myIt)->getLifePoints() < 0 || !(*myIt)->isAlive())
        {
            delete *myIt;
            myIt = bullets.erase(myIt);
        }
        else
        {
            myIt++;
        }
    }
}
/**********************************************************
 * Function: draw
 * Description: Actually draws on screen all of the objects
 **********************************************************/

void Game :: draw(const Interface pUI)
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
    for (int i = 0; i < mediumRocksVector.size(); i++)
    {
        mediumRocksVector.at(i)->draw();
    }
    for (int i = 0; i < smallRocksVector.size(); i++)
    {
        smallRocksVector.at(i)->draw();
    }
    
}



/**********************************************************
 * Function: handleInput
 * Description: Handles user input to control the ship and
 * bullets.
 **********************************************************/

void Game :: handleInput(const Interface pUI)
{
    if (ship->isAlive())
    {
        if (pUI.isUp())
        {
            ship->applyThrust();
        }
        else
        {
            ship->setThrust(false);
        }
        if (pUI.isLeft())
        {
            ship->rotateLeft();
        }
        
        if (pUI.isRight())
        {
            ship->rotateRight();
        }
    }
    // Check for "Spacebar
    if (pUI.isSpace())
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

float Game :: getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
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

      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);

      distMin = min(distMin, distSquared);
   }
    

   return sqrt(distMin);
}
