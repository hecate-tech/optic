#ifndef GAME_H
#define GAME_H

#include <raylib.h>
#include <stdio.h>
#include <string.h>

#include "common.h"
#include "player.hpp"
#include "unsafe.hpp"

class Game {
   private:
	Camera3D camera{};
	Player player = Player();
	Color backgroundColor = WHITE;

	void update3D(Camera3D*);
	void update2D(Camera3D*);

   public:
	Camera3D* GetCamera() { return &camera; };
	Player* GetPlayer() { return &player; };

	void Update();
	void Unload();

	Game();
};

#endif  // GAME_H