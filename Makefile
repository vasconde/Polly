# Makefile dedicado ah compilacao dos ficheiros objecto

CC = g++
CFLAGS = -g -Wall -std=c++98

BCOODIR = ./Libs/BaseCoordinates
DPROBLEMDIR = ./Libs/GeoMathLib/Traverse
IOPOLLYDIR = ./Libs/IOPolly
SIUNITSDIR = ./Libs/SIUnits

# # # # #

all: $(BCOODIR)/Leafs/ENZ.o $(BCOODIR)/Body/GeoCoord.o $(DPROBLEMDIR)/DProblem.o $(IOPOLLYDIR)/IOPolly.o $(SIUNITSDIR)/SIUnits.o

# ENZ.o

$(BCOODIR)/Leafs/ENZ.o: $(BCOODIR)/Leafs/ENZ.h $(BCOODIR)/Leafs/ENZ.cpp
	$(CC) $(CFLAGS) -c $(BCOODIR)/Leafs/ENZ.cpp -o $(BCOODIR)/Leafs/ENZ.o

# GeoCoord.o

$(BCOODIR)/Body/GeoCoord.o: $(BCOODIR)/Body/GeoCoord.h $(BCOODIR)/Body/GeoCoord.cpp
	$(CC) $(CFLAGS) -c $(BCOODIR)/Body/GeoCoord.cpp -o $(BCOODIR)/Body/GeoCoord.o

# DProblem.o

$(DPROBLEMDIR)/DProblem.o: $(DPROBLEMDIR)/DProblem.h $(DPROBLEMDIR)/DProblem.cpp
	$(CC) $(CFLAGS) -c $(DPROBLEMDIR)/DProblem.cpp -o $(DPROBLEMDIR)/DProblem.o

# IOPolly.o

$(IOPOLLYDIR)/IOPolly.o: $(IOPOLLYDIR)/IOPolly.h $(IOPOLLYDIR)/IOPolly.cpp
	$(CC) $(CFLAGS) -c $(IOPOLLYDIR)/IOPolly.cpp -o $(IOPOLLYDIR)/IOPolly.o

# SIUnits.o

$(SIUNITSDIR)/SIUnits.o: $(SIUNITSDIR)/SIUnits.h $(SIUNITSDIR)/SIUnits.cpp
	$(CC) $(CFLAGS) -c $(SIUNITSDIR)/SIUnits.cpp -o $(SIUNITSDIR)/SIUnits.o