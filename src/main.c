#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdint.h>
#include "player.h"


#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define PADDLE_WIDTH = 25
#define PADDLE_HEIGHT = 100
#define PADDING = 50
float PLAYER_POSITION_Y = 0; 
#define PADDLE_SPEED = 50;
int InitSDL(SDL_Window* win, SDL_Renderer* renderer, SDL_Surface* surface)
{
 if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return -1;
    }

    win = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!win) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        return -1;
    }
    renderer = SDL_CreateRenderer(win, 0, SDL_RENDERER_ACCELERATED);
    if(!renderer)
    {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        return -1;
    }

    surface = SDL_GetWindowSurface(win);
    if(!surface)
    {
        printf("SDL_CreateSurface Error: %s\n", SDL_GetError());
        return -1;
    }
    return 1;
}
int main() 
{
    SDL_Window *win = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Surface* surface = NULL;

   if(InitSDL(win, renderer, surface) != 1)
   {
        SDL_Quit();
        return -1;
   }
    
    SDL_Rect p1;
    SDL_Rect p2;
    SDL_Event ev;
    int quit = 0;
    float dt = 1.0f / 60.0f;
    float dir = 0;
    while(!quit)
    {
    while (SDL_PollEvent(&ev))
    {
        switch(ev.type)
        {
            case SDL_KEYDOWN:
            {
                switch (ev.key.keysym.sym)
                {
                    case SDLK_w:
                    {
                       dir = -1;
                    }
                    break;
                    case SDLK_s:
                    {
                        dir = 1;
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
        PLAYER_POSITION_Y +=  (dir * dt);

        //render fun;
        SDL_SetRenderDrawColor(renderer, 0x00,0x00,0x00,0x00);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        DrawPlayer(&p1, 0, (WINDOW_HEIGHT / 2 - PADDING) + PLAYER_POSITION_Y, PADDLE_WIDTH, PADDLE_HEIGHT);
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