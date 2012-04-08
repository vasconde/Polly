CC = g++
CFLAGS = -Wall -std=c++98

OBJ = main.o SIUnits.o

# # # # #

all: main

main: main.o SIUnits.o
	$(CC) $(CFLAGS) -o main $(OBJ)

main.o: SIUnits.o main.cpp
	$(CC) $(CFLAGS) -c main.cpp

SIUnits.o: SIUnits.h SIUnits.cpp
	$(CC) $(CFLAGS) -c SIUnits.cpp

# # # # #

clean:
	rm -rf *.o
	rm -rf *~

mrproper: clean
	rm -rf main