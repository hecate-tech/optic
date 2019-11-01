#ifndef GAME_H
#define GAME_H

#ifndef RAYLIB_H
#include <raylib.h>
#endif  // RAYLIB_H

#ifndef PLAYER_H
#include "player.h"
#endif  // PLAYER_H

struct Game {
	Camera3D camera;
	Color backgroundColor;
	struct Player player;
} game;

void InitGame();	// Initializes the global game's values.
void UnloadGame();  // Unloads and frees memory that was allocated.
void UpdateGame();  // The update function that should be used in the main game
					// loop.

static void update3D();  // Updates everything that should be rendered in 3D.

#endif  // GAME_H