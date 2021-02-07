#include "flyingObject.h"

void FlyingObject::advance()
{
    point.addX(velocity.getDx());
    point.addY(velocity.getDy());
}

// Put your FlyingObject method bodies here
