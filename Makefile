# Makefile dedicado ah compilacao dos ficheiros objecto

CC = g++
CFLAGS = -g -Wall -std=c++98

BCOODIR = ./Libs/BaseCoordinates
DPROBLEMDIR = ./Libs/GeoMathLib/Traverse/DProblem
IOPOLLYDIR = ./Libs/IOPolly
SIUNITSDIR = ./Libs/SIUnits
NEWMAT = ./Libs/newmat

# # # # #

all: newmat $(BCOODIR)/Leafs/ENZ.o $(BCOODIR)/Body/GeoCoord.o $(DPROBLEMDIR)/DProblem.o $(IOPOLLYDIR)/IOPolly.o $(SIUNITSDIR)/SIUnits.o

# newmat - biblioteca externa para calculo de matrizes
newmat: ./Libs/newmat10/nm_gnu.mak
	make --directory=./Libs/newmat10 -f nm_gnu.mak

# ENZ.o

$(BCOODIR)/Leafs/ENZ.o: $(BCOODIR)/Leafs/ENZ.h $(BCOODIR)/Leafs/ENZ.cpp
	$(CC) $(CFLAGS) -c $(BCOODIR)/Leafs/ENZ.cpp -o $(BCOODIR)/Leafs/ENZ.o

# GeoCoord.o

$(BCOODIR)/Body/GeoCoord.o: $(BCOODIR)/Body/GeoCoord.h $(BCOODIR)/Body/GeoCoord.cpp
	$(CC) $(CFLAGS) -c $(BCOODIR)/Body/GeoCoord.cpp -o $(BCOODIR)/Body/GeoCoord.o

# DProblem.o

$(DPROBLEMDIR)/DProblem.o: $(DPROBLEMDIR)/DProblem.h $(DPROBLEMDIR)/DProblem.cpp
	$(CC) $(CFLAGS) -c $(DPROBLEMDIR)/DProblem.cpp -o $(DPROBLEMDIR)/DProblem.o

# Data.o Station.o Reading.o

$(IOPOLLYDIR)/Data.o: $(IOPOLLYDIR)/Data.h $(IOPOLLYDIR)/Data.cpp $(IOPOLLYDIR)/Station.h $(IOPOLLYDIR)/Reading.h
	$(CC) $(CFLAGS) -c $(IOPOLLYDIR)/Data.cpp -o $(IOPOLLYDIR)/Data.o

$(IOPOLLYDIR)/Station.o: $(IOPOLLYDIR)/Station.h $(IOPOLLYDIR)/Station.cpp $(IOPOLLYDIR)/Reading.h
	$(CC) $(CFLAGS) -c $(IOPOLLYDIR)/Station.cpp -o $(IOPOLLYDIR)/Station.o

$(IOPOLLYDIR)/Reading.o: $(IOPOLLYDIR)/Reading.h $(IOPOLLYDIR)/Reading.cpp
	$(CC) $(CFLAGS) -c $(IOPOLLYDIR)/Reading.cpp -o $(IOPOLLYDIR)/Reading.o


# SIUnits.o

$(SIUNITSDIR)/SIUnits.o: $(SIUNITSDIR)/SIUnits.h $(SIUNITSDIR)/SIUnits.cpp
	$(CC) $(CFLAGS) -c $(SIUNITSDIR)/SIUnits.cpp -o $(SIUNITSDIR)/SIUnits.o
