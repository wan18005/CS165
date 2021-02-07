/*************************************************************
 * File: flyingObject.h
 * Author: Yiqi Wang
 *
 * Description: header file for flyingObject
 *************************************************************/
 
/*************************************************************
 * In this header file 
 *+getPoint() : Point
 *+getVelocity() : Velocity
 *+isAlive() : bool
 *+setPoint(Point) : void
 *+setVelocity(Velocity) : void
 *+kill() : void
*************************************************************/
#ifndef flyingObjects_H
#define flyingObjects_H
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

using namespace std;
class flyingObjects
{
/*
 protected member variable or function is very similar to a private member but it provided one additional benefit that they can be accessed in child classes which are called derived classes.
*/
protected:
   Point point;
   Velocity velocity;
   bool alive;
   int lives;
   int score;
   int bonus;
   

public:
    flyingObjects() 
    {
        bool alive = 0;
        int lives = 0;
        int score = 0;
        int bonus = 0;
        this->point = point;
    }

 
   // point 
   void setPoint(const Point& point) { this->point = point; }
   Point getPoint() { return point; }
  
   
   
   // velocity 
   void setVelocity(const Velocity& velocity) { this->velocity = velocity; }
   Velocity getVelocity() { return velocity; }
   
   

   //lives
   void setLives(int lives) { this->lives = lives; }
   int getLives() { return lives; }
   
   

   //score
   void setScore(int score) { this->score = score; }
   int getScore() { return score; }
  
   

   //isAlive
   bool isAlive() { return alive; }
   void setAlive(bool alive){this->alive = alive;}
   
   // kill
   void kill() {alive = false;}
   
   

/*************************************************************
* I add this today after the programing exercice
*************************************************************/

   virtual void advance();
   virtual void draw() = 0;

};
#endif 
