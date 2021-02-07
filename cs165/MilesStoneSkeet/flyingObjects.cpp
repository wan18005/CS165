/*************************************************************
 * File: flyingObject.h
 * Author: Yiqi Wang
 *
 * Description: header file for flyingObject
 *************************************************************/
 
/*************************************************************
 * In this cpp file
 * +advance() : void
*************************************************************/
#include "flyingObjects.h"
using namespace std;

//Advance
void flyingObjects::advance()
{
	point.setX(point.getX() + velocity.getDx());
	point.setY(point.getY() + velocity.getDy());
}
