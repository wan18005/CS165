/*************************************************************
 * File: game.cpp
 * Author: Br. Burton
 *
 * Description: Contains the implementations of the
 *  method bodies for the game class.
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/

#include "game.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "flyingObjects.h"
#include "velocity.h"
#include "bullet.h"
#include <vector>
#include <limits>
#include <algorithm>
#include "game.h"
#include "ship.h"
using namespace std;

#define OFF_SCREEN_BORDER_AMOUNT 5

/***************************************
 * GAME CONSTRUCTOR
 ***************************************/
Game:: Game(Point tl, Point br)
	: topLeft(tl), bottomRight(br) //rifle(br)
{
	// Set up the initial conditions of the game
	score = 0;
	rock = NULL;
	// show 5 at a time
		for (int i = 0; i < 5; i++)
		{
			rocks.push_back(createRock());
		}
}

/****************************************
 * GAME DESTRUCTOR
 ****************************************/
Game :: ~Game()
{   
	// TODO: Check to see if there is currently a bird allocated
	//       and if so, delete it.
	if (rock != NULL)
	{
		delete rock;
		rock = NULL;
	}
}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game::advance()
{
	advanceBullets();
	advanceRock();

	handleCollisions();
	cleanUpZombies();
}

/***************************************
 * GAME :: ADVANCE BULLETS
 * Go through each bullet and advance it.
 ***************************************/
void Game::advanceBullets()
{
	// Move each of the bullets forward if it is alive
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			// this bullet is alive, so tell it to move forward
			bullets[i].advance();

			if (!isOnScreen(bullets[i].getPoint()))
			{
				// the bullet has left the screen
				bullets[i].kill();
			}

		}
	}
}

/**************************************************************************
 * GAME :: ADVANCE Rock
 *
 * 1. If there is no Rock, create one with some probability
 * 2. If there is a Rock, and it's alive, advance it
 * 3. Check if the Rock has gone of the screen, and if so, "kill" it
 **************************************************************************/
void Game::advanceRock()
{
	//how to use a vector from homework
	// for (vector <Food*>::iterator it = items.begin();
	// it != items.end(); ++ it)
	vector<Rock*>::iterator rockB = rocks.begin();

	while (rockB != rocks.end())
	{
		Rock* pRock = *rockB;
		//Bullet* pBullet = *bulletIt;
		//copy this from the last game.cpp
		// we have a Rock, make sure it's alive
		if (pRock->isAlive())
		{
			// move it forward
			pRock->advance();

			// check if the Rock has gone off the screen
			if (!isOnScreen(pRock->getPoint()))
			{
				// We have missed the Rock
				pRock->kill();
			}

		}

		rockB++; // vector

	}


	/* if (bird == NULL)
   {
      // there is no bird right now, possibly create one
      
      // "resurrect" it will some random chance
      if (random(0, 30) == 0)
      {
         // create a new bird
         bird = createBird();
      }
   }
   else
   {
      // we have a bird, make sure it's alive
      if (bird->isAlive())
      {
         // move it forward
         bird->advance();
         
         // check if the bird has gone off the screen
         if (!isOnScreen(bird->getPoint()))
         {
            // We have missed the bird
            bird->kill();
         }
      }
   }
   */
   

   }

/**************************************************************************
* GAME :: CREATE Rock
* Create a Rock of a random type according to the rules of the game.
**************************************************************************/
Rock* Game::createRock()
{
	Rock* newRock = NULL;
	newRock = new BigRock();
	newRock->setPoint(Point(-200, random(-200, 200)));
	newRock->setVelocity(Velocity(1, 1));
	return newRock;
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

/**************************************************************************
 * GAME :: HANDLE COLLISIONS
 * Check for a collision between a Rock and a bullet.
 **************************************************************************/
void Game::handleCollisions()
{
	// now check for a hit (if it is close enough to any live bullets)
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			// this bullet is alive, see if its too close

			// check if the Rock is at this point (in case it was hit)
			if (rock != NULL && rock->isAlive())
			{
				// BTW, this logic could be more sophisiticated, but this will
				// get the job done for now...
				if (fabs(bullets[i].getPoint().getX() - rock->getPoint().getX()) < CLOSE_ENOUGH
					&& fabs(bullets[i].getPoint().getY() - rock->getPoint().getY()) < CLOSE_ENOUGH)
				{
					//we have a hit!

					// hit the Rock
					int points = rock->hit();
					score += points;

					// the bullet is dead as well
					bullets[i].kill();
				}
			}
		} // if bullet is alive

	} // for bullets
}

/**************************************************************************
 * GAME :: CLEAN UP ZOMBIES
 * Remove any dead objects (take bullets out of the list, deallocate Rock)
 **************************************************************************/
void Game::cleanUpZombies()
{
	// check for dead bird
	if (rock != NULL && !rock->isAlive())
	{
		// the bird is dead, but the memory is not freed up yet

	  // TODO: Clean up the memory used by the bird
		delete rock;
		rock = NULL;
	}

	// Look for dead bullets
	vector<Bullet>::iterator bulletIt = bullets.begin();
	while (bulletIt != bullets.end())
	{
		Bullet bullet = *bulletIt;
		// Asteroids Hint:
		// If we had a list of pointers, we would need this line instead:
		//Bullet* pBullet = *bulletIt;

		if (!bullet.isAlive())
		{
			// If we had a list of pointers, we would need to delete the memory here...


			// remove from list and advance
			bulletIt = bullets.erase(bulletIt);
		}
		else
		{
			bulletIt++; // advance
		}
	}

}

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game::handleInput(const Interface& ui)
{
	//MoveUp or Movedown should be included too.
	// Change the direction of the rifle
	if (ui.isLeft())
	{
		// rifle.moveLeft();
	}

	if (ui.isRight())
	{
		//rifle.moveRight();
	}

	// Check for "Spacebar
	if (ui.isSpace())
	{
		
	}
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game::draw(const Interface& ui)
{
	// ship.draw();
	//vector 
	vector<Rock*>::iterator rockB = rocks.begin();

	//how to use a vector from homework
	// for (vector <Food*>::iterator it = items.begin();
	// it != items.end(); ++ it)
	while (rockB != rocks.end())
	{
		Rock* pRock = *rockB;

		if (pRock->isAlive())
		{
			pRock->draw();
		}

		rockB++;

	}
	

	
   /* // draw the bird
        if (bird != NULL)
        {
            if (bird->isAlive())
            {
                bird->draw();
            }
        }
        


        // draw the rifle
        rifle.draw();
	}*/



	// draw the bullets, if they are alive
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			bullets[i].draw();
		}
	}

	// Put the score on the screen
	Point scoreLocation;
	scoreLocation.setX(topLeft.getX() + 5);
	scoreLocation.setY(topLeft.getY() - 5);

	drawNumber(scoreLocation, score);

}

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/
/*
float Game::getClosestDistance(const flyingObjects& obj1, const flyingObjects& obj2) const
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
*/