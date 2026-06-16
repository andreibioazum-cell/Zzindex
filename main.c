#include "raylib.h"
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

lua_State* L;

void UpdateGame() {
    lua_getglobal(L, "update");
    lua_pushnumber(L, GetFrameTime());
    lua_pcall(L, 1, 0, 0);
}

void DrawGame() {
    BeginDrawing();
    ClearBackground(SKYBLUE);
    lua_getglobal(L, "draw");
    lua_pcall(L, 0, 0, 0);
    EndDrawing();
}

int main() {
    InitWindow(1280, 720, "Cubic Battle");
    L = luaL_newstate();
    luaL_openlibs(L);
    if (luaL_dofile(L, "logic.lua")) return 1;

    while (!WindowShouldClose()) {
        UpdateGame();
        DrawGame();
    }
    CloseWindow();
    return 0;
}
