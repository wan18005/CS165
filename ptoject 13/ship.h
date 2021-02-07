#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5

#include "flyingObject.h"
#include "uiDraw.h"
#include <stdlib.h>


// Put your Ship class here
class Ship: public FlyingObject
{
   protected:
      bool thrust;
      int movement;
      int direction;
      float speed;
      int size;
    
   public:
    
    
     void setThrust(bool thrust) { this->thrust = thrust; }
     bool getThrust() const { return thrust; }
    
     void setSize(int size) {this->size = size; }
     int getSize(){return size;}
    
     void setDirection(int direction) { this->direction = direction; }
     int getDirection() const { return direction; }
    
     void draw();
     void applyThrust();
     void rotateLeft();
     void rotateRight();
     void advance();
    
    Ship()
    {
        movement = 60;
        speed = 0;
        alive = true;
        thrust = false;
        velocity.setDx(speed * -cos(M_PI / 180.0 * movement));
        velocity.setDy(speed * sin(M_PI / 180.0 * movement));
        point.setX(0);
        point.setY(0);
        setSize(SHIP_SIZE);
        
    }

};

#endif /* ship_h */
