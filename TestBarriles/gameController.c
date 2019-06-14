#include <stdio.h>
#include "gameWindow.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

/**
 *  Metodo que inicia las vidas asignadas a Mario.
 * @param game
 */
void initLives(GameState *game) {
    char vida[128] = "";
    sprintf(vida, "x %d", (int) game->mario.lives);
    SDL_Color white = {255, 255, 255, 255};
    SDL_Surface *tmp = TTF_RenderText_Blended(game->font, vida, white);
    game->labelW = tmp->w;
    game->labelH = tmp->h;
    game->label = SDL_CreateTextureFromSurface(game->renderer, tmp);
    SDL_FreeSurface(tmp);
}

/**
 * Metodo que dibuja las vidas de Mario.
 * @param game
 */
void drawLives(GameState *game) {
    SDL_SetRenderDrawColor(game->renderer, 25, 25, 20, 20);
    SDL_RenderClear(game->renderer);
    SDL_Rect rect = {220, 216, 30, 30};
    SDL_RenderCopyEx(game->renderer, game->marioTexture[0], NULL, &rect, 0, NULL, (game->mario.izq == 0));
    SDL_SetRenderDrawColor(game->renderer, 255, 255, 255, 255);
    SDL_Rect textRect = {320, 240 - game->labelH / 2, game->labelW, game->labelH};
    SDL_RenderCopy(game->renderer, game->label, NULL, &textRect);
}

/**
 *
 * @param game
 */
void sutdownLives(GameState *game) {
    SDL_DestroyTexture(game->label);
    game->label = NULL;
}

/**
 *
 * @param game
 */
void initGameOver(GameState *game) {
    //Create label textures for status screen
    SDL_Color white = {255, 255, 255, 255};

    SDL_Surface *tmp = TTF_RenderText_Blended(game->font, "GAME OVER!", white);
    game->labelW = tmp->w;
    game->labelH = tmp->h;
    game->label = SDL_CreateTextureFromSurface(game->renderer, tmp);
    SDL_FreeSurface(tmp);
}

/**
 *
 * @param game
 */
void drawGameOver(GameState *game) {
    SDL_Renderer *renderer = game->renderer;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_Rect textRect = {320 - game->labelW / 2, 240 - game->labelH / 2, game->labelW, game->labelH};
    SDL_RenderCopy(renderer, game->label, NULL, &textRect);
}

/**
 *
 * @param game
 */
void shutdownLives(GameState *game) {
    SDL_DestroyTexture(game->label);
    game->label = NULL;
}

/**
 *
 * @param game
 */
void initGameVictory(GameState *game) {
    SDL_Color white = {255, 255, 255, 255};
    SDL_Surface *tmp = TTF_RenderText_Blended(game->font, "WIN!", white);
    game->labelW = tmp->w;
    game->labelH = tmp->h;
    game->label = SDL_CreateTextureFromSurface(game->renderer, tmp);
    SDL_FreeSurface(tmp);
}

/**
 *
 * @param game
 */
void drawGameVictory(GameState *game) {
    SDL_Renderer *renderer = game->renderer;
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect textRect = {320 - game->labelW / 2, 240 - game->labelH / 2, game->labelW, game->labelH};
    SDL_RenderCopy(renderer, game->label, NULL, &textRect);
}

/**
 *
 * @param game
 */
void shutDownGameVictory(GameState *game) {
    SDL_DestroyTexture(game->label);
    game->label = NULL;
}
