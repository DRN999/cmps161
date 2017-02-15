# Makefile for Assignment 2	#
# Noriaki Nakano			#
# nnakano@ucsc.edu			#
# 1418185					#
######################################################################################
# Makefile CMPS161 prog1
# prog1: compiles prog1 

# all: compiles all 
# clean: removes exe and object files 
# check: checks for memory leaks

######################################################################################

CXX	=	g++
FLAGS	=	-std=gnu++0x	-Wall 
SOURCES	=	Interpolation.cpp	file_input.cpp	cell_grid.cpp	cell.cpp
OBJECTS	=	$(SOURCES:.cpp=.o)
EXEBIN	=	Interpolation


######################################################################################

all:	prog1

prog1:	$(SOURCES)
	$(CXX)	$(FLAGS)	-o	$(EXEBIN)	$(SOURCES)	-g

clean:
	rm	-f	$(EXEBIN) $(OBJECTS)

check:
	valgrind	--leak-check=full	-v $(EXEBIN)

	
######################################################################################

