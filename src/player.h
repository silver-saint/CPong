#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include "types.h"
typedef struct
{
    int up;
    int down;
} Input;

SDL_Rect InitPlayer(i32 startPosX, i32 startPosY, i32 Width, i32 Height);
void MovePlayer( f32* currentYPos, f64 moveBy);
void DrawPlayers(SDL_Renderer* renderer ,SDL_Rect p1, SDL_Rect p2);
#endif