#include "player.h"

Player NewPlayer() {
	Player p;

	p.texture_path = "dwarf_diffuse.png";
	p.model_path = "dwarf.obj";

	p.color = WHITE;
	p.model = LoadModel(p.model_path);
	p.texture = LoadTexture(p.texture_path);
	p.scale = 2.0;

	p.model.materials[0].maps[MAP_DIFFUSE].texture = p.texture;

	return p;
}

void UnloadPlayer(Player *p) {
	UnloadTexture(p->texture);
	UnloadModel(p->model);
}