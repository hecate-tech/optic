#ifndef RAYLIB_H
    #include <raylib.h>
#endif // RAYLIB_H

#ifndef _LIBCPP_ERRNO_H
    #include <errno.h>
#endif // _LIBCPP_ERRNO_H

#ifndef _LIBCPP_STRING_H
    #include <string.h>
#endif // _LIBCPP_STRING_H

#ifndef _LIBCPP_STDIO_H
    #include <stdio.h>
#endif // _LIBCPP_STDIO_H

#ifndef __STDARG_H
    #include <stdarg.h>
#endif // __STDARG_H

int main(void) {
    InitWindow(800, 450, "Hello");

    Camera3D camera = { 0 };
    camera.position = (Vector3){3.0, 3.0, 3.0};
    camera.target = (Vector3){0.0, 1.5, 0.0};
    camera.up = (Vector3){0.0, 1.0, 0.0};
    camera.fovy = 45.0;

    // Makes program exit with any level warning and above.
    SetTraceLogExit(LOG_WARNING);
    TraceLogCallback();

    Model dwarf = LoadModel("dwarf.obj");
    Texture2D tex = LoadTexture("dwarf_diffuse.png");

    dwarf.materials[0].maps[MAP_DIFFUSE].texture = tex;
    
    Vector3 position = {0.0, 0.0, 0.0};

    SetTargetFPS(60);
    SetCameraMode(camera, CAMERA_ORBITAL);

    while (!WindowShouldClose()) {
        UpdateCamera(&camera);

        BeginDrawing();

        ClearBackground(DARKGRAY);

        BeginMode3D(camera);

        DrawModel(dwarf, position, 2.0, WHITE);
        DrawGrid(10, 1.0);
        DrawGizmo(position);

        EndMode3D();

        EndDrawing();
    }

    UnloadTexture(tex);
    UnloadModel(dwarf);

    CloseWindow();
}