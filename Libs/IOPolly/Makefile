CC = g++
CFLAGS = -g -Wall -std=c++98

OBJ = test.o IOPolly.o 
OOBJ = ../SIUnits/SIUnits.o ../BaseCoordinates/Body/GeoCoord.o ../BaseCoordinates/Leafs/ENZ.o

# # # # #

all: test

test: $(OBJ) $(OOBJ)
	$(CC) $(CFLAGS) -o test $(OBJ) $(OOBJ)

test.o: IOPolly.o test.cpp
	$(CC) $(CFLAGS) -c test.cpp

IOPolly.o: IOPolly.h IOPolly.cpp
	$(CC) $(CFLAGS) -c IOPolly.cpp

# # # # #

clean:
	rm -rf *.o
	rm -rf *~

mrproper: clean
	rm -rf test