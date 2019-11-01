#include "game.h"

void InitGame() {
	game.backgroundColor = WHITE;

	game.camera.position = (Vector3){3.0, 3.0, 3.0};
	game.camera.target = (Vector3){0.0, 1.5, 0.0};
	game.camera.up = (Vector3){0.0, 1.0, 0.0};
	game.camera.fovy = 45.0;

	SetCameraMode(game.camera, CAMERA_ORBITAL);

	game.player = NewPlayer();
}

void UnloadGame() { UnloadPlayer(&game.player); }

static void update3D() {
	BeginMode3D(game.camera);

	DrawModel(game.player.model, game.player.position, 2.0, game.player.color);

	DrawGrid(10, 1.0);
	DrawGizmo(game.player.position);

	EndMode3D();
}

void UpdateGame() {
	UpdateCamera(&game.camera);

	BeginDrawing();
	ClearBackground(game.backgroundColor);

	update3D();

	EndDrawing();
}