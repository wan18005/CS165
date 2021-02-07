#include "robot.h"
#include <iostream>
using namespace std;

/************************************
 * Function: Display
 * Purpose: Displays the robot.
 ************************************/



void Robot :: display() const
{
   position.display();
   cout << " - Energy: " << getEnergy();
}

/********************
* Getters
********************/

int Robot::getEnergy() const
{
	return this->energy;
}

/********************
* Setters
********************/
void Robot::setPosition(Point p)
{
	this->position = p;
}
void Robot::setEnergy(int energy)
{
	if (energy < 0)
	{
		this->energy = 0;
	}
	else
	{
		this->energy = energy;
	}
}
/********************
* Constructors
********************/
Robot :: Robot()
{
  energy = 100;
}
Robot::Robot(int energy)
{
	setEnergy(energy);
}
Robot::Robot(Point position, int energy)
{
   setEnergy(energy);
   setPosition(position);
}


/********************
* Stretch 
********************/
Robot::moveUp(int y)
{
   this->y = y+1;



}





