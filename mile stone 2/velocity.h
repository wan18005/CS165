#ifndef VELOCITY_H
#define VELOCITY_H


// Put your velocity class here, or overwrite this file with your own
// velocity class from the previous project

#include "point.h"
/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Velocity
{
   private:
     float dx;
     float dy;

   public:
     Velocity()
        {
           dx = 0.0;
           dy = 0.0;
        }

   float getDx() const { return dx; }
   float getDy() const { return dy; }

   void setDx(float dx) { this->dx = dx; }
   void setDy(float dy) { this->dy = dy; }


};

#endif
