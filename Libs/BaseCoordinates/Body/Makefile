CC = g++
CFLAGS = -g -Wall -std=c++98

OBJ = test.o GeoCoord.o ENZ.o

# # # # #

all: test

test: $(OBJ)
	$(CC) $(CFLAGS) -o test $(OBJ)

test.o: GeoCoord.o test.cpp
	$(CC) $(CFLAGS) -c test.cpp

GeoCoord.o: GeoCoord.h GeoCoord.cpp
	$(CC) $(CFLAGS) -c GeoCoord.cpp 

ENZ.o: ../Leafs/ENZ.h ../Leafs/ENZ.cpp
	$(CC) $(CFLAGS) -c ../Leafs/ENZ.cpp -o ENZ.o

# # # # #

clean:
	rm -rf *.o
	rm -rf *~

mrproper: clean
	rm -rf test
