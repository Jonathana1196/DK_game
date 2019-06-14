#ifndef TESTBARRILES_GAMEWINDOW_H
#define TESTBARRILES_GAMEWINDOW_H


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#define STATUS_STATE_LIVES 0
#define STATUS_STATE_GAME 1
#define STATUS_STATE_GAMEOVER 2
#define STATUS_STATE_WIN 3
#define NUM_PISO 135
#define NUM_BARRILES 15
#define NUM_BARRIL_BAJA 15
#define NUM_ESCALERAS 12
#define NUM_LLAMAS 50

/**
 * Estructura personalizada para Donkey Kong.
 */
typedef struct {
    int x, y;
} Donkey;

/**
 * Estructura personalizada para Mario.
 */
typedef struct {
    float x, y, dx, dy;
    int marioSuelo, deadMario, lives, up, down, animTexture, izq, slowingDown;
} Mario;

/**
 * Estructura personalizada para la Princesa.
 */
typedef struct {
    int x, y, dx, paulineTexture;
} Princesa;

/**
 * Estructura personalizada para el piso.
 */
typedef struct {
    int x, y, w, h;
} Piso;

/**
 * Estructura personalizada para las escaleras.
 */
typedef struct {
    int x, y;
} Escalera;

/**
 * Estructura personalizada para los barriles normales.
 */
typedef struct {
    int x, y;
    float dx, dy;
} Barriles;

/**
 * Estructura personalizada para los barriles que caen.
 */
typedef struct {
    int x, y, barrilBajaTexture;
    float dy;
} BarrilBaja;

/**
 * Estructura personalizada para las llamas.
 */
typedef struct {
    int x, y, llamaTexture, gravedad, check;
    float dx, dy;
} Llama;

/**
 * Estructura personalizada para el tanque.
 */
typedef struct {
    int x, y, tanqueTexture;
} TanqueLlama;


/**
 * Estructura para los estados de juego donde se pasan las estructuras que se crean durante el juego.
 */
typedef struct {
    /// Objetos
    Mario mario;
    Donkey donkey;
    Princesa princesa;
    Llama llamas[NUM_LLAMAS];
    TanqueLlama tanqueLlama;
    Piso piso[NUM_PISO];
    Barriles barriles[NUM_BARRILES];
    BarrilBaja barrilBaja[NUM_BARRIL_BAJA];
    Escalera escaleras[NUM_ESCALERAS];

    /// Imagenes
    SDL_Texture *barrilBajaTexture[2];
    SDL_Texture *llamaTexture[5];
    SDL_Texture *paulineTexture[5];
    SDL_Texture *barril;
    SDL_Texture *tanqueTexture[2];
    SDL_Texture *escaleraTexture;
    SDL_Texture *donkeyKongTexture[2];
    SDL_Texture *marioTexture[2];
    SDL_Texture *deadMario;
    SDL_Texture *ground;
    SDL_Texture *label;
    int labelW, labelH;

    /// Fonts
    TTF_Font *font;

    /// tiempo
    int time, deathCountdown;
    int statusState;

    /// Renderer
    SDL_Renderer *renderer;
} GameState;


#endif //TESTBARRILES_GAMEWINDOW_H
