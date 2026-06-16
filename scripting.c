#include "engine.h"

// Экспортируем функцию в Lua: setBlock(x, y, z, id)
int l_set_block(lua_State *L) {
    int x = luaL_checkinteger(L, 1);
    int y = luaL_checkinteger(L, 2);
    int z = luaL_checkinteger(L, 3);
    int id = luaL_checkinteger(L, 4);
    world_set_block(x, y, z, id);
    return 0;
}

void register_api(lua_State *L) {
    lua_pushcfunction(L, l_set_block);
    lua_setglobal(L, "setBlock");
}
