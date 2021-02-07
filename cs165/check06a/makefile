###############################################################
# Program:
#     Checkpoint 06a, Makefiles
#     Brother Comeau, CS165
# Author:
#     Yiqi Wang
# Summary:
#     Got some problem with missing separator error than I
#     realize I need to use tab other than space
###############################################################


# Insert your rule for a.out here:
a.out : robot.o point.o check06a.o
	g++ robot.o point.o check06a.o

# Insert your rule for robot.o here:
robot.o : robot.cpp robot.h point.h
	g++ -c robot.cpp

# Insert your rule for point.o here:
point.o : point.cpp point.h
	g++ -c point.cpp

# Insert your rule for check06a.o here:
check06a.o : check06a.cpp robot.h
	g++ -c check06a.cpp