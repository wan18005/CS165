#include "flyingObjects.h"
using namespace std;


void flyingObjects::advance()
{
	point.addX(velocity.getDx());
	point.addY(velocity.getDy());
}

