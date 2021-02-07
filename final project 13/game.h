/*************************************************************
 * File: game.h
 * Author: Br. Burton
 *
 * Description: The game of Skeet. This class holds each piece
 *  of the game (birds, bullets, rifle, score). It also has
 *  methods that make the game happen (advance, interact, etc.)
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/

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
        Ship* ship;
        std::vector<Bullet*> bullets;
        std::vector<BigRock*> bigRocks;
        std::vector<MediumRock*> mediumRocks;
        std::vector<SmallRock*> smallRocks;
  
        int score;
        int HP;
        Point topLeft;
        Point bottomRight;

        void advanceBigRock();
        void advanceMediumRock();
        void advanceSmallRock();
        void advanceBullet();
        void advanceShip();
        
        void cleanUp1();
        void cleanUp2();
        void cleanUp3();
        void cleanUp4();

        void handleCollision1();
        void handleCollision2();
        void handleCollision3(); 
        
        
        bool isOnScreen(const Point& point);

   public:
      Game(Point tl, Point br);
      float getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const;
      void advance();
      
      void handleInput(const Interface& ui);
      void draw(const Interface& ui);  
};

#endif /* GAME_H */
