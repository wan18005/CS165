/*************************************************************
 * File: bird.h
 * Author: Yiqi Wang
 *
 * Description: header file for all kind of birds
 *
 *************************************************************/
#include "flyingObjects.h"
#ifndef bird_h
#define bird_h

/*********************************************
* class for bird
*********************************************/
class Bird : public flyingObjects
{

  public:
	  Bird();
	  int hit();
   private:
	};

/*********************************************
 * BirdStandard Class
 *********************************************/
class StandardBird : public Bird
{
public:
	void advance();
	void draw();
private:
};

/*********************************************
 * BirdTough Class
 *********************************************/
class BirdTough : public Bird
{
public:

private:

};

/*********************************************
 * BirdSacred Class
 *********************************************/
class BirdSacred : public Bird
{
public:

private:

};


#endif