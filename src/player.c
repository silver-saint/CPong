
#include "player.h"

SDL_Rect InitPlayer(i32 startPosX, i32 startPosY, i32 Width, i32 Height)
{
    SDL_Rect player = {startPosX, startPosY, Width, Height};
    return player;
}

void MovePlayer(f32* currentYPos, f64 moveBy)
{
        *currentYPos += moveBy;
}

void DrawPlayers(SDL_Renderer* renderer ,SDL_Rect p1, SDL_Rect p2)
{
          SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        //player
        SDL_RenderFillRect( renderer, &p1);
        SDL_RenderFillRect( renderer, &p2);
        SDL_RenderPresent(renderer);
}