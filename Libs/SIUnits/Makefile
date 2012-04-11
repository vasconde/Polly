CC = g++
CFLAGS = -g -Wall -std=c++98

OBJ = test.o SIUnits.o

# # # # #

all: test

test: test.o SIUnits.o
	$(CC) $(CFLAGS) -o test $(OBJ)

test.o: SIUnits.o test.cpp
	$(CC) $(CFLAGS) -c test.cpp

SIUnits.o: SIUnits.h SIUnits.cpp
	$(CC) $(CFLAGS) -c SIUnits.cpp

# # # # #

clean:
	rm -rf *.o
	rm -rf *~

mrproper: clean
	rm -rf test