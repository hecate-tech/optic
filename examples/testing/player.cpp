#include "player.hpp"

Player::Player() {
	color = WHITE;
	scale = 2.0;
	renderLayer = RenderLayers::PLAYER;
	texture = LoadTexture(texturePath);

	unsafe::PauseLogger();
	model = LoadModel(modelPath);
	unsafe::ResumeLogger();

	model.materials[0].maps[MAP_DIFFUSE].texture = texture;
}

void Player::Render() const { DrawModel(model, position, scale, color); }

void Player::Unload() {
	UnloadModel(model);
	UnloadTexture(texture);
}