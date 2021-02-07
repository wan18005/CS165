#include "flyingObject.h"
#include "uiDraw.h"

#ifndef BULLET_H
#define BULLET_H


class Bullet: public FlyingObject
{
protected:
    int direction;
    int lifePoints;
public:
    void draw();
    void advance();
    
    void setLifePoints(int lifePoints) { this->lifePoints = lifePoints; }
    int getLifePoints() { return lifePoints; }
    
    Bullet(Point point, int direction, Velocity shipVelocity)
    {

        alive = true;
        this->point = point;
        this->direction = direction;
        velocity.setDx(5 * cos(M_PI / 180.0 * direction) + shipVelocity.getDx());
        velocity.setDy(5 * sin(M_PI / 180.0 * direction) + shipVelocity.getDy());
        lifePoints = 40;
    };
};
#endif
