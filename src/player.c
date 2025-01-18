
#include "player.h"

void DrawPlayer(SDL_Renderer* renderer, SDL_Rect* player, int startPosX, int startPosY, int Width, int Height)
{
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    player->x = startPosX;
    player->y = startPosY;
    player->w = Width;
    player->h = Height;
    SDL_RenderFillRect( renderer, player);
    SDL_RenderPresent(renderer);

}