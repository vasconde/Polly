CC = g++
CFLAGS = -g -Wall -std=c++98

OBJ = test.o ENZ.o

# # # # #

all: test

test: test.o ENZ.o
	$(CC) $(CFLAGS) -o test $(OBJ)

test.o: ENZ.o test.cpp
	$(CC) $(CFLAGS) -c test.cpp

ENZ.o: ENZ.h ENZ.cpp
	$(CC) $(CFLAGS) -c ENZ.cpp

# # # # #

clean:
	rm -rf *.o
	rm -rf *~

mrproper: clean
	rm -rf test
