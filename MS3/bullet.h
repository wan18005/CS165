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
class Bullet: public FlyingObject
{
protected:
    int rotatation;
    int HP;
public:
    void draw();
    void advance();
    
    void setHP(int HP) { this->HP = HP; }
    int getHP() { return HP; }
    
    Bullet(Point point, int rotatation, Velocity shipVelocity)
    {
        HP = 40;
        alive = true;
        this->point = point;
        this->rotatation = rotatation;
        // Bullets are should start with the same velocity of the ship (speed and direction) plus 5 pixels per frame in the direction the ship is pointed.
        velocity.setDx(BULLET_SPEED * cos(M_PI / 180.0 * rotatation) + shipVelocity.getDx() );
        velocity.setDy(BULLET_SPEED * sin(M_PI / 180.0 * rotatation) + shipVelocity.getDy() );
        
    };
};
#endif
