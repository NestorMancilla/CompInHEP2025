CC = g++
CFLAGS = -Wall -std=c++11

all: test

test: main.o Track.o SimulatedTrack.o
	$(CC) $(CFLAGS) main.o Track.o SimulatedTrack.o -o test

Track.o: Track.cpp Track.h
	$(CC) $(CFLAGS) -c Track.cpp

SimulatedTrack.o: SimulatedTrack.cpp SimulatedTrack.h Track.h
	$(CC) $(CFLAGS) -c SimulatedTrack.cpp

main.o: main.cpp Track.h SimulatedTrack.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f *.o test

