CC = g++
CFLAGS = -g -Wall -std=c++98

OBJ = test.o IOPolly.o

# # # # #

all: test

test: test.o IOPolly.o
	$(CC) $(CFLAGS) -o test $(OBJ)

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