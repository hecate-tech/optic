#ifndef GAME_H
#define GAME_H

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

typedef enum RenderLayers {
    LAYER_MENU    = 0,
    LAYER_PLAYER,
    LAYER_BACKGROUND,
};

class Player {
private:
    const char* texturePath = "dwarf_diffuse.png";
    const char* modelPath = "dwarf.obj";
public:
    Texture2D texture{};
    Model model{};
    Vector3 position{0,0,0};
    Color color = WHITE;
    float scale = 2.0;
    int renderLayer = LAYER_PLAYER;
    
    void Render();
    void Unload();
    
    Player();
};

class Game {
private:
    Camera3D  camera{};
    Player player = Player();
    Color     backgroundColor = WHITE;

    void update3D(Camera3D*);
    void update2D(Camera3D*);
public:
    Camera3D* GetCamera() { return &camera; };
    
    void Update();
    void Unload();

    Game();
};

#endif // GAME_H