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
    //default 
    Rock() : FlyingObject() 
    {
      setScore(0);
      setLives(0);
      setSpin(0);
      setSize(0);
      setInitialAngle(0);

    }

/*********************************************
* Rock ::  setScore
* set Score 
*********************************************/
void setScore(int score)
    { 
        this->score = score; 
    }
/*********************************************
* Rock ::  getScore
* get Score
*********************************************/
int getScore() 
    { 
        return score; 
    }
/*********************************************
* Rock ::  setLives
* setLives
*********************************************/
void setLives(int lives) 
{ 
    this->lives = lives; 
}
/*********************************************
* Rock ::  getLives
* getLives
*********************************************/
int getLives() 
{ 
    return lives; 
}

/*********************************************
* Rock ::  setSpin
* setSpin
*********************************************/
void setSpin(int spin) 
{ 
    this->spin = spin; 
}

/*********************************************
* Rock ::  getSpin
* getSpin
*********************************************/
int getSpin() 
{ 
    return spin; 
}
/*********************************************
* Rock ::  setSize
* setSize
*********************************************/
void setSize(int size) 
{ 
    this->size = size; 
}

/*********************************************
* Rock ::  getSize
* getSize
*********************************************/
int getSize() 
{ 
    return size; 
}
/*********************************************
* Rock ::  setInitialAngle
* setInitialAngle
**********************************************/
void setInitialAngle(int initialAngle) 
{ 
    this->initialAngle = initialAngle; 
}

/*********************************************
* Rock ::  getInitialAngle
* getInitialAngle
**********************************************/
float getInitialAngle()
{
    return initialAngle;
}

}; // end class rock



/*********************************************
* Big Rock class
* include
**********************************************/
class BigRock : public Rock
{
public:
   BigRock(): Rock()
   {   
       
       initialAngle = random(0, 360);
       velocity.setDx(-cos(M_PI / 180.0 * initialAngle));
       velocity.setDy(sin(M_PI / 180.0 * initialAngle));
       point.setX(random(-200,200));
       point.setY(random(-200,200));
       // begining at random spin
       setSpin(random(0,360));
       // size of the rock 
       setSize(BIG_ROCK_SIZE);
       // score
       setScore(1);
       // lives 
       setLives(1);
       alive = true;
   }
/*********************************************
* BigRock: cpp class
**********************************************/
   int hit();
   void draw();
   void advance();
};// emd big rock class

/*********************************************
* Medium Rock class
* include
**********************************************/
class MediumRock : public Rock
{
public:
   // the same with big rock but with different size and score
   MediumRock(): Rock()
   {
       initialAngle = random(0, 360);
       velocity.setDx(-cos(M_PI / 180.0 * initialAngle));
       velocity.setDy(sin(M_PI / 180.0 * initialAngle));
       point.setX(random(-200, 200));
       point.setY(random(-200, 200));
       setSpin(random(0, 360));
       setSize(MEDIUM_ROCK_SIZE);
       setScore(2);
       setLives(1);
       alive = true;
   }
/*********************************************
* Medium Rock: cpp class
**********************************************/
    int hit();
    void draw();
    void advance();
};// end medium rock



/*********************************************
* Small Rock class
* include
**********************************************/
class SmallRock : public Rock
{
public:
   // constructors
   
   SmallRock(): Rock()
   {
       initialAngle = random(0, 360);
       velocity.setDx(-cos(M_PI / 180.0 * initialAngle));
       velocity.setDy(sin(M_PI / 180.0 * initialAngle));
       point.setX(random(-200, 200));
       point.setY(random(-200, 200));
       setSpin(random(0, 360));
       setSize(SMALL_ROCK_SIZE);
       setScore(3);
       setLives(1);
       alive = true;
   }
/*********************************************
* Small Rock: cpp class
**********************************************/
    int hit();
    void draw();
    void advance();
};


#endif 