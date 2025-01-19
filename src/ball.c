#include "ball.h"

void MoveBall(SDL_Rect* ball ,i32 startPosX, i32 startPosY, i32 Width, i32 Height)
{
    ball->x = startPosX;
    ball->y = startPosY;
    ball->w = Width;
    ball->h = Height;
}
