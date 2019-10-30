#include "game.h"

int main(void) {
    InitWindow(800, 450, "Hello Pure-C");

    SetTargetFPS(60);

    struct Game game; // Zero value Game struct.

    // Initialize everything in the game.
    InitGame(&game);

    while (!WindowShouldClose()) {
        // Update the game using a helper function.
        UpdateGame(&game);
    }

    // Unload the game.
    UnloadGame(&game);

    return 0;
}