//
//  velocity.h
//  myMoonLander
//
//  Created by Scott Burton on 10/22/15.
//  Copyright © 2015 Scott Burton. All rights reserved.
//

#ifndef velocity_h
#define velocity_h

#include "point.h"

class Velocity
{
private:
   float dx;
   float dy;
   
public:
  
   //getter
   float getDx() const { return dx; }
   float getDy() const { return dy; }
   //setter
   void setDx(float x) { dx = x; }
   void setDy(float y) { dy = y; }
   //constructor
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
