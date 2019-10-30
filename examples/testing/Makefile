all: build run

build:
	# cc *.hpp *.cpp -std=c++17 -Wall -v `pkg-config --libs --cflags raylib`
	cc *.cpp -std=c++17 -Wall -I*.hpp -v `pkg-config --libs --cflags raylib`

run: build
	./a.out