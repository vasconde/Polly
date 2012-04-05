CC = g++
CFLAGS = -g -Wall -std=c++98
ENZFLAG = -I../Leafs
# # # # #


GeoCoord.o: GeoCoord.hpp
	$(CC) $(CFLAGS) -c GeoCoord.hpp $(ENZFLAG)

# # # # #

clean:
	rm -rf *.o
	rm -rf *~

mrproper: clean
	rm -rf GeoCoord
