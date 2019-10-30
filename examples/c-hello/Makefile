all: build run

build:
	cc main.c `pkg-config --libs --cflags raylib`

run: build
	./a.out