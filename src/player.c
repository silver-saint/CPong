
#include "player.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

void  MovePlayer(SDL_Rect* player ,i32 startPosX, i32 startPosY, i32 Width, i32 Height)
{
    player->x = startPosX;
    player->y = startPosY;
    player->w = Width;
    player->h = Height;
}


void RenderPlayers(SDL_Renderer* renderer ,SDL_Rect p1, SDL_Rect p2, SDL_Rect ball)
{
          SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        //player
        SDL_RenderFillRect( renderer, &p1);
        SDL_RenderFillRect( renderer, &p2);
        SDL_RenderFillRect(renderer, &ball);
        SDL_RenderPresent(renderer);
}