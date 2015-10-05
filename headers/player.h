//
//  player.h
//  FirstGame
//
//  Created by Guilherme Vicentin on 04/10/15.
//  Copyright © 2015 Guilherme Vicentin. All rights reserved.
//

#ifndef player_h
#define player_h

#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>

#include "globals.h"

typedef struct player
{
    SDL_Rect m_rect;
    float m_dx, m_dy;
    
    Boolean isOnGround;
    
} Player;

Player* createPlayer (float px, float py);
void destroyPlayer (Player* pPlayer);

SDL_Rect* createRectangle(int px, int py, int pw, int ph);

#endif /* player_h */
