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
    
    new_player->m_x = px;
    new_player->m_y = py;
    new_player->m_width = 50.0f;
    new_player->m_height = 100.0f;
    new_player->m_dx = 0.0f;
    new_player->m_dy = 0.0f;
    
    return new_player;
}

void destroyPlayer (Player* pPlayer)
{
    free(pPlayer);
    pPlayer = NULL;
}
