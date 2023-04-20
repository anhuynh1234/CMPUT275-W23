CC = g++
CFLAGS = -std=c++11 -g -Wall
BINS = w1 w2 w3
OBJS = w1.o w2.o w3.o

all: w1 w2 w3

w1: w1.o
	$(CC) w1.o -o w1

w1.o: w1.cpp
	$(CC) -c w1.cpp $(CFLAGS)

w2: w2.o
	$(CC) w2.o -o w2

w2.o: w2.cpp
	$(CC) -c w2.cpp $(CFLAGS)

w3: w3.o
	$(CC) w3.o -o w3

w3.o: w3.cpp
	$(CC) -c w3.cpp $(CFLAGS)

clean:
	-rm -f $(OBJS) $(BINS)