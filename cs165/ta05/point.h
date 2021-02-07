#ifndef POINT_H
#define POINT_H

class Point
{
private:
   int x;
   int y;

public:
  void display() const;
/********************
    * Constructors
    ********************/
  Point ();
	Point(int x, int y);
/********************
    * Getters
    ********************/
	int getX() const;
	int getY() const;
 /********************
    * Setters
    ********************/
	void setX(int);
	void setY(int);

};

#endif
