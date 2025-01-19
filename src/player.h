#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include "types.h"
typedef struct
{
    int up;
    int down;
} Input;

void MovePlayer(SDL_Rect* player ,i32 startPosX, i32 startPosY, i32 Width, i32 Height);
void RenderPlayers(SDL_Renderer* renderer ,SDL_Rect p1, SDL_Rect p2, SDL_Rect ball);
#endif