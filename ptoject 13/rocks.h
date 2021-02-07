#ifndef rocks_h
#define rocks_h

#include "flyingObject.h"
#include "uiDraw.h"

#include <stdlib.h>

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10



// Define the following classes here:
//   Rock
class Rock: public FlyingObject
{
protected:
  int reward;
  int life;
  int spin;
  int size;
  int angle;

public:

   // getfunctions
   int getReward(){return reward;}
   int getLife(){return life;}
   int getspin(){return spin;}
   int getSize(){return size;}
   int getAngle(){return angle; }


   // setfunctions
   void setReward(int reward) {this->reward = reward; }
   void setLife(int life) {this->life = life; }
   void setSpin(int spin) {this->spin = spin; }
   void setSize(int size) {this->size = size; }
   void setAngle(int angle) {this->angle = angle; }

   // funtions
   int hit();

   //constructors
   virtual ~Rock(){}
   Rock() : FlyingObject() {}


};
//   BigRock
class BigRock : public Rock
{
public:
   // constructors
   ~BigRock(){ }
   BigRock()
   : Rock()
   {
      angle = rand() % 360;
      velocity.setDx(-cos(M_PI / 180.0 * angle));
      velocity.setDy(sin(M_PI / 180.0 * angle));
      point.setX(rand() % 400 - 200);
      point.setY(rand() % 400 - 200);
      setSpin(BIG_ROCK_SPIN);
      setSize(BIG_ROCK_SIZE);
      setReward(1);
      setLife(1);
      alive = true;
      

   }
   void draw();
   void advance();
};
//   MediumRock
class MediumRock : public Rock
{
public:
   // constructors
   ~MediumRock(){ }
   MediumRock()
   : Rock()
   {
       angle = rand() % 360;
       velocity.setDx(-cos(M_PI / 180.0 * angle));
       velocity.setDy(sin(M_PI / 180.0 * angle));
       point.setX(rand() % 400 - 200);
       point.setY(rand() % 400 - 200);
       setSpin(MEDIUM_ROCK_SPIN);
       setSize(MEDIUM_ROCK_SIZE);
       setReward(1);
       setLife(1);
       alive = true;

   }
    void draw();
    void advance();
};
//   SmallRock
class SmallRock : public Rock
{
public:
   // constructors
   ~SmallRock(){ }
   SmallRock()
   : Rock()
   {
       angle = rand() % 360;
       velocity.setDx(-cos(M_PI / 180.0 * angle));
       velocity.setDy(sin(M_PI / 180.0 * angle));
       point.setX(rand() % 400 - 200);
       point.setY(rand() % 400 - 200);
       setSpin(SMALL_ROCK_SPIN);
       setSize(SMALL_ROCK_SIZE);
       setReward(1);
       setLife(1);
       alive = true;

   }
    void draw();
    void advance();
};


#endif /* rocks_h */
