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
class ToughBird : public Bird
{
public:
	ToughBird();
	void advance();
	void draw();

private:

};

/*********************************************
 * BirdSacred Class
 *********************************************/
class SacredBird : public Bird
{
public:
	SacredBird();
	void draw();
	void advance();

private:

};
/*********************************************
 * Boss Bird Class
 *********************************************/
class Boss : public Bird
{
public:
	Boss();
	void draw();
	void advance();
	
private:
	

};

#endif