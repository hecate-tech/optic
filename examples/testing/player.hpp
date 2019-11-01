#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>
#include "common.h"
#include "unsafe.hpp"

class Player {
   private:
	const char* texturePath = "dwarf_diffuse.png";
	const char* modelPath = "dwarf.obj";

   public:
	Texture2D texture{};
	Model model{};
	Vector3 position{};
	Color color;
	float scale;
	int renderLayer;

	void Render() const;
	void Unload();

	Player();
};

#endif  // PLAYER_H