/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/

#ifndef GAME_H
#define GAME_H

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "FlyingObject.h"
#include "velocity.h"
#include "bullet.h"
#include <vector>
#include <limits>
#include <algorithm>
#include "game.h"
#include "ship.h"
#include "rocks.h"

#define CLOSE_ENOUGH 15

class Game
{
private:

    // TODO: declare your bird here (e.g., "Bird * bird;")
       Ship *ship;
       std::vector<Bullet*> bullets;
       int score;


   public:
       std::vector<BigRock*> bigRocks;
      float getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const;
      void advance();
      void handleInput(const Interface& ui);
      void draw(const Interface& ui);

      Game(Point topLeft, Point topRight)
      {
         for (int i = 0; i < 5; i++)
         {
             BigRock *bigRock = new BigRock();
             bigRock->setPoint(Point(random(-200,200), random(-200, 200)));
             bigRock->setVelocity(Velocity(1, 1));
             bigRocks.push_back(bigRock);
         }
          ship = new Ship();
     }
    
};

#endif /* GAME_H */
