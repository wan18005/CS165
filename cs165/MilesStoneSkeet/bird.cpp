/*************************************************************
 * File: bird.cpp
 * Author: Yiqi Wang
 *
 * Description: All the running function for different kinds of bird
 *
 *************************************************************/
#include "bird.h"
 /*********************************************
  * Bird Class
  *********************************************/
Bird::Bird()
{
	alive = true;
	lives = 1;
	score = 1;
	this->point = point;
}

int Bird::hit()
{

	kill();
	return getScore();
}
/*********************************************
 * BirdStandard Class
 *********************************************/
void StandardBird::draw()
{
	drawCircle(point, 15);
}   


void StandardBird::advance()
{
	point.setX(point.getX() + velocity.getDx());
	point.setY(point.getY() + velocity.getDy());
}



/*********************************************
 * Bird2 Class
 *********************************************/

/*********************************************
 * Bird3 Class
 *********************************************/