//
//  player.c
//  FirstGame
//
//  Created by Guilherme Vicentin on 04/10/15.
//  Copyright © 2015 Guilherme Vicentin. All rights reserved.
//

#include "player.h"

Player* createPlayer (float px, float py)
{
    Player* new_player = (Player*) malloc(sizeof(Player));
    
    new_player->m_rect.x = px;
    new_player->m_rect.y = py;
    new_player->m_rect.w = 50.0f;
    new_player->m_rect.h = 100.0f;
    new_player->m_dx = 0.0f;
    new_player->m_dy = 0.0f;
    new_player->isOnGround = false;
    
    return new_player;
}

void destroyPlayer (Player* pPlayer)
{
    free(pPlayer);
    pPlayer = NULL;
}

SDL_Rect* createRectangle (int px, int py, int pw, int ph)
{
    SDL_Rect* new_rect = (SDL_Rect*)malloc(sizeof(SDL_Rect));
    
    new_rect->x = px;
    new_rect->y = py;
    new_rect->w = pw;
    new_rect->h = ph;
    
    return new_rect;
}
