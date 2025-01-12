
#include "player.h"

void DrawPlayer(SDL_Rect* player, int startPosX, int startPosY, int Width, int Height)
{
    player->y = startPosX;
    player->x = startPosY;
    player->w = Width;
    player->h = Height;
}