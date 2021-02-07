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
#include "velocity.h"
#include "rocks.h"
#include "ship.h"
#include "bullet.h"
#include <vector>

#define CLOSE_ENOUGH 15

class Game
{
private:
    Ship *ship;
    std::vector<Bullet*> bullets;
   public:
      float getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const;
      void advance();
      void handleInput( const Interface pUI);
      void draw( const Interface pUI);
      std::vector<BigRock*> bigRocks;
      std::vector<MediumRock*> mediumRocksVector;
      std::vector<SmallRock*> smallRocksVector;
    
    
      Game(Point topLeft, Point topRight)
      {
         for (int i = 0; i < 5; i++)
         {
             BigRock *bigRock = new BigRock();
             bigRocks.push_back(bigRock);
         }
          ship = new Ship();
     }
    
};

#endif /* GAME_H */
