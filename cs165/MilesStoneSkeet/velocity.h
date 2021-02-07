/*************************************************************
 * File: velocity.h
 * Author: Yiqi Wang
 *
 * Description: header file for bullet
 *************************************************************/


#ifndef VELOCITY_H
#define VELOCITY_H
#include <iostream>

class Velocity
{
private:
    float Vx;
    float Vy;

public:
    float getDx() const { return Vx; };
    float getDy() const { return Vy; };

    void setDx(float x) { Vx = x; };
    void setDy(float y) { Vy = y; };

    Velocity()
    {
        setDx(0);
        setDy(0);
    }

    Velocity(float x, float y)
    {
        setDx(x);
        setDy(y);
    }
};



#endif