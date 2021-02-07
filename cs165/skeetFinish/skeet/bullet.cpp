/*************************************************************
 * File: bullet.cpp
 * Author: Yiqi Wang
 *
 * Description: header file for bullet
 *************************************************************/
 
 /*************************************************************
 * In this cpp file 
 *
 *+advance() : void
 *+fire(point:Point, angle:float) : void
 *************************************************************/
#include "bullet.h"
# define PI           3.1415926 /* pi */
#define BULLET_SPEED 10.0

 /*********************************************
  * Bullet: Default
  *********************************************/
Bullet::Bullet()
{
	alive = true;
	point.setX(200);
	point.setY(-200);
	
	
}
/*********************************************
 * Bullet: fire
 *********************************************/
void Bullet::fire(Point point, float angle)
{  
	
	velocity.setDx(BULLET_SPEED * (-cos(PI / 180.0 * angle)));
	velocity.setDy(BULLET_SPEED * (sin(PI / 180.0 * angle)));
	
	
}
/*********************************************
 * Bullet: draw
 *********************************************/
void Bullet::draw()
{
	drawDot(point);
}

