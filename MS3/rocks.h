/*************************************************************
 * File: rocks.h
 * Author: Yiqi Wang
 *
 * Description: header file for flyingObject
 *************************************************************/
#ifndef rocks_h
#define rocks_h

#include "flyingObject.h"
#include "uiDraw.h"

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10
#define M_PI 3.1415


// Define the following classes here:
/*********************************************
 * Rock Class
 *********************************************/
class Rock: public FlyingObject
{
protected:
  int score;
  int lives;
  int spin;
  int size;
  int initialAngle;

public:

   // getfunctions
   int getScore(){return score;}
   int getLives(){return lives;}
   int getSpin(){return spin;}
   int getSize(){return size;}
   int getInitialAngle(){return initialAngle; }

   // setfunctions
   void setScore(int score) {this->score = score; }
   void setLives(int lives) {this->lives = lives; }
   void setSpin(int spin) {this->spin = spin; }
   void setSize(int size) {this->size = size; }
   void setInitialAngle(int angle) {this->initialAngle = initialAngle; }

   // funtions
   int hit();
   //constructors
   
   Rock() : FlyingObject() {}
  


};

/*********************************************
 * Big Rock Class
 *********************************************/
class BigRock : public Rock
{
public:
   // constructors
   
   BigRock(): Rock()
   {
       initialAngle = rand();
       velocity.setDx(-cos(M_PI / 180.0 * initialAngle));
       velocity.setDy(sin(M_PI / 180.0 * initialAngle));
       point.setX(rand());
       point.setY(rand());
       spin = BIG_ROCK_SPIN;
       size = BIG_ROCK_SIZE;
       score = 1;
       lives = 1;
       alive = true;
      

   }
   void draw();
   void advance();
};

/*********************************************
 * Medium Rock Class
 *********************************************/
class MediumRock : public Rock
{
public:
   // constructors
   MediumRock(): Rock()
   {
       initialAngle = rand();
       velocity.setDx(-cos(M_PI / 180.0 * initialAngle));
       velocity.setDy(sin(M_PI / 180.0 * initialAngle));
       point.setX(rand());
       point.setY(rand());
       spin = MEDIUM_ROCK_SIZE;
       size = MEDIUM_ROCK_SIZE;
       score = 1;
       lives = 1;
       alive = true;
   }
    void draw();
    void advance();
};

/*********************************************
 * Small Rock Class
 *********************************************/
class SmallRock : public Rock
{
public:
   // constructors
   
   SmallRock(): Rock()
   {
       initialAngle = rand();
       velocity.setDx(-cos(M_PI / 180.0 * initialAngle));
       velocity.setDy(sin(M_PI / 180.0 * initialAngle));
       point.setX(rand());
       point.setY(rand());
       spin = SMALL_ROCK_SIZE;
       size = SMALL_ROCK_SIZE;
       score = 1;
       lives = 1;
       alive = true;
   }
    void draw();
    void advance();
};


#endif 