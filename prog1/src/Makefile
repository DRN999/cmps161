# Makefile for Assignment 2	#
# Noriaki Nakano			#
# nnakano@ucsc.edu			#
# 1418185					#
######################################################################################
# Makefile CMPS109 assignment 2
# prog1: compiles problem1 (institute.exe)
# prog2: compiles problem2 (scanner.exe)
# prog3: (attemps) to compile problem 3 (problem with inheritance) (MAX_Heap.exe)
# all: compiles all problems
# clean: removes exe and object files 
# check1: checks for memory leaks for problem 1 
# check2: checks for memory leaks for problem 2 
# check3: checks for memory leaks for problem 3 
######################################################################################

CXX	=	g++
FLAGS	=	-std=gnu++0x	-Wall 
SOURCES	=	Interpolation.cpp	file_input.cpp
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

