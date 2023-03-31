# Makefile for the BSTMap test program

CC=g++
LFLAGS=
CFLAGS=-c -std=c++11 -Wall -O2
OBJS=bstmaptest.o
PROJ=bstmaptest

$(PROJ): $(OBJS)
	$(CC) $(OBJS) -o $(PROJ) $(LFLAGS)

bstmaptest.o: bstmaptest.cpp bstmap.h bstaux.h
	$(CC) bstmaptest.cpp -o bstmaptest.o $(CFLAGS)

clean:
	@rm -f $(OBJS) $(PROJ)
