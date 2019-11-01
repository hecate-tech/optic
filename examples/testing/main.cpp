#ifndef GAME_H
#include "game.hpp"
#endif  // GAME_H

int main() {
	InitWindow(800, 450, "Hello C++");

	SetTargetFPS(60);

	Game game;  // Automatically calls Game constructor.

	while (!WindowShouldClose()) {
		// Update the game's objects.
		game.Update();
	}

	// Unload all the game assets from memory.
	game.Unload();

	return 0;
}