CFLAGS = -ggdb -std=c++11

p1.x: main.cpp
	g++ $(CFLAGS) -o p1.x main.cpp
