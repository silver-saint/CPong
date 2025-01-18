#include <SDL2/SDL.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_render.h>
#include <stdio.h>
#include <stdint.h>
#include "player.h"
#include "types.h"
//window
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
//paddle size
#define PADDLE_WIDTH 25
#define PADDLE_HEIGHT 100
#define PADDING 50
#define PADDLE_SPEED 0.8
//movement
f32  VELOCITY = 0;
f32 PLAYER_POSITION_Y = 0; 
//has game ended
i32 quit = 0;


i32 InitSDL(SDL_Window** win, SDL_Renderer** renderer, SDL_Surface** surface);
void HandleInput(SDL_Event* ev, Input* input);
void ClampPosition(f32 playerPos );
void Drawbackground(SDL_Renderer* renderer);
int main() 
{
    SDL_Window* win = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Surface* surface = NULL;
    u8 init = InitSDL(&win, &renderer, &surface);
   if(!init)
   {
        SDL_Quit();
        return -1;
   }
    
    SDL_Rect p1 = InitPlayer( 0, ((WINDOW_HEIGHT / 2) - PADDING), PADDLE_WIDTH, PADDLE_HEIGHT);
    SDL_Rect p2 =   InitPlayer( (WINDOW_WIDTH - PADDLE_WIDTH + 1), ((WINDOW_HEIGHT / 2) - PADDING), PADDLE_WIDTH, PADDLE_HEIGHT);
    SDL_Event ev;
    u64 NOW = SDL_GetPerformanceCounter();
    u64 LAST = 0;
    Input input = {0,0};
    f64 moveByAmount = 0;

    f64 deltaTime = 0;
    while (!quit)
    {
        if(SDL_PollEvent(&ev))
        {
            HandleInput(&ev, &input);
        }
        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();
        deltaTime = ((NOW - LAST)*1000 / (f64)SDL_GetPerformanceFrequency() );
        moveByAmount = (VELOCITY * PADDLE_SPEED * deltaTime);
         MovePlayer(&PLAYER_POSITION_Y, moveByAmount);
        ClampPosition(PLAYER_POSITION_Y);
        
        //background
        Drawbackground(renderer);
        //players
        DrawPlayers(renderer,p1, p2);
         //Move player
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
void HandleInput(SDL_Event* ev, Input* input)
{
        switch(ev->type)
        {
            case SDL_KEYDOWN:
            {
                switch (ev->key.keysym.sym)
                {
                case SDLK_w:
                {
                        input->up = 1;
                     //   VELOCITY = -1;
                }
                break;
                case SDLK_s:
                {
                    input->down = 1;
                   // VELOCITY = 1;
                }
                break;
            }
            break;
            case SDL_KEYUP:
            {
                switch (ev->key.keysym.sym)
                {
                    case SDLK_w:
                    {
                        input->up = 0;
                    }
                    break;
                    case SDLK_s:
                    {
                        input->down = 0;
                    }
                    break;
                }
            }
            break;
            case SDL_QUIT:
            {
                quit = 1;
                break;
            }
        }
    }
    if (input->up == 1)
    {
        VELOCITY = -1;
    }
    else if (input->down == 1)
    {
        VELOCITY = 1;
    }
    else 
    {
        VELOCITY = 0;
    }
    
}
void ClampPosition(f32 playerPosY)
{
    const i32 pos = (i32)(playerPosY);
    //temporary solution, I don't like this.
   const i32 bottomBorder = (WINDOW_HEIGHT - PADDLE_HEIGHT) / 2; 
   const i32 topBorder = -(WINDOW_HEIGHT - PADDLE_HEIGHT) / 2; 
   if(pos > bottomBorder )
   {
        playerPosY = ((WINDOW_HEIGHT - PADDLE_HEIGHT) / 2.0f) ;
   }
   else if(pos < topBorder)
   {   
        playerPosY = -((WINDOW_HEIGHT - PADDLE_HEIGHT) / 2.0f);
   }
}
void Drawbackground(SDL_Renderer* renderer)
{
     SDL_SetRenderDrawColor(renderer, 0x00000000,0x0000000000,0x0000000000,0x0000000000);
    SDL_RenderClear(renderer);
}