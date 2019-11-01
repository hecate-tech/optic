all: build run

build:
	g++ *.cpp -std=c++17 -Wall -I*.hpp `pkg-config --libs --cflags raylib`

run: build
	./a.out