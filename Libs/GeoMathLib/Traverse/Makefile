CC = g++
CFLAGS = -g -Wall -std=c++98

OBJ = test.o DProblem.o

# # # # #

all: test

test: test.o DProblem.o
	$(CC) $(CFLAGS) -o test $(OBJ)

test.o: DProblem.o test.cpp
	$(CC) $(CFLAGS) -c test.cpp

DProblem.o: DProblem.h DProblem.cpp
	$(CC) $(CFLAGS) -c DProblem.cpp

# # # # #

clean:
	rm -rf *.o
	rm -rf *~

mrproper: clean
	rm -rf test
