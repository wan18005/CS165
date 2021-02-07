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
#include <iostream>
#include <vector>

#include"flyingObjects.h"
#include "bullet.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"
#include "ship.h"
#include "rocks.h"






#define CLOSE_ENOUGH 15


/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
public:
    /*********************************************
     * Constructor
     * Initializes the game
     *********************************************/
    Game(Point tl, Point br);
    ~Game();

    /*********************************************
     * Function: handleInput
     * Description: Takes actions according to whatever
     *  keys the user has pressed.
     *********************************************/
    void handleInput(const Interface& ui);

    /*********************************************
     * Function: advance
     * Description: Move everything forward one
     *  step in time.
     *********************************************/
    void advance();

    /*********************************************
     * Function: draw
     * Description: draws everything for the game.
     *********************************************/
    void draw(const Interface& ui);
    /*********************************************
    * Function: getClosestDistance
    * Description: get the distance from 2 object
    *********************************************/

    //float getClosestDistance(const flyingObjects& obj1, const flyingObjects& obj2) const;


private:
    // The coordinates of the screen
    Point topLeft;
    Point bottomRight;

    int score;
    

    std::vector<Bullet> bullets;
    std::vector<Rock*> rocks;

    // TODO: declare your bird here (e.g., "Bird * bird;")
    Rock * rock;


    /*************************************************
     * Private methods to help with the game logic.
     *************************************************/
    bool isOnScreen(const Point& point);
    void advanceBullets();
    void advanceRock();
    Rock* createRock();

    void handleCollisions();
    void cleanUpZombies();

};

#endif /* GAME_H */
