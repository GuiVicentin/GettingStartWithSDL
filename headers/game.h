//
//  game.h
//  FirstGame
//
//  Created by Guilherme Vicentin on 04/10/15.
//  Copyright © 2015 Guilherme Vicentin. All rights reserved.
//

#ifndef game_h
#define game_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>

#include "globals.h"
#include "player.h"

typedef struct game
{
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    
    Boolean isRunning;
    
    Player* player;
    
} Game;

Game* initGame (void);
void closeGame (Game* pGame);

void loadGameContext(Game* pGame);

void handleEvents (Game* pGame);
void updateGame (Game* pGame);
void renderGame (Game* pGame);

Boolean checkBoxCollision (SDL_Rect* pRect1, SDL_Rect* pRect2);


#endif /* game_h */
