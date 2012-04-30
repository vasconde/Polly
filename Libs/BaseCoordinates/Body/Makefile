CC = g++
CFLAGS = -g -Wall -std=c++98
GeoCoordFLAG = -I../Leafs

OBJ = test.o GeoCoord.o

# # # # #

all: test

test: test.o GeoCoord.o
	$(CC) $(CFLAGS) -o test $(OBJ)

test.o: GeoCoord.o test.cpp
	$(CC) $(CFLAGS) -c test.cpp $(GeoCoordFLAG)

GeoCoord.o: GeoCoord.h GeoCoord.cpp
	$(CC) $(CFLAGS) -c GeoCoord.cpp $(GeoCoordFLAG)	-c ENZ.cpp

# # # # #

clean:
	rm -rf *.o
	rm -rf *~

mrproper: clean
	rm -rf test
