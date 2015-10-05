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

typedef struct player
{
    float m_x, m_y;
    float m_width, m_height;
    float m_dx, m_dy;
    
} Player;

Player* createPlayer (float px, float py);
void destroyPlayer (Player* pPlayer);

#endif /* player_h */
