/*************************************************************
 * File: game.h
 * Author: 
 *
 * Description: The game of Skeet. This class holds each piece
 *  of the game (birds, bullets, rifle, score). It also has
 *  methods that make the game happen (advance, interact, etc.)
 *
 * Got ideas from 
 *************************************************************/

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

#define OFF_SCREEN_BORDER_AMOUNT 5
#define initalSpeed 0

Game:: Game(Point t1, Point br)
    :topLeft(t1), bottomRight(br)
{   // The game begins with 5 large asteroids.
    for (int i = 0; i < 5; i++)
    {
        BigRock* bigRock = new BigRock();
        bigRocks.push_back(bigRock);
    }
    // create new ship it's location and speed
    ship = new Ship();
    ship->setPoint(Point(0, 0));
    ship->setVelocity(Velocity(initalSpeed * cos(M_PI / 180.0), (initalSpeed *sin(M_PI / 180.0))));
    score = 0;
    ship->getHP();
}



/*********************************************
* Game :: advanceBigRock
* Advance for BigRock
* for as how many big rocks they are they all will advance feature in them
**********************************************/
void Game::advanceBigRock()
{   
    for (int i = 0; i < bigRocks.size(); i++)
    {
        bigRocks[i]->advance();
    }

}

/*********************************************
* Game :: advanceMediumRock
* Advance for medium rock
* the same with big rock 
* for as how many medium rocks they are they all will advance feature in them
**********************************************/
void Game::advanceMediumRock()
{
    for (int i = 0; i <mediumRocks.size(); i++)
    {
       mediumRocks[i]->advance();
    }

}

/*********************************************
* Game :: advanceSmallRock
* Advance for small rock
* the same with the other two rocks
* for as how many small rocks they are they all will advance feature in them
**********************************************/
void Game::advanceSmallRock()
{
    for (int i = 0; i < smallRocks.size(); i++)
    {
        smallRocks[i]->advance();
    }

}

/*********************************************
* Game :: advanceBullet
* Advance for Bullet
* for as how many bullets they all will advance feature in them
**********************************************/
void Game::advanceBullet()
{
    for (int i = 0; i < bullets.size(); i++)
    {
        bullets[i]->advance();
    }

}

/*********************************************
* Game :: advanceShip
* Advance for ship
* Ship will have the advance feature.
**********************************************/
void Game::advanceShip()
{
    ship->advance();
}

/*********************************************
* Game :: handleCollision1
* This handle collision for the big rock ans ship
* two medium rock and a small rock created when hitted
**********************************************/
void Game::handleCollision1()
{// big Rock Collision with Ship
    // get this idea from the pervious project 
    for (int i = 0; i < bigRocks.size(); i++)
    {   
        // get impact between big rock and ship
        float impact = getClosestDistance(*bigRocks[i], *ship);

        if (impact < bigRocks[i]->getSize())
        {
            ship->hit();
        }
        // big Rock Collision with Bullet
        for (int b = 0; b < bullets.size(); b++)
        {
            float impact = getClosestDistance(*bigRocks[i], *bullets[b]);
            if (impact < bigRocks[i]->getSize())
            {   
                // the same with above
                // kill bullet
                bullets[b]->kill();
                // big rock got hit and return score
                int points = bigRocks[i]->hit();
                //return the score 
                //got this from skeet projects
                score += points;
                /*********************************************
                * If a large asteroid gets hit,
                * it breaks apartand becomes two medium asteroidsand one small one.
                **********************************************/
                // Medium Rock 1
                MediumRock* medRock = new MediumRock();
                mediumRocks.push_back(medRock);
                /*********************************************
                * The first medium asteroid has the same velocity as the original large one 
                *plus 1 pixel/frame in the up direction.
                **********************************************/
                medRock->setPoint(bigRocks[i]->getPoint());
                medRock->setVelocity(bigRocks[i]->getVelocity());
                Velocity* newVelocity = new Velocity();
                newVelocity->setDy(medRock->getVelocity().getDy() + 1);
                newVelocity->setDx(medRock->getVelocity().getDx());
                medRock->setVelocity(*newVelocity);
                // Medium Rock 2
                medRock = new MediumRock();
                mediumRocks.push_back(medRock);
                /*********************************************
                * The second medium asteroid has the same velocity as the original large one
                *plus 1 pixel/frame in the down direction.
                **********************************************/
                medRock->setPoint(bigRocks[i]->getPoint());
                medRock->setVelocity(bigRocks[i]->getVelocity());
                newVelocity = new Velocity();
                newVelocity->setDy(medRock->getVelocity().getDy() - 1);
                newVelocity->setDx(medRock->getVelocity().getDx());
                medRock->setVelocity(*newVelocity);
                // Small Rock from big Rock
                SmallRock* smallRockObject = new SmallRock();
                smallRocks.push_back(smallRockObject);
                /*********************************************
               * The small asteroid has the original velocity 
               * plus 2 pixels/frame to the right.
               **********************************************/
                smallRockObject->setPoint(bigRocks[i]->getPoint());
                smallRockObject->setVelocity(bigRocks[i]->getVelocity());
                newVelocity = new Velocity();
                newVelocity->setDy(smallRockObject->getVelocity().getDy());
                newVelocity->setDx(smallRockObject->getVelocity().getDx() + 2);
                smallRockObject->setVelocity(*newVelocity);
            }
        }
    }
}
/*********************************************
* Game :: handleCollision2
* This handle collision for the medium rock and ship
* 2 small rock created 
**********************************************/
void Game::handleCollision2()
{
    for (int i = 0; i < mediumRocks.size(); i++)
    {   
        // check distance of impact
        float impact = getClosestDistance(*mediumRocks[i], *ship);
        if (impact < mediumRocks[i]->getSize())
        {
            ship->hit();
        }
        // for bullet
        for (int b = 0; b < bullets.size(); b++)
        {   
            // impact between medium rock and bullet
            float impact = getClosestDistance(*mediumRocks[i], *bullets[b]);
            if (impact < mediumRocks[i]->getSize())
            {
                // medium rock got hit and return score
                int points = mediumRocks[i]->hit();
                score += points;
                // kill bullet
                bullets[b]->kill();
              /*********************************************
              * If hit, it breaks apart and becomes two small asteroids
              * small rock 1
              **********************************************/
                SmallRock* smallRockObject = new SmallRock();
                smallRocks.push_back(smallRockObject);
             /*********************************************
             * The small asteroid has the same velocity as the original medium one 
             * plus 3 pixel/frame to the right.
             **********************************************/
                smallRockObject->setPoint(mediumRocks[i]->getPoint());
                smallRockObject->setVelocity(mediumRocks[i]->getVelocity());
                Velocity* newVelocity = new Velocity();
                newVelocity->setDy(smallRockObject->getVelocity().getDy());
                newVelocity->setDx(smallRockObject->getVelocity().getDx() + 3);
                smallRockObject->setVelocity(*newVelocity);
                /*********************************************
                * If hit, it breaks apart and becomes two small asteroids
                * small rock 2
                **********************************************/
                smallRockObject = new SmallRock();
                smallRocks.push_back(smallRockObject);
                /*********************************************
                * The small asteroid has the same velocity as the original medium one
                * plus 3 pixel/frame to the left
                **********************************************/
                smallRockObject->setPoint(mediumRocks[i]->getPoint());
                smallRockObject->setVelocity(mediumRocks[i]->getVelocity());
                newVelocity = new Velocity();
                newVelocity->setDy(smallRockObject->getVelocity().getDy());
                newVelocity->setDx(smallRockObject->getVelocity().getDx() - 3);
                smallRockObject->setVelocity(*newVelocity);
            }
        }
    }
}
/*********************************************
* Game :: handleCollision3 
* This handle collision for the small rock and ship
* that is yet nice and easy
**********************************************/
void Game::handleCollision3()
{
            // small rock
            for (int i = 0; i < smallRocks.size(); i++)
            {   // impact distance for small rock and ship
                float impact = getClosestDistance(*smallRocks[i], *ship);
                
                if (impact < smallRocks[i]->getSize())
                {
                    ship->hit();
                }
                // impact distance for bullet and small rock
                for (int b = 0; b < bullets.size(); b++)
                {
                    float impact = getClosestDistance(*smallRocks[i], *bullets[b]);
                    if (impact < smallRocks[i]->getSize())
                    {   
                        // return points for killing the small rocks
                        int points = smallRocks[i]->hit();
                        score += points;
                        //kill the bullet
                        bullets[b]->kill();
                    }
                }
            }     
}

