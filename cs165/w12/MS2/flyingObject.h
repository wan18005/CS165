/*************************************************************
 * File: flyingObject.h
 * Author: Yiqi Wang
 *
 * Description: header file for flyingObject
 *************************************************************/
#ifndef flyingObject_h
#define flyingObject_h

#include "point.h"
#include "velocity.h"
#include <stdio.h>


// Put your FlyingObject class here
class FlyingObject
{
protected:
   Point point;
   Velocity velocity;
   bool alive;
   int lives;
   int score;
   int bonus;
public:
    //constructors
    FlyingObject() 
    {
        bool alive = 0;
        int lives = 0;
        int score = 0;
        int bonus = 0;
    }
    virtual ~FlyingObject()  { }

/*********************************************
* getter
 *********************************************/
    Point getPoint() const { return point; }
    Velocity getVelocity() const { return velocity; }
    bool isAlive() const { return alive; }
    int getLives() { return this->lives; }
    int getScore() { return score; }
    int getBonus() { return bonus; }
    
/*********************************************
 * setter
*********************************************/
    void setPoint(const Point &point) { this->point = point; }
    void setVelocity(const Velocity &velocity) {this->velocity = velocity; }
    void setLives(int lives) { this->lives = lives; }
    void setScore(int score) { this->score = score; }
    void setBonus(int bonus) { this->bonus = bonus; }
    void kill() { alive = false; }
    
    virtual void advance();
    virtual void draw() = 0;
};



#endif
