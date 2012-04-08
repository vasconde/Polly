CC = g++
CFLAGS = -g -Wall -std=c++98

# # # # #

all:ENZ.o

ENZ.o: ENZ.hpp
	$(CC) $(CFLAGS) -c ENZ.hpp

# # # # #

clean:
	rm -rf *.o
	rm -rf *~

mrproper: clean
	rm -rf ENZ
