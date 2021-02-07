#include "bullet.h"
#include "uiDraw.h"
#include <cmath>

#define BULLET_SPEED 10.0

void Bullet :: draw()
{
    drawDot(point);
}

void Bullet :: advance()
{
    point.setX(point.getX() + velocity.getDx());
    point.setY(point.getY() + velocity.getDy());
    if(getPoint().getX() > 200)
    {
        point.setX(200 * -1);
    }
    else if (getPoint().getX() < -200)
    {
        point.setX(-200 * -1);
    }
    if(getPoint().getY() > 200)
    {
        point.setY(200 * -1);
    }
    else if (getPoint().getY() < -200)
    {
        point.setY(-200 * -1);
    }
    lifePoints--;
}
