//
//  main.m
//  FirstGame
//
//  Created by Guilherme Vicentin on 23/09/15.
//  Copyright © 2015 Guilherme Vicentin. All rights reserved.
//

#include <stdio.h>

#include "game.h"
#include "globals.h"

int main (int argc, char *argv[])
{
    Game* game = initGame();
    
    while (game->isRunning)
    {
        handleEvents(game);
        updateGame(game);
        renderGame(game);
    }
    
    closeGame(game);
    return 0;
}