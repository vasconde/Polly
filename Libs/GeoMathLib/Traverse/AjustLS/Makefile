CC = g++
CFLAGS = -g -Wall -std=c++98

OBJ = test.o AjustLS.o

# # # # #

all: test

test: test.o AjustLS.o
	$(CC) $(CFLAGS) -o test $(OBJ)

test.o: AjustLS.h test.cpp
	$(CC) $(CFLAGS) -c test.cpp

AjustLS.o: AjustLS.h AjustLS.cpp
	$(CC) $(CFLAGS) -c AjustLS.cpp

# # # # #

clean:
	rm -rf *.o
	rm -rf *~

mrproper: clean
	rm -rf test