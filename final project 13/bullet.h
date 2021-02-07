/*************************************************************
 * File: bullet.h
 * Author: Yiqi Wang
 *
 * Description: header file for bullet
 *************************************************************/
#include "flyingObject.h"
#include "uiDraw.h"
#include "point.h"


#ifndef BULLET_H
#define BULLET_H
#define M_PI 3.1415
#define BULLET_SPEED 5.0

 /*********************************************
 * Bullet class
 **********************************************/
class Bullet: public FlyingObject
{
protected:
    int rotatation;
    int HP;
public:
/*********************************************
* Bullet::setHP
* setHP
**********************************************/
    void setHP(int HP) 
    { 
        this->HP = HP; 
    }
/*********************************************
* Bullet::getHP
* getHP
**********************************************/
    int getHP() 
    { 
        return HP; 
    }
/*********************************************
* Bullet::cpp file function
* setHP
 **********************************************/
    void draw();
    void advance();
    
    
/*********************************************
* Bullet::Bullet
* include
**********************************************/
    Bullet(Point point, int rotatation, Velocity shipVelocity)
    {   //Bullets only live for 40 frames, after which they should "die" and be removed from the game.
        HP = 40;
        alive = true;
        // update point and rotataion
        this->point = point;
        this->rotatation = rotatation;
        // Bullets are should start with the same velocity of the ship (speed and direction) plus 5 pixels per frame in the direction the ship is pointed.
        velocity.setDx(BULLET_SPEED * cos(M_PI / 180.0 * rotatation) + shipVelocity.getDx() );
        velocity.setDy(BULLET_SPEED * sin(M_PI / 180.0 * rotatation) + shipVelocity.getDy()  );
    }
};
#endif
