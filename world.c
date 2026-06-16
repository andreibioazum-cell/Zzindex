#include "raylib.h"
#define WORLD_SIZE 32

unsigned char world[WORLD_SIZE][16][WORLD_SIZE];

void draw_world(Texture2D tex) {
    for (int x = 0; x < WORLD_SIZE; x++) {
        for (int z = 0; z < WORLD_SIZE; z++) {
            for (int y = 0; y < 16; y++) {
                if (world[x][y][z]) 
                    DrawCubeTexture(tex, (Vector3){x, y, z}, 1, 1, 1, WHITE);
            }
        }
    }
}
