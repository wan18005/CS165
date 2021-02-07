/***********************************************************************
 * Program:
 *    Pong. What?  you never heard of pong?
 * Author:
 *    Br. Helfrich
 * Summary:
 *    OK, I couldn't help myself.  The first video game is "Tennis for Two"
 *    developed in 1958 (you read that correctly) by William Higinbotham
 *    as a demo for the computer systems in the Brookhaven National Laboratory.
 *    The display was a normal oscilloscope.  Ours will use slighly more
 *    advanced graphics: OpenGL
 ***********************************************************************/

#include "point.h"       // the ball has a position
#include "uiInteract.h"  // interface with OpenGL
#include "uiDraw.h"      // all the draw primitives exist here

#define PADDLE 20

/*****************************************
 * PONG
 * The main pong structure containing everything
 * necessary to plan our beloved game
 ****************************************/
class Pong
{
public:
   Pong();                          // set up the game
   void advance();                  // advance the game by one move
   void draw();                     // draw everything
   void move(int up, int down);     // move everything
   void strike();                   // did we hit something?
private:
   Point topLeft;
   Point bottomRight;

   Point ball;   // ball position
   float dx;     // horizontal velocity of the ball
   float dy;     // vertical velocity of the ball
   bool dead;    // is the game over?
   int score;    // current score.. how many times did we hit the ball?
   Point paddle; // location of the paddle
};

/***************************************************
 * PONG :: CONSTRUCTOR
 * Give the ball a random vertical velocity and set
 * the positions of everything else.
 ***************************************************/
Pong::Pong() : ball(), dead(false), score(0), paddle()
{
   // set the game bounds
   topLeft = Point(-128, 128);
   bottomRight = Point(128, -128);

   // set the ball position
   ball.setX(topLeft.getX() + 1.0);
   ball.setY((topLeft.getY() - bottomRight.getY()) / 2.0);

   // set the initial ball velocity.  This is the serve
   dx = 4.0;
   dy = (float)random(-2, 2);

   // put the paddle where it belongs
   paddle.setX(bottomRight.getX() - 1.0);
};

/********************************************
 * PONG :: ADVANCE
 * Move the ball forward by some amount
 *******************************************/
void Pong::advance()
{
   // gravity.. just for fun!
//   dy -= .2;
   
   // woops, we missed the ball!
   if (ball.getX() + dx > bottomRight.getX() - 1.0)
      dead = true;

   // bounce off the back wall
   else if (ball.getX() + dx < topLeft.getX() + 1.0)
   {
      ball.setX(topLeft.getX() + 1.0);
      dx *= -1.0;
   }

   // bounce off the ceiling
   else if (ball.getY() + dy > topLeft.getY() - 1.0)
   {
      ball.setY(topLeft.getY() - 1.0);
      dy *= -1.0;
   }

   // and off the floor
   else if (ball.getY() + dy < bottomRight.getY() + 1.0)
   {
      ball.setY(bottomRight.getY() + 1.0);
      dy *= -1.0;
   }
   else
   {
      ball.setX(ball.getX() + dx);
      ball.setY(ball.getY() + dy);
   }
}

/****************************************
 * STRIKE
 * Strike the paddle.  The further from the center,
 * the more it hits
 ****************************************/
void Pong::strike()
{
   // ball not at the paddle yet
   if (ball.getX() + dx < bottomRight.getX() - 2.0)
      return;

   // missed!
   float distance = ball.getY() - paddle.getY();
   if (fabs(distance) > PADDLE)
      return;

   //
   // yeah, we hit the ball
   //
   
   // hit.  Change the dx direction.
   dx *= -1.0;
   ball.setX(bottomRight.getX() - 1.0);

   // get some score
   score++;

   // speed up every 5 points
   if (score % 5 == 0)
      dx += -1.0;

   // the dy is changed by the angle.
   dy += distance / 5;
}

/**************************************************
 * PONG : MOVE
 * Move the paddle
 *************************************************/
void Pong::move(int up, int down)
{
   if (up && paddle.getY() < topLeft.getY())
      paddle.addY( 5);
   if (down && paddle.getY() > bottomRight.getY())
      paddle.addY(-5);
}

/*************************************************
 * PONG : DRAW
 * Draw the stuff
 ************************************************/
void Pong::draw()
{
   // draw the ball and the paddle
   drawRect(paddle, 2, PADDLE * 2, 0);

   // draw the ball
   if (!dead)
      drawCircle(ball, 8);

   // draw the score
   Point point(topLeft.getX() + 5, topLeft.getY() - 5);
   drawNumber(point, score);
}

/*********************************************
 * CALLBACK
 * The main interaction loop of the engine.
 * This gets called from OpenGL.  It give us our
 * interface pointer (where we get our events from)
 * as well as a void pointer which we know is our
 * game class.
 *********************************************/
void callBack(const Interface *pUI, void *p)
{
   // we know the void pointer is our game class so
   // cast it into the game class.
   Pong *pPong = (Pong *)p;

   // advance the ball
   pPong->advance();

   // check the paddle
   pPong->move(pUI->isUp(), pUI->isDown());

   // did we hit the ball?
   pPong->strike();

   // draw it
   pPong->draw();
}


/*********************************
 * MAIN
 * initialize the drawing window, initialize
 * the game,and run it!
 *********************************/
int main(int argc, char **argv)
{
   // Start the drawing, and set the window size
   Interface ui(argc, argv, "Pong!", Point(-128, 128), Point(128, -128));

   // play the game.  Our function callback will get called periodically
   Pong pong;  
   ui.run(callBack, (void *)&pong);

   return 0;
}
