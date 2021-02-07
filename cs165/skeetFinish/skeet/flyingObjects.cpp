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

/*********************************************
 * flyingObjects: Advance
 *********************************************/
void flyingObjects::advance()
{
	point.addX(velocity.getDx());
	point.addY(velocity.getDy());
}
