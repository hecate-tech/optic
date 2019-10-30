all: build run

build:
	cc *.h *.c -Wall -v `pkg-config --libs --cflags raylib`

run: build
	./a.out