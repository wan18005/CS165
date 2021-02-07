#ifndef ROBOT_H
#define ROBOT_H

#include "point.h"

class Robot
{
private:
   Point position;
   int energy;

public:
  void display() const;
/********************
* Constructors
********************/
  Robot ();
	Robot(int energy);
	Robot(Point position, int energy);
/********************
* Getters
********************/
Point getPosition() const;
int getEnergy() const;

/********************
* Setters
********************/
	void setPosition(Point p);
	void setEnergy(int energy);
 
 void moveUp();
	
};

#endif
