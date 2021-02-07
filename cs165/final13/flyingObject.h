/*************************************************************
 * File: flyingObject.h
 * Author: Yiqi Wang
 *
 * Description: header file for flyingObject
 *************************************************************/
#ifndef flyingObject_h
#define flyingObject_h

#include "point.h"
#include "velocity.h"
#include <stdio.h>


// Put your FlyingObject class here
class FlyingObject
{
protected:
   Point point;
   Velocity velocity;
   bool alive;
   
public:
    //constructors
    FlyingObject() 
    {
        this->point = point;
        this->velocity = velocity;
        bool alive = true;
    }
    
    /*********************************************
    * FlyingObject :: getPoint
    * getPoint
    **********************************************/
    Point getPoint() const 
    { 
        return point; 
    }

    /*********************************************
    * FlyingObject :: setPoint
    * setPoint
    **********************************************/
    void setPoint(const Point& point)
    {
        this->point = point;
    }

    /*********************************************
    * FlyingObject :: getVelocity
    * getVelocity
    **********************************************/
    Velocity getVelocity() const
    {
        return velocity;
    }


    /*********************************************
    * FlyingObject :: getVelocity
    * getVelocity
    **********************************************/
    void setVelocity(const Velocity& velocity)
    {
        this->velocity = velocity;
    }

    /*********************************************
    * FlyingObject :: isAlive
    * isAlive
    **********************************************/
    bool isAlive() const 
    { 
        return alive; 
    }
    /*********************************************
    * FlyingObject :: kill
    * kill
    **********************************************/
    void kill() 
    { 
        alive = false; 
    }
    
/*********************************************
* FlyingObject :: cpp file function
**********************************************/
    virtual void advance();
    virtual void draw() = 0;
    
};



#endif
