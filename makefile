CC = g++ -std=c++11 -Wall -Wextra -I.

all: constTest.x fqueue_char.x fqueue_int.x fqueue_string.x

constTest.x: tqueue.h constTest.cpp
	$(CC) -o constTest.x constTest.cpp

fqueue_char.x: tqueue.h fqueue_char.cpp
	$(CC) -o fqueue_char.x fqueue_char.cpp

fqueue_int.x: tqueue.h fqueue_int.cpp
	$(CC) -o fqueue_int.x fqueue_int.cpp

fqueue_string.x: tqueue.h fqueue_string.cpp
	$(CC) -o fqueue_string.x fqueue_string.cpp

clean:
	rm constTest.x fqueue_char.x fqueue_int.x fqueue_string.x