#include "game.hpp"

Game::Game() {
	camera.position = (Vector3){3.0, 3.0, 3.0};
	camera.target = (Vector3){0.0, 1.5, 0.0};
	camera.up = (Vector3){0.0, 1.0, 0.0};
	camera.fovy = 45.0;

	SetCameraMode(camera, CAMERA_ORBITAL);

	player = Player();
}

void Game::Unload() {
	player.Unload();

	CloseWindow();
}

void Game::Update() {
	Camera3D* camera = Game::GetCamera();

	UpdateCamera(camera);

	BeginDrawing();
	ClearBackground(Game::backgroundColor);

	Game::update3D(camera);

	EndDrawing();
}

void Game::update3D(Camera3D* camera) {
	BeginMode3D(*camera);

	player.Render();

	DrawGrid(10, 1.0);
	DrawGizmo(player.position);

	EndMode3D();
}

void Game::update2D(Camera3D* camera) {}