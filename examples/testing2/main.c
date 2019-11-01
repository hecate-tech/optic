#include "game.h"

int main(void) {
    InitWindow(800, 450, "Hello Pure-C");

    SetTargetFPS(60);

    // Initialize everything in the game.
    InitGame();

    while (!WindowShouldClose()) {
        // Update the game using a helper function.
        UpdateGame();
    }

    // Unload the game.
    UnloadGame();

    return 0;
}