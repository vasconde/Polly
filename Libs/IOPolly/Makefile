CC = g++
CFLAGS = -g -Wall -std=c++98

OBJ = test.o Data.o Station.o Reading.o
OOBJ = ../SIUnits/SIUnits.o ../BaseCoordinates/Body/GeoCoord.o ../BaseCoordinates/Leafs/ENZ.o

# # # # #

all: test

test: $(OBJ) $(OOBJ)
	$(CC) $(CFLAGS) -o test $(OBJ) $(OOBJ)

test.o: Data.h Station.h Reading.h test.cpp
	$(CC) $(CFLAGS) -c test.cpp

Data.o: Data.h Data.cpp Station.h Reading.h
	$(CC) $(CFLAGS) -c Data.cpp

Station.o: Station.h Station.cpp Reading.h
	$(CC) $(CFLAGS) -c Station.cpp

Reading.o: Reading.h Reading.cpp
	$(CC) $(CFLAGS) -c Reading.cpp

# # # # #

clean:
	rm -rf *.o
	rm -rf *~

mrproper: clean
	rm -rf test