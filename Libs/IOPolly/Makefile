CC = g++
CFLAGS = -g -Wall -std=c++98

OBJ = test.o IOPolly.o SIUnits.o

# # # # #

all: test

test: $(OBJ)
	$(CC) $(CFLAGS) -o test $(OBJ)

test.o: IOPolly.o test.cpp
	$(CC) $(CFLAGS) -c test.cpp

IOPolly.o: IOPolly.h IOPolly.cpp
	$(CC) $(CFLAGS) -c IOPolly.cpp

SIUnits.o: ../SIUnits/SIUnits.h ../SIUnits/SIUnits.cpp
	$(CC) $(CFLAGS) -c ../SIUnits/SIUnits.cpp -o SIUnits.o

# # # # #

clean:
	rm -rf *.o
	rm -rf *~

mrproper: clean
	rm -rf test