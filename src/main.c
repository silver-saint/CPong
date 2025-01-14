#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdint.h>
#include "player.h"

//window
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
//paddle size
#define PADDLE_WIDTH 25
#define PADDLE_HEIGHT 100
#define PADDING 50
#define PADDLE_SPEED 50
//movement
float PLAYER_POSITION_Y = 0; 
//has game ended
int quit = 0;



int InitSDL(SDL_Window** win, SDL_Renderer** renderer, SDL_Surface** surface);
void HandleInput(SDL_Event* ev);
int main() 
{
    SDL_Window* win = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Surface* surface = NULL;
    int32_t init = InitSDL(&win, &renderer, &surface);
   if(!init)
   {
        SDL_Quit();
        return -1;
   }
    SDL_Rect p1;
    SDL_Rect p2;
    SDL_Event ev;
    while(!quit)
    {
    while (SDL_PollEvent(&ev))
    {
        HandleInput(&ev);
      

        //render fun;
        SDL_SetRenderDrawColor(renderer, 0x00000000,0x0000000000,0x0000000000,0x0000000000);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        DrawPlayer(&p1, 0, (WINDOW_HEIGHT / 2 - PADDING), PADDLE_WIDTH, PADDLE_HEIGHT);
        DrawPlayer(&p2, (WINDOW_WIDTH - PADDLE_WIDTH + 1), (WINDOW_HEIGHT / 2 - PADDING), PADDLE_WIDTH, PADDLE_HEIGHT);
        SDL_RenderFillRect( renderer, &p1);
        SDL_RenderFillRect( renderer, &p2);
        SDL_RenderPresent(renderer);
        }
    }
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}


int InitSDL(SDL_Window** win, SDL_Renderer** renderer, SDL_Surface** surface)
{
 if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return -1;
    }

    *win = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!(*win)) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        return -1;
    }
    *renderer = SDL_CreateRenderer(*win, 0, SDL_RENDERER_ACCELERATED);
    if(!(*renderer))
    {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        return -1;
    }

    *surface = SDL_GetWindowSurface(*win);
    if(!(*surface))
    {
        printf("SDL_CreateSurface Error: %s\n", SDL_GetError());
        return -1;
    }
    return 1;
}
void HandleInput(SDL_Event* ev)
{
        switch(ev->type)
        {
            case SDL_KEYDOWN:
            {
                switch (ev->key.keysym.sym)
                {
                case SDLK_w:
                {
                }
                break;
                case SDLK_s:
                {
                }
                break;
            }
            break;
            case SDL_QUIT:
            {
                quit = 1;
                break;
            }
        }
    }
}