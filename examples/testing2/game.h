#include <raylib.h>
#include <string.h>

typedef struct Player {
    const char* texture_path;
    const char* model_path;
    
    float scale;

    Texture2D texture;
    Model model;
    Vector3 position;
    Color color;
} Player;

static Player newPlayer() {
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

struct Game {
    Camera3D camera;
    Color backgroundColor;
    struct Player player;
} game;

static void unloadPlayer(Player *p) {
    UnloadTexture(p->texture);
    UnloadModel(p->model);
}

void UnloadGame() {
    unloadPlayer(&game.player);
}

void InitGame() {
    game.backgroundColor = WHITE;

    game.camera.position = (Vector3){3.0, 3.0, 3.0};
    game.camera.target = (Vector3){0.0, 1.5, 0.0};
    game.camera.up = (Vector3){0.0, 1.0, 0.0};
    game.camera.fovy = 45.0;

    SetCameraMode(game.camera, CAMERA_ORBITAL);

    game.player = newPlayer();
}

static void update3D() {
    BeginMode3D(game.camera);

    DrawModel(
        game.player.model,
        game.player.position,
        2.0,
        game.player.color
    );

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