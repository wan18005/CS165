#include "bullet.h"
#include "uiDraw.h"


#define BULLET_SPEED 10.0

void Bullet :: draw()
{
    drawDot(point);
}

void Bullet :: advance()
{
    point.addX(velocity.getDx());
    point.addY(velocity.getDy());
    
}
