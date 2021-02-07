#include "bullet.h"
#include "uiDraw.h"


void Bullet :: draw()
{
    drawDot(point);
}

void Bullet :: advance()
{
    point.addX(velocity.getDx());
    point.addY(velocity.getDy());
    
}
