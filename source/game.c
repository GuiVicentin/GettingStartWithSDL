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
    free(pGame->ground);
    free(pGame);
}

void loadGameContext (Game* pGame)
{
    //inicializando player
    pGame->player = createPlayer(300.0f, 220.0f);
    
    //inicializando chao
    pGame->ground = createRectangle(0, 440, 640, 40);
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
            
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_UP:
                        pGame->player->m_rect.y -= 150.0f;
                        break;
                        
                    default:
                        break;
                }
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
    
    pGame->player->m_rect.x += pGame->player->m_dx * deltaTime;
    pGame->player->m_rect.y += pGame->player->m_dy * deltaTime;
    
    if (pGame->player->m_dx > 0.0f)
    {
        pGame->player->m_dx -= 5.0f;
    }
    if (pGame->player->m_dx < 0.0f)
    {
        pGame->player->m_dx += 5.0f;
    }
    
    if (!pGame->player->isOnGround)
    {
        pGame->player->m_dy += 5.0f;
    }
    else
    {
       pGame->player->m_dy = 0;
    }
    
    //colisao player e chao
    if (checkBoxCollision(&pGame->player->m_rect, pGame->ground))
    {
        pGame->player->isOnGround = true;
    }
    else
    {
        pGame->player->isOnGround = false;
    }
}

void renderGame (Game* pGame)
{
    SDL_SetRenderDrawColor(pGame->m_renderer, 121, 213, 251, 255);
    SDL_RenderClear(pGame->m_renderer);
    
    //desenhando player
    SDL_SetRenderDrawColor(pGame->m_renderer, 255, 255, 255, 255);
    SDL_Rect Player = {pGame->player->m_rect.x, pGame->player->m_rect.y, pGame->player->m_rect.w, pGame->player->m_rect.h};
    SDL_RenderFillRect(pGame->m_renderer, &Player);
    
    //Desenhando chao
    SDL_SetRenderDrawColor(pGame->m_renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(pGame->m_renderer, pGame->ground);
    
    SDL_RenderPresent(pGame->m_renderer);
}

Boolean checkBoxCollision (SDL_Rect* pRect1, SDL_Rect* pRect2)
{
    if (pRect2->x > pRect1->x + pRect1->w)
        return false;
        
    if (pRect2->x + pRect2->w < pRect1->x)
        return false;
    
    if (pRect2->y > pRect1->y + pRect1->h)
        return false;
    
    if (pRect2->y + pRect2->h < pRect1->y)
        return false;
    
    return true;
}