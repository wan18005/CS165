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
    FlyingObject() { }
    virtual ~FlyingObject()  { }

    // get functions
    Point getPoint() const { return point; }
    Velocity getVelocity() const { return velocity; }
    bool isAlive() const { return alive; }

    // set functions
    void setPoint(const Point &point) { this->point = point; }
    void setVelocity(const Velocity &velocity) {this->velocity = velocity; }
    void kill() {alive = false; }

    virtual void advance();
    virtual void draw() = 0;


};



#endif /* flyingObject_h */
