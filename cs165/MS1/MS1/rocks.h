#ifndef rocks_h
#define rocks_h
#include "flyingObjects.h"

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10



// Define the following classes here:
//   Rock
//   BigRock
//   MediumRock
//   SmallRock

/*********************************************
 * Rock Class
 *********************************************/
class Rock : public flyingObjects
{
public:
	Rock();
	int hit();


};

/*********************************************
 * Small Rock Class
 *********************************************/
class SmallRock : public Rock
{
public:
	SmallRock();
	void draw();
	void advance();
};



/*********************************************
 * Medium Rock Class
 *********************************************/
class MediumRock : public Rock
{
public:
	MediumRock();
	void draw();
	void advance();

};

/*********************************************
 * Big Rock Class
 *********************************************/
class BigRock : public Rock
{
public:
	BigRock();
	void draw();
	void advance();
};


#endif /* rocks_h */
