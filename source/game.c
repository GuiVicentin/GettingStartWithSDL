//
//  game.c
//  FirstGame
//
//  Created by Guilherme Vicentin on 04/10/15.
//  Copyright © 2015 Guilherme Vicentin. All rights reserved.
//

#include "game.h"

Game* initGame (void)
{
    Game* new_game = (Game*) malloc(sizeof(Game));
    
    SDL_Init(SDL_INIT_EVERYTHING);
    
    new_game->m_window = SDL_CreateWindow("First Game", 100, 100, 640, 480, 0);
    if (new_game->m_window == NULL)
    {
        printf("Nao foi possivel criar uma janela!\n");
        exit(1);
    }
    
    new_game->m_renderer = SDL_CreateRenderer(new_game->m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (new_game->m_renderer == NULL)
    {
        printf("Nao foi possivel criar um renderer!\n");
        exit(2);
    }

    loadGameContext(new_game);
    
    printf("Jogo inicializado com sucesso\n");
    new_game->isRunning = true;
    return new_game;
}

void closeGame (Game* pGame)
{
    printf("Limpando jogo e fechando...\n");
    
    //liberando SDL
    SDL_DestroyRenderer(pGame->m_renderer);
    SDL_DestroyWindow(pGame->m_window);
    SDL_Quit();
    
    //liberando objetos do game
    destroyPlayer(pGame->player);
    free(pGame);
}

void loadGameContext (Game* pGame)
{
    //inicializando player
    pGame->player = createPlayer(300.0f, 220.0f);
}

void handleEvents (Game* pGame)
{
    SDL_Event event;
    
    while(SDL_PollEvent(&event))
    {
        switch (event.type) {
            case SDL_QUIT:
                pGame->isRunning = false;
                break;
                
            default:
                break;
        }
    }
    
    const Uint8* keys = SDL_GetKeyboardState(NULL);
    if (keys[SDL_SCANCODE_RIGHT])
    {
        if (pGame->player->m_dx < 200.0f)
            pGame->player->m_dx += 20.0f;
    }
    if (keys[SDL_SCANCODE_LEFT])
    {
        if (pGame->player->m_dx > -200.0f)
            pGame->player->m_dx -= 20.0f;
    }if (keys[SDL_SCANCODE_DOWN])
    {
        if (pGame->player->m_dy < 200.0f)
            pGame->player->m_dy += 20.0f;
    }
    if (keys[SDL_SCANCODE_UP])
    {
        if (pGame->player->m_dy > -200.0f)
            pGame->player->m_dy -= 20.0f;
    }
}

void updateGame (Game* pGame)
{
    static int thisTime = 0;
    static int lastTime = 0;
    static float deltaTime = 0.0f;
    
    thisTime = SDL_GetTicks();
    deltaTime = (float) (thisTime - lastTime) / 1000;
    lastTime = thisTime;
    
    pGame->player->m_x += pGame->player->m_dx * deltaTime;
    pGame->player->m_y += pGame->player->m_dy * deltaTime;
    
    if (pGame->player->m_dx > 0.0f)
    {
        pGame->player->m_dx -= 5.0f;
    }
    if (pGame->player->m_dx < 0.0f)
    {
        pGame->player->m_dx += 5.0f;
    }
    
    if (pGame->player->m_dy > 0.0f)
    {
        pGame->player->m_dy -= 5.0f;
    }
    if (pGame->player->m_dy < 0.0f)
    {
        pGame->player->m_dy += 5.0f;
    }
    
    printf("%d\n", (int) (1 / deltaTime));
}

void renderGame (Game* pGame)
{
    SDL_SetRenderDrawColor(pGame->m_renderer, 121, 213, 251, 255);
    SDL_RenderClear(pGame->m_renderer);
    
    //desenhando player
    SDL_SetRenderDrawColor(pGame->m_renderer, 255, 255, 255, 255);
    SDL_Rect Player = {pGame->player->m_x, pGame->player->m_y, pGame->player->m_width, pGame->player->m_height};
    SDL_RenderFillRect(pGame->m_renderer, &Player);
    
    //Desenhando chao
    SDL_SetRenderDrawColor(pGame->m_renderer, 0, 0, 0, 255);
    SDL_Rect ground = {0, 440, 680, 40};
    SDL_RenderFillRect(pGame->m_renderer, &ground);
    
    if (checkBoxCollision(&Player, &ground))
        printf("Colidindo\n");
    
    SDL_RenderPresent(pGame->m_renderer);
}

Boolean checkBoxCollision (SDL_Rect* pRect1, SDL_Rect* pRect2)
{
    return false;
}