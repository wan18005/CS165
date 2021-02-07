###############################################################
# Program:
#     Project 09, Skeet
#     Brother Comeau, CS165
# Author:
#     Yiqi Wang
# Summary:
#     Finish with this project
# Above and Beyond
#     Added:
#     1. Another bird called Boss.
#     2. Add colour to Boss and it will change it every second.
#     3. Add text next to the point.
#     4. Add the number of player on under the point.
#     Pending:
#     I had add a buttom F1, but right now it does nothing,
#     I am thinking when F1 is pressed destory all the bird on the screen.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o rifle.o velocity.o flyingObjects.o bullet.o bird.o 
	g++ driver.o game.o uiInteract.o uiDraw.o point.o rifle.o velocity.o flyingObjects.o bullet.o bird.o  $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

game.o: game.cpp uiDraw.h uiInteract.h point.h rifle.h bullet.h bird.h
	g++ -c game.cpp

driver.o: game.h uiInteract.h driver.cpp
	g++ -c driver.cpp

rifle.o: rifle.h point.h uiDraw.h rifle.cpp
	g++ -c rifle.cpp
 
#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#######################################################################
velocity.o: velocity.cpp velocity.h
	g++ -c velocity.cpp

flyingObjects.o: flyingObjects.cpp flyingObjects.h point.h velocity.h
	g++ -c flyingObjects.cpp

bullet.o: bullet.cpp bullet.h flyingObjects.h
	g++ -c bullet.cpp

bird.o: bird.cpp bird.h flyingObjects.h uiDraw.h
	g++ -c bird.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o