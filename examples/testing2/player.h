#ifndef PLAYER_H
#define PLAYER_H

#ifndef RAYLIB_H
#include <raylib.h>
#endif  // RAYLIB_H

typedef struct Player {
	const char *texture_path;
	const char *model_path;

	float scale;

	Texture2D texture;
	Model model;
	Vector3 position;
	Color color;
} Player;

Player NewPlayer();
void UnloadPlayer(Player *);

#endif  // PLAYER_H