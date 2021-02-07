#include "rocks.h"

// Put your Rock methods here
/*********************************************
 * Rock Class: Basic
 *********************************************/

Rock::Rock()
{

}
/*********************************************
  * Rock hit
  * When a Rock is hit it loses lives
  *********************************************/
int Rock::hit()
{
	lives = lives - 1;
	if (lives == 0)
	{
		kill();

		if (bonus)
			return score + bonus;

	}

	return getScore();
}

/*********************************************
 * SmallRock Class: Basic
 *********************************************/
SmallRock::SmallRock()
{
	
	
}
/*********************************************
 * SmallRock Class: Draw
 *********************************************/
void SmallRock::draw()
{
	
	drawSmallAsteroid(point, SMALL_ROCK_SPIN);

}
/*********************************************
 * SmallRock Class: Advance
 *********************************************/
void SmallRock::advance()
{
	point.addX(velocity.getDx());
	point.addY(velocity.getDy());
}
/*********************************************
 * MediumRock Class: Basic
 *********************************************/
MediumRock::MediumRock()
{
	

}
/*********************************************
 * MediumRock Class: Draw
 *********************************************/
void MediumRock::draw()
{
	drawMediumAsteroid(point, MEDIUM_ROCK_SPIN);
}
/*********************************************
 * MediumRock Class: Advance
 *********************************************/
void MediumRock::advance()
{
	point.addX(velocity.getDx());
	point.addY(velocity.getDy());
}
/*********************************************
 * BigRock Class: Basic
 *********************************************/
BigRock::BigRock()
{
	

}
/*********************************************
 * BigRock Class: draw
 *********************************************/
void BigRock::draw()
{
	drawLargeAsteroid(point, BIG_ROCK_SPIN);
}
/*********************************************
 * BigRock Class: advance
 *********************************************/
void BigRock::advance()
{
	point.addX(velocity.getDx());
	point.addY(velocity.getDy());
}