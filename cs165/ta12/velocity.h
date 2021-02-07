#ifndef VELOCITY_H
#define VELOCITY_H
#include <iostream>
class Velocity
{
private:
   float dx;
   float dy;

public:
   /**************************
    * Getters and Setters
    **************************/
   float getDx() const { return dx; }
   float getDy() const { return dy; }

   void setDx(float dx) { this->dx = dx; }
   void setDy(float dy) { this->dy = dy; }

   /**************************
    * Public member functions
    **************************/
   void prompt();
   void display() const;
   
   /*****************************
    * Non-Member Friend Operators
    *****************************/
   friend Velocity operator - (const Velocity& lhs, const Velocity& rhs);
   friend Velocity & operator -= ( Velocity & lhs, const Velocity& rhs);
};

// R1 

Velocity operator + (const Velocity& lhs, const Velocity& rhs);
Velocity & operator += ( Velocity & lhs, const Velocity& rhs);



//strectch 1 
/*
bool operator == (const Velocity& lhs, const Velocity& rhs);

bool operator != (const Velocity& lhs, const Velocity& rhs);

bool operator > (const Velocity& lhs, const Velocity& rhs);
bool operator < (const Velocity& lhs, const Velocity& rhs);

bool operator >= (const Velocity& lhs, const Velocity& rhs);
bool operator <= (const Velocity& lhs, const Velocity& rhs);
// S2

std::ostream & operator << (ostream & out, const Velocity & velocity);
std::istream &  operator >> (istream & in, Velocity & velocity);
//S3
Velocity & operator ++( Velocity & lhs);
Velocity& operator ++(Velocity& lhs, int postfix);
*/
#endif
