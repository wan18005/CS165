###############################################################
# Program:
#     Pong
# Author:
#     Br. Helfrich
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main Moon Lander game
###############################################################
a.out: pong.o uiInteract.o uiDraw.o point.o
	g++ pong.o uiInteract.o uiDraw.o point.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

pong.o: pong.cpp uiDraw.h uiInteract.h point.h
	g++ -c pong.cpp


###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o *.tar
