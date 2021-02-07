/*************************************************************
 * File: bullet.cpp
 * Author:Yiqi Wang
 **********************************************/
#include "bullet.h"
#include "uiDraw.h"

/*********************************************
* bullet :: draw
* draw the bullet from uiDraw
* void drawDot(const Point & point);
**********************************************/
void Bullet :: draw()
{
    drawDot(point);
}

/*********************************************
* bullet :: advance
* advance bullet
* Copy from last project
**********************************************/
void Bullet :: advance()
{
    point.addX(velocity.getDx());
    point.addY(velocity.getDy());
    
}
