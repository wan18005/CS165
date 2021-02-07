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
#include "rifle.h"
#include "bird.h"
#include "bullet.h"
#include <vector>

using namespace std;

#define OFF_SCREEN_BORDER_AMOUNT 5


/***************************************
 * GAME CONSTRUCTOR
 ***************************************/
Game :: Game(Point tl, Point br)
 : topLeft(tl), bottomRight(br), rifle(br)
{
   // Set up the initial conditions of the game
   score = 0;

   // TODO: Set your bird pointer to a good initial value (e.g., NULL)
   bird = NULL;
}

/****************************************
 * GAME DESTRUCTOR
 ****************************************/
Game :: ~Game()
{
   // TODO: Check to see if there is currently a bird allocated
   //       and if so, delete it.
    if (bird != NULL)
    {
        delete bird;
        bird = NULL;
    }
}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   advanceBullets();
   advanceBird();

   handleCollisions();
   cleanUpZombies();
}

/***************************************
 * GAME :: ADVANCE BULLETS
 * Go through each bullet and advance it.
 ***************************************/
void Game :: advanceBullets()
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
 * GAME :: ADVANCE BIRD
 *
 * 1. If there is no bird, create one with some probability
 * 2. If there is a bird, and it's alive, advance it
 * 3. Check if the bird has gone of the screen, and if so, "kill" it
 **************************************************************************/
void Game :: advanceBird()
{
   if (bird == NULL)
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
   
}

/**************************************************************************
 * GAME :: CREATE BIRD
 * Create a bird of a random type according to the rules of the game.
 **************************************************************************/
Bird* Game :: createBird()
{
   Bird* newBird = NULL;
   
   // TODO: Fill this in
   

   int bird = random(0,4);
   switch (bird)
   {
   
   case 0: // Standard Bird
       newBird = new StandardBird();
       newBird->setPoint(Point(-200, random(-200,200)));
       
       // Get Y Value : cout << newBird->getPoint().getY();
       // got helped from the TA so I don't have to hard code the velocity
       if ((newBird->getPoint().getY() >=0))
       {   
           newBird->setVelocity(Velocity(random(3, 6), random(-4, -1)));
       } 
       else 
       {
           newBird->setVelocity(Velocity(random(3, 6), random(1, 4)));
       }
       break;
   case 1:
       newBird = new ToughBird();
       newBird->setPoint(Point(-200, random(-200, 200)));
       if ((newBird->getPoint().getY() >= 0))
       {
           newBird->setVelocity(Velocity(random(2, 4), random(-3, -1)));
       }
       else
       {
           newBird->setVelocity(Velocity(random(2, 4), random(1, 3)));
       }
       break;
      
       
   case 2:
       newBird = new SacredBird();
       newBird->setPoint(Point(-200, random(-200, 200)));
       if ((newBird->getPoint().getY() >= 0))
       {
           newBird->setVelocity(Velocity(random(3, 6), random(-4, -1)));
       }
       else
       {
           newBird->setVelocity(Velocity(random(3, 6), random(1, 4)));
       }

       
       break;
   case 3:
       newBird = new Boss();
       newBird->setPoint(Point(-200, random(-200, 200)));
       if ((newBird->getPoint().getY() >= 0))
       {
           newBird->setVelocity(Velocity(random(2, 4), random(-3, -1)));
       }
       else
       {
           newBird->setVelocity(Velocity(random(2, 4), random(1, 3)));
       }
       break;

   }
   return newBird;
   
   
}

/**************************************************************************
 * GAME :: IS ON SCREEN
 * Determines if a given point is on the screen.
 **************************************************************************/
bool Game :: isOnScreen(const Point & point)
{
   return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT
      && point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT
      && point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT
      && point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
}

/**************************************************************************
 * GAME :: HANDLE COLLISIONS
 * Check for a collision between a bird and a bullet.
 **************************************************************************/
void Game :: handleCollisions()
{
   // now check for a hit (if it is close enough to any live bullets)
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         // this bullet is alive, see if its too close

         // check if the bird is at this point (in case it was hit)
         if (bird != NULL && bird->isAlive())
         {
            // BTW, this logic could be more sophisiticated, but this will
            // get the job done for now...
            if (fabs(bullets[i].getPoint().getX() - bird->getPoint().getX()) < CLOSE_ENOUGH
                && fabs(bullets[i].getPoint().getY() - bird->getPoint().getY()) < CLOSE_ENOUGH)
            {
               //we have a hit!
               
               // hit the bird
               int points = bird->hit();
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
 * Remove any dead objects (take bullets out of the list, deallocate bird)
 **************************************************************************/
void Game :: cleanUpZombies()
{
   // check for dead bird
   if (bird != NULL && !bird->isAlive())
   {
      // the bird is dead, but the memory is not freed up yet
      
      // TODO: Clean up the memory used by the bird
       delete bird;
       bird = NULL;
   
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
void Game :: handleInput(const Interface & ui)
{
   // Change the direction of the rifle
   if (ui.isLeft())
   {
      rifle.moveLeft();
   }
   
   if (ui.isRight())
   {
      rifle.moveRight();
   }
   
   // Check for "Spacebar
   if (ui.isSpace())
   {
      Bullet newBullet;
      newBullet.fire(rifle.getPoint(), rifle.getAngle());
      
      bullets.push_back(newBullet);
   }
   if (ui.isF1())
   {   
       

   }
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game::draw(const Interface& ui)
{  
    if (score >= 0)
    {
        // draw the bird
        if (bird != NULL)
        {
            if (bird->isAlive())
            {
                bird->draw();
            }
        }
        


        // draw the rifle
        rifle.draw();

        // draw the bullets, if they are alive
        for (int i = 0; i < bullets.size(); i++)
        {
            if (bullets[i].isAlive())
            {
                bullets[i].draw();
            }
        }

        /*********************************************
        * GAME :: DRAW
        * Put the score on the screen
        *********************************************/
        Point scoreLocation;
        scoreLocation.setX(topLeft.getX() + 5);
        scoreLocation.setY(topLeft.getY() - 5);
        drawNumber(scoreLocation, score);

        /*********************************************
        * GAME :: DRAW
        * point on screen
        *********************************************/
        // point on screen
        Point scoreText;
        scoreText.setX(topLeft.getX() + 30);
        scoreText.setY(topLeft.getY() - 15);
        drawText(scoreText, "Points");
        /*********************************************
        * GAME :: DRAW
        * GameTime
        *********************************************/
        Point gameTimeLocation;
        gameTimeLocation.setX(topLeft.getX() + 5);
        gameTimeLocation.setY(topLeft.getY() - 20);
        drawNumber(gameTimeLocation, gameTime);
        /*********************************************
         * GAME :: DRAW
         * GameTime Text
        *********************************************/
        Point gameTimeText;
        gameTimeText.setX(topLeft.getX() + 30);
        gameTimeText.setY(topLeft.getY() - 30);
        drawText(gameTimeText, "Player");
    }


   
else if (score < -10)
    { 
        Point goodGameTextLocation;
        goodGameTextLocation.setX(topLeft.getX() + 150);
        goodGameTextLocation.setY(topLeft.getY() - 200);
        drawText(goodGameTextLocation, "GG! WELL PLAYED!");
    }
   

   
}



