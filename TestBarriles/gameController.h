//
// Created by jonathan on 13/06/19.
//

#ifndef TESTBARRILES_GAMECONTROLLER_H
#define TESTBARRILES_GAMECONTROLLER_H


#include "gameWindow.h"

void initLives(GameState *game);

void drawLives(GameState *game);

void sutdownLives(GameState *game);

void initGameOver(GameState *game);

void drawGameOver(GameState *game);

void shutdownLives(GameState *game);

void initGameVictory(GameState *game);

void drawGameVictory(GameState *game);

void shutDownGameVictory(GameState *game);


#endif //TESTBARRILES_GAMECONTROLLER_H
