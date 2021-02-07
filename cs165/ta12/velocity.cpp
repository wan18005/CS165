#include "velocity.h"

#include <iostream>
using namespace std;

// TODO: Put your method bodies here


// R1

void Velocity :: prompt()
{
   cout << "dx: ";
   cin >> dx;

   cout << "dy: ";
   cin >> dy;
}

void Velocity :: display() const 
{
   cout << "(dx=" << dx << ", dy=" << dy << ")";
}

Velocity operator+(const Velocity & lhs, const Velocity& rhs)
{
   Velocity velocity;

   velocity.setDx(lhs.getDx() + rhs.getDx());
   velocity.setDy(lhs.getDy() + rhs.getDy());

   return velocity;
}

Velocity& operator+=(Velocity& lhs, const Velocity& rhs)
{
   lhs = lhs + rhs;

   return lhs;
}

/*

bool operator==(const Velocity& lhs, const Velocity& rhs)
{
   return lhs.getDx() == rhs.getDx() && lhs.getDy() == rhs.getDy();
}

bool operator!=(const Velocity& lhs, const Velocity& rhs)
{
   return !(lhs == rhs);
}

bool operator>(const Velocity& lhs, const Velocity& rhs)
{
   return lhs.getDx() > rhs.getDx() && lhs.getDy() > rhs.getDy();
}

bool operator<(const Velocity& lhs, const Velocity& rhs)
{
   return lhs.getDx() < rhs.getDx() && lhs.getDy() < rhs.getDy();
}

bool operator>=(const Velocity& lhs, const Velocity& rhs)
{
   return lhs.getDx() >= rhs.getDx() && lhs.getDy() >= rhs.getDy();
}

bool operator<=(const Velocity& lhs, const Velocity& rhs)
{
   return lhs.getDx() <= rhs.getDx() && lhs.getDy() <= rhs.getDy();
}

ostream& operator << (ostream& out, const Velocity& velocity)
{
   out << "(dx=" << velocity.getDx() << ", dy=" << velocity.getDy() << ")" << endl;
   return out;
}

istream& operator>>(istream& in, Velocity& velocity)
{
   float _dx;
   float _dy;

   in >> _dx;
   
   in.clear();

   in >> _dy;

   velocity.setDx(_dx);
   velocity.setDy(_dy);

   return in;
}

Velocity& operator++( Velocity& lhs)
{
   lhs.setDx(lhs.getDx()+1);
   lhs.setDy(lhs.getDy()+1);

   return lhs;
}

Velocity& operator++(Velocity& lhs, int postfix)
{
  Velocity oldValue;
  oldValue.setDx(lhs.getDx());
  oldValue.setDy(lhs.getDy());

  ++lhs; //increment

  return oldValue;

}
*/