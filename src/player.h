#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

typedef struct
{
    int32_t up;
    int32_t down;
} Input;

void DrawPlayer(SDL_Rect* player, int startPosX, int startPosY, int Width, int Height);

#endif