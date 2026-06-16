#include "raylib.h"
#include "engine.h"
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int main() {
    InitWindow(1280, 720, "MicroCraft-9");
    SetTargetFPS(60);

    lua_State *L = init_lua(); // Запуск Lua
    init_world();              // Генерация мира

    Camera3D camera = { { 10, 10, 10 }, { 0, 0, 0 }, { 0, 1, 0 }, 45, 0 };

    while (!WindowShouldClose()) {
        update_logic_lua(L, &camera); // Вся логика — в Lua!
        
        BeginDrawing();
            ClearBackground(SKYBLUE);
            BeginMode3D(camera);
                draw_world();
            EndMode3D();
            DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();
    lua_close(L);
    return 0;
}
