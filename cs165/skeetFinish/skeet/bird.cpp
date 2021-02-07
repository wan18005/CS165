/*************************************************************
 * File: bird.cpp
 * Author: Yiqi Wang
 *
 * Description: All the running function for different kinds of bird
 *
 *************************************************************/
#include "bird.h"
 /*********************************************
  * Bird Class
  *********************************************/
Bird::Bird()
{   
	this->point= point;
	alive = true;
	lives = 1;
	score = 1;
	

/*********************************************
 * Hard Code
 * Work
 *********************************************/
 /*
	point.setX(-200);
	point.setY(random(-150, 150));
	velocity.setDx(random(3, 6));
	if (point.getY() >= 0)
	{

		velocity.setDy(random(-4, -1));
	}
	else
		velocity.setDy(random(1, 4));
*/
}
/*********************************************
  * Bird hit
  * When a bird is hit it loses lives
  *********************************************/
int Bird::hit()
{
	lives = lives -1 ;
	if (lives == 0)
	{
		kill();
		if (bonus)
			return score + bonus;

	}

	return getScore();
}


/*********************************************
 * BirdStandard Class : Draw
 *********************************************/
void StandardBird::draw()

{
	drawCircle(point, 15);
	
}   
/*********************************************
 * BirdStandard Class : Advance
 *********************************************/
void StandardBird::advance()
{
	point.addX(velocity.getDx());
	point.addY(velocity.getDy());
}

/*********************************************
 * Tough Bird Class: Basic
 *********************************************/
ToughBird::ToughBird()
{
	alive = true;
	lives = 3;
	score = 1;
	bonus = 2;
	
	
}
/*********************************************
 * Tough Bird Class: Draw
 *********************************************/
void ToughBird::draw()
{
	drawToughBird(point, 15, lives);
}
/*********************************************
 * Tough Bird Class: Advance
 *********************************************/
void ToughBird::advance()
{
	point.addX(velocity.getDx());
	point.addY(velocity.getDy());
}
/*********************************************
 * Sacred Bird Class: Basic
 *********************************************/
SacredBird::SacredBird()
{
	alive = true;
	lives = 1;
	bonus = 0;
	score = -10;
	
}
/*********************************************
 * Sacred Bird Class: Draw
 *********************************************/
void SacredBird::draw()
{
	drawSacredBird(point, 15);

}
/*********************************************
 * Sacred Bird Class: Advance
 *********************************************/
void SacredBird::advance()
{
	point.addX(velocity.getDx());
	point.addY(velocity.getDy());
}
/*********************************************
 * Boss Bird Class:Basic
 *********************************************/
Boss::Boss()
{
	alive = true;
	lives = 5;
	score = 1;
	bonus = 10;
	

}
/*********************************************
 * Boss Bird Class: Draw
 *********************************************/
void Boss::draw()
{   
#define RED 1
#define GREEN 2
#define BLUE 3
#define YELLOW 4
#define FUCHSINE 5
#define CYAN 6
#define WHITE 7
	// RANDOM COLOUR FOR BOSS
	drawBoss(point, 20, lives, random(1,7));

}
/*********************************************
 * Boss Bird Class: Advance
 *********************************************/
void Boss::advance()
{ 
	point.addX(velocity.getDx());
	point.addY(velocity.getDy());

}

