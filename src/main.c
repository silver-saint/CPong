#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdint.h>
#include "player.h"


const uint32_t WINDOW_WIDTH = 800;
const uint32_t WINDOW_HEIGHT = 600;
const uint32_t PADDLE_WIDTH = 25;
const uint32_t PADDLE_HEIGHT = 100;
const uint32_t PADDING = 50;
int32_t PLAYER_POSITION_Y = 0; 
const uint32_t PADDLE_SPEED = 5;


int main() {
    
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *win = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!win) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }
    SDL_Renderer* renderer = SDL_CreateRenderer(win, 0, SDL_RENDERER_ACCELERATED);
    if(!renderer)
    {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    SDL_Surface* surface = SDL_GetWindowSurface(win);
    if(!surface)
    {
        printf("SDL_CreateSurface Error: %s\n", SDL_GetError());
        SDL_Quit();
    }
    SDL_Rect p1;
    SDL_Rect p2;
    SDL_Event ev;
    int quit = 0;

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
                        PLAYER_POSITION_Y-=1 * PADDLE_SPEED;
                    }
                    break;
                    case SDLK_s:
                    {
                        PLAYER_POSITION_Y+= 1 * PADDLE_SPEED;
                    }
                    break;
                }
                break;
            }
            case SDL_QUIT:
            {
                quit = 1;
                break;
            }

        }
        SDL_SetRenderDrawColor(renderer, 0x00,0x00,0x00,0x00);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        DrawPlayer(&p1, (WINDOW_HEIGHT / 2 - PADDING) + PLAYER_POSITION_Y, 0, PADDLE_WIDTH, PADDLE_HEIGHT);
        DrawPlayer(&p2, (WINDOW_HEIGHT / 2 - PADDING), (WINDOW_WIDTH - PADDLE_WIDTH), PADDLE_WIDTH, PADDLE_HEIGHT);
        SDL_RenderFillRect( renderer, &p1);
        SDL_RenderFillRect( renderer, &p2);
        SDL_RenderPresent(renderer);
    }
    }
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}