/*********************************************
* Game :: cleanUP1
* Just like a clean up zombie function
* It clean up the Big Rock
**********************************************/
void Game::cleanUp1()
{   
    // get this from skeet project
    // look for dead bigRock
    vector<BigRock*>::iterator bigIt = bigRocks.begin();
    while (bigIt != bigRocks.end())
    {
        if (!(*bigIt)->isAlive())
        {
            delete* bigIt; //delete
            bigIt = bigRocks.erase(bigIt);// remove from list and advance

        }
        else
        {
            bigIt++; // adcance
        }
    }
}

/*********************************************
* Game :: cleanUP2
* Just like a clean up zombie function
* It clean up the medium Rock
**********************************************/
void Game::cleanUp2()
{
    // look for dead bigRock
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
/*********************************************
* Game :: cleanUP3
* Just like a clean up zombie function
* It clean up the small Rock
**********************************************/
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

    /*********************************************
    * Game :: cleanUP4
    * Just like a clean up zombie function
    * It clean up the bullet
    **********************************************/
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

/*********************************************
* Game :: advance
* Advance for the whole game
* call all function below
**********************************************/
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

  
        
/*********************************************
* Game :: draw
* It draw everything for the game
**********************************************/
void Game :: draw(const Interface& ui)
{   
    // HP update from getHP
    HP = ship->getHP();
    if (HP > 0 )
    { 
    for (int i = 0; i < bigRocks.size(); i++)
    {
        bigRocks[i]->draw();
    }
    ship->draw();
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

    // added new text
    Point scoreText;
    scoreText.setX(topLeft.getX() + 30);
    scoreText.setY(topLeft.getY() - 15);
    drawText(scoreText, "Points");

    // added HP point
    Point HPLocation;
    scoreLocation.setX(topLeft.getX() + 5);
    scoreLocation.setY(topLeft.getY() - 20);
    drawNumber(scoreLocation, HP);

    // added HP text
    Point HPText;
    HPText.setX(topLeft.getX() + 30);
    HPText.setY(topLeft.getY() - 30);
    drawText(HPText, "Health Point");
    }
    // when HP low finish the game 
    else if (HP <= 0)
    {
        Point goodGameTextLocation;
        goodGameTextLocation.setX(topLeft.getX() + 150);
        goodGameTextLocation.setY(topLeft.getY() - 200);
        drawText(goodGameTextLocation, "Game Over ! Press <F1> to try again");
    }
    
}

/*********************************************
* Game :: handleInput
* It handle all the key press in the game
**********************************************/
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

        // add new key f1
        if (ui.isF1())
        {
            ship->reset();
        }
        // add new key f2
        if (ui.isF2())
        {
            ship->setHP(999);
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

/**************************************************************************
 * GAME :: IS ON SCREEN
 * Determines if a given point is on the screen.
 **************************************************************************/
bool Game::isOnScreen(const Point& point)
{
    return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT
        && point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT
        && point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT
        && point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
}
