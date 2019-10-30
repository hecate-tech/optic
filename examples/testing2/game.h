#include <raylib.h>

struct Player {
    const char* texture_path;
    const char* model_path;
    
    Texture2D texture;
    Model model;
    Vector3 position;
    Color color;
    float scale;
};

struct Player newPlayer() {
    struct Player p;

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
    struct Player player;
    Color backgroundColor;
};

static void unloadPlayer(struct Player *p) {
    UnloadTexture(p->texture);
    UnloadModel(p->model);
}

void UnloadGame(struct Game *g) {
    unloadPlayer(&g->player);
}

void InitGame(struct Game *g) {
    g->backgroundColor = WHITE;

    g->camera.position = (Vector3){3.0, 3.0, 3.0};
    g->camera.target = (Vector3){0.0, 1.5, 0.0};
    g->camera.up = (Vector3){0.0, 1.0, 0.0};
    g->camera.fovy = 45.0;

    SetCameraMode(g->camera, CAMERA_ORBITAL);

    g->player = newPlayer();
}

static void update3D(struct Game* g) {
    BeginMode3D(g->camera);

    DrawModel(g->player.model, g->player.position, 2.0, g->player.color);

    DrawGrid(10, 1.0);
    DrawGizmo(g->player.position);

    EndMode3D();
}

void UpdateGame(struct Game* g) {
    UpdateCamera(&g->camera);

    BeginDrawing();
    ClearBackground(g->backgroundColor);

    update3D(g);

    EndDrawing();
}