#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>

using namespace std;

class Circle
{
public:

	void setRadius(float radius);
	float getRadius();
	void promptForCircle();
	void display();
private:
	float radius;
};


#endif