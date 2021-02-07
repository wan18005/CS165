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
  int angle;

public:

   // getfunctions
   int getScore(){return score;}
   int getLives(){return lives;}
   int getspin(){return spin;}
   int getSize(){return size;}
   int getAngle(){return angle; }

   // setfunctions
   void setScore(int score) {this->score = score; }
   void setLives(int lives) {this->lives = lives; }
   void setSpin(int spin) {this->spin = spin; }
   void setSize(int size) {this->size = size; }
   void setAngle(int angle) {this->angle = angle; }

   // funtions
   int hit();
   //constructors
   virtual ~Rock() {}
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
       angle = rand();
       velocity.setDx(-cos(M_PI / 180.0 * angle));
       velocity.setDy(sin(M_PI / 180.0 * angle));
       
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
   MediumRock(): Rock(){}
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
   
   SmallRock(): Rock(){}
    void draw();
    void advance();
};


#endif 