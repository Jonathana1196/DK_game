//GUI
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <time.h>
#include "gameWindow.h"
#include "gameController.h"
#include <stdlib.h>

#define GRAVEDAD 0.80f

/**
 * Metodo que carga toda la base del juego.
 * @param game Recibe un gameState
 */
void loadGame(GameState *game) {
    SDL_Surface *surface = NULL;

    ///Carga la imagen de Donkey Kong y crea texturas con el render a partir de ella.
    surface = IMG_Load("../Images/staticDonkey.png");
    if (surface == NULL) {
        printf("Cannot find DonkeyKongTexture image!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->donkeyKongTexture[0] = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    /// Carga la imagen de Mario cuando esta muerto y crea texturas con el render a partir de ella.
    surface = IMG_Load("../Images/deadMario.png");
    if (surface == NULL) {
        printf("Cannot find Mario deadMario image!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->deadMario = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    /// Carga la imagen de Mario detenido y crea texturas con el render a partir de ella
    surface = IMG_Load("../Images/marioStaticRight.png");
    if (surface == NULL) {
        printf("Cannot find Mario image!\n\n");
        SDL_Quit();
        exit(1);
    }

    game->marioTexture[0] = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    /// Carga la imagen de Mario caminando a la derecha y crea texturas con el render a partir de ella
    surface = IMG_Load("../Images/marioRight1.png");
    if (surface == NULL) {
        printf("Cannot find Mario image!\n\n");
        SDL_Quit();
        exit(1);
    }

    game->marioTexture[1] = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    /// Carga la imagen del barril 1 y crea texturas con el render a partir de ella.
    surface = IMG_Load("../Images/barril3.png");
    game->barril = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    /// Carga la imagen del barril 1 y crea texturas con el render a partir de ella.
    surface = IMG_Load("../Images/tanqueLlama1.png");
    game->tanqueTexture[0] = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    /// Carga la imagen de Pauline1 1 y crea texturas con el render a partir de ella.
    surface = IMG_Load("../Images/paulineRight1.png");
    game->paulineTexture[0] = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);
    /// Carga la imagen de Pauline1 2 y crea texturas con el render a partir de ella.
    surface = IMG_Load("../Images/paulineRight2.png");
    game->paulineTexture[1] = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);
    /// Carga la imagen de Pauline1 3 y crea texturas con el render a partir de ella.
    surface = IMG_Load("../Images/paulineLeft2.png");
    game->paulineTexture[2] = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);
    /// Carga la imagen de Pauline1 4 y crea texturas con el render a partir de ella.
    surface = IMG_Load("../Images/paulineLeft1.png");
    game->paulineTexture[3] = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);


    /// Carga la imagen de la llama 1 y crea texturas con el render a partir de ella.
    surface = IMG_Load("../Images/llama1.png");
    game->llamaTexture[0] = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);
    /// Carga la imagen de llama 2 y crea texturas con el render a partir de ella.
    surface = IMG_Load("../Images/llama2.png");
    game->llamaTexture[1] = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);
    /// Carga la imagen de llama 3 y crea texturas con el render a partir de ella.
    surface = IMG_Load("../Images/llama3.png");
    game->llamaTexture[2] = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);
    /// Carga la imagen de llama 4 y crea texturas con el render a partir de ella.
    surface = IMG_Load("../Images/llama4.png");
    game->llamaTexture[3] = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);


    /// Carga la imagen del barril 7 y crea texturas con el render a partir de ella.
    surface = IMG_Load("../Images/barril7.png");
    game->barrilBajaTexture[0] = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);
    /// Carga la imagen del barril 8 y crea texturas con el render a partir de ella.
    surface = IMG_Load("../Images/barril8.png");
    game->barrilBajaTexture[1] = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);


    /// Carga la imagen del barril 1 y crea texturas con el render a partir de ella.
    surface = IMG_Load("../Images/tanqueLlama2.png");
    game->tanqueTexture[1] = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);



    /// Carga la imagen del Suelo y crea texturas con el render a partir de ella.
    surface = IMG_Load("../Images/piso.png");
    game->ground = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    /// Carga las letras del font.
    game->font = TTF_OpenFont("../fonts/Crazy-Pixel.ttf", 50);
    if (!game->font) {
        printf("Cannot find font");
        SDL_Quit();
        exit(1);
    }

    /// Carga la escalera.
    surface = IMG_Load("../Images/escalera.png");
    game->escaleraTexture = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);



    /// Posiciones de las imagenes, Inicia Mario
    game->mario.x = 35;
    game->mario.y = 625;
    game->mario.dx = 0;
    game->mario.dy = 0;
    game->mario.marioSuelo = 0;
    game->mario.animTexture = 0;
    game->mario.izq = 1;
    game->mario.slowingDown = 0;
    game->mario.lives = 1;
    game->mario.deadMario = 0;
    game->mario.up = 0;
    game->mario.down = 0;

    /// Inicia el estado del juego
    game->statusState = STATUS_STATE_LIVES;

    /// Inicia el estado de la vidas
    initLives(game);
    game->deathCountdown = -1;


//    /// Inicia label para escribir en pantalla
//    game->label = NULL;

    /// Inicia el tiempo
    game->time = 0;

    /// Inicia a Donkey Kong
    game->donkey.x = 20;
    game->donkey.y = 80;

    /// Inicia el suelo
    /// Piso #1.
    for (int i = 0; i < 25; i++) {
        game->piso[i].w = 25;
        game->piso[i].h = 20;
        game->piso[i].x = 50 + (i * 25);
        game->piso[i].y = 660;
    }
    /// Piso #2.
    for (int i = 25; i < 45; i++) {
        game->piso[i].w = 25;
        game->piso[i].h = 20;
        game->piso[i].x = (i - 25) * 25;
        game->piso[i].y = 550 + (i - 25);
    }
    /// Piso #3.
    for (int i = 45; i < 65; i++) {
        game->piso[i].w = 25;
        game->piso[i].h = 20;
        game->piso[i].x = 600 - ((i - 45) * 25);
        game->piso[i].y = 450 + (i - 45);
    }
    /// Piso #4.
    for (int i = 65; i < 85; i++) {
        game->piso[i].w = 25;
        game->piso[i].h = 20;
        game->piso[i].x = (i - 65) * 25;
        game->piso[i].y = 340 + (i - 45);
    }
    /// Piso #5.
    for (int i = 85; i < 105; i++) {
        game->piso[i].w = 25;
        game->piso[i].h = 20;
        game->piso[i].x = 600 - ((i - 85) * 25);
        game->piso[i].y = 250 + (i - 85);
    }
    /// Piso #6.
    for (int i = 105; i < 127; i++) {
        game->piso[i].w = 25;
        game->piso[i].h = 20;
        game->piso[i].x = (i - 105) * 25;
        game->piso[i].y = 150 + (i - 105);
    }
    /// Piso #7.
    for (int i = 127; i < 135; i++) {
        game->piso[i].w = 25;
        game->piso[i].h = 20;
        game->piso[i].x = 115 + (i - 127) * 25;
        game->piso[i].y = 75;
    }
    /// Inicia las escaleras de la primera parte.
    /// Temporal se encarga de dibujar diversos bloques de escaleras.
    int temporal = 610;
    for (int i = 0; i < 4; i += 2) {
        game->escaleras[i].x = 500;
        game->escaleras[i].y = temporal;
        game->escaleras[i + 1].x = 500;
        game->escaleras[i + 1].y = temporal - 50;
        temporal = 410;
    }
    /// Inicia las escaleras de la segunda parte.
    temporal = 510;
    for (int i = 4; i < 8; i += 2) {
        game->escaleras[i].x = 95;
        game->escaleras[i].y = temporal;
        game->escaleras[i + 1].x = 95;
        game->escaleras[i + 1].y = temporal - 40;
        temporal = 310;
    }
    /// Inicia las escaleras de la tercera parte.
    for (int i = 8; i < 10; i += 2) {
        game->escaleras[i].x = 550;
        game->escaleras[i].y = 200;
        game->escaleras[i + 1].x = 550;
        game->escaleras[i + 1].y = 200 - 40;

    }
    /// Inicia las escaleras de la cuarta parte.
    for (int i = 10; i < 12; i += 2) {
        game->escaleras[i].x = 315;
        game->escaleras[i].y = 115;
        game->escaleras[i + 1].x = 315;
        game->escaleras[i + 1].y = 115 - 40;

    }
    /// Inicia el Tanque de fuego.
    game->tanqueLlama.x = 50;
    game->tanqueLlama.y = 620;
    game->tanqueLlama.tanqueTexture = 0;

    /// Inicia la Princesa.
    game->princesa.x = 120;
    game->princesa.y = 43;
    game->princesa.dx = 1;
    game->princesa.paulineTexture = 0;

}


/**
 * Metodo que nos permite realizar animaciones con las imagenes.
 * @param newBarril
 * @param newLlama
 * @param newBarrilBaja
 * @param game
 */
void process(int newBarril, int newLlama, int newBarrilBaja, GameState *game) {
    /// Agrega tiempo, para hacer las animaciones por frames.
    game->time++;

    if (game->statusState == STATUS_STATE_LIVES) {
        /// Muestra la ventana de vidas antes de empezar el juego.
        if (game->time > 120) {
            shutdownLives(game);
            game->statusState = STATUS_STATE_GAME;
        }
    }

        /// Si el estado de juego es Game Over.
    else if (game->statusState == STATUS_STATE_GAMEOVER) {
        if (game->time > 190) {
            SDL_Quit();
            exit(0);
        }
    }

        /// Si se esta jugando entonces...
    else if (game->statusState == STATUS_STATE_GAME) {
        /// Animación del tanque de fuego.
        if (game->time % 40 == 0) {
            if (game->tanqueLlama.tanqueTexture == 0) {
                game->tanqueLlama.tanqueTexture = 1;

            } else {
                game->tanqueLlama.tanqueTexture = 0;
            }
        }

        /// Animación de la Princesa game->time % 5000 == 0 && game->time % 5000 == 0 &&
        if (game->princesa.dx > 0) {
            if (game->princesa.paulineTexture == 0 || game->princesa.paulineTexture == 3) {
                game->princesa.paulineTexture = 1;

            } else {
                game->princesa.paulineTexture = 0;
            }
        }
        if (game->princesa.dx < 0) {
            if (game->princesa.paulineTexture == 0 || game->princesa.paulineTexture == 3) {
                game->princesa.paulineTexture = 2;

            } else {
                game->princesa.paulineTexture = 3;
            }
        }

        /// Animación de las llamas.
        for (int i = 0; i < newLlama; i++) {
            if (game->time % 40 == 0 && game->llamas[i].dx < 0) {
                if (game->llamas[i].llamaTexture == 0 || game->llamas[i].llamaTexture == 3) {
                    game->llamas[i].llamaTexture = 1;

                } else {
                    game->llamas[i].llamaTexture = 0;
                }
            }
            if (game->time % 40 == 0 && game->llamas[i].dx > 0) {
                if (game->llamas[i].llamaTexture == 0 || game->llamas[i].llamaTexture == 3) {
                    game->llamas[i].llamaTexture = 2;

                } else {
                    game->llamas[i].llamaTexture = 3;
                }
            }
        }

        /// Animación de los Barriles que bajan.
        for (int i = 0; i < newBarrilBaja; i++) {
            if (game->time % 40 == 0) {
                if (game->barrilBaja[i].barrilBajaTexture == 0) {
                    game->barrilBaja[i].barrilBajaTexture = 1;

                } else {
                    game->barrilBaja[i].barrilBajaTexture = 0;
                }
            }
        }

        /// Animación de Mario muerto.
        if (!game->mario.deadMario) {
            /// Movimiento de Mario
            Mario *mario = &game->mario;
            mario->x += mario->dx;
            mario->y += mario->dy;

            /// Cambia el sprite segun el movimiento.
            if (mario->dx != 0 && mario->marioSuelo && !mario->slowingDown) {
                /// Si han pasado 8 frames por segundo.
                if (game->time % 40 == 0) {
                    if (mario->animTexture == 0) {
                        mario->animTexture = 1;

                    } else {
                        mario->animTexture = 0;

                    }
                }
            }

            for (int i = 0; i < newBarril; i++) {
                game->barriles[i].dy += GRAVEDAD;
            }
            for (int i = 0; i < newLlama; i++) {
                if (game->llamas[i].gravedad == 1) {
                    game->llamas[i].dy += GRAVEDAD;
                }

            }


            mario->dy += GRAVEDAD;


        }
        /// Si Mario muere y el contador de muertes es inferior a 0 entonces...
        if (game->mario.deadMario && game->deathCountdown < 0) {
            game->deathCountdown = 120;
        }
        if (game->deathCountdown >= 0) {
            game->deathCountdown--;
            if (game->deathCountdown < 0) {
                game->mario.lives--;

                if (game->mario.lives >= 0) {
                    initLives(game);
                    game->statusState = STATUS_STATE_LIVES;
                    game->time = 0;

                    /// Reset a las variables de Mario.
                    game->mario.deadMario = 0;
                    game->mario.x = 100;
                    game->mario.y = 240 - 40;
                    game->mario.dx = 0;
                    game->mario.dy = 0;
                    game->mario.marioSuelo = 0;
                } else {
                    initGameOver(game);
                    game->statusState = STATUS_STATE_GAMEOVER;
                    game->time = 0;
                }
            }
        }
    }

}

/**
 * Metodo que nos permite saber si dos imagenes estan compartiendo el mismo espacio de juego.
 * @param x1
 * @param y1
 * @param x2
 * @param y2
 * @param wt1
 * @param ht1
 * @param wt2
 * @param ht2
 * @return
 */
int collide2d(float x1, float y1, float x2, float y2, float wt1, float ht1, float wt2, float ht2) {
    return (!((x1 > (x2 + wt2)) || (x2 > (x1 + wt1)) || (y1 > (y2 + ht2)) || (y2 > (y1 + ht1))));
}

/**
 * Metodo que tedecta las colisiones.
 * @param game
 */
void collisionDetect(GameState *game) {
    /// Verifica choques con barriles
    int i;
    for (int i = 0; i < NUM_BARRILES; i++) {
        if (collide2d(game->mario.x, game->mario.y, game->barriles[i].x, game->barriles[i].y, 30, 30, 20, 20)) {
            game->mario.deadMario = 1;
        }
    }
    for (i = 0; i < NUM_BARRIL_BAJA; i++) {
        if (collide2d(game->mario.x, game->mario.y, game->barrilBaja[i].x, game->barrilBaja[i].y, 30, 30, 20, 20)) {
            game->mario.deadMario = 1;
        }
    }

    for (int i = 0; i < NUM_LLAMAS; i++) {
        for (int j = 0; j < NUM_ESCALERAS; j++) {
            if (collide2d(game->llamas[i].x, game->llamas[i].y, game->escaleras[j].x + 10, game->escaleras[j].y, 20, 20,
                          1, 40)) {
                game->llamas[i].gravedad = 0;
                game->llamas[i].dx = 0;
                if (game->time % 2 == 0) {
                    game->llamas[i].y += -1;
                    if (!(collide2d(game->llamas[i].x, game->llamas[i].y, game->escaleras[j].x + 10,
                                    game->escaleras[j].y, 20, 20, 1, 40))) {
                        if (game->llamas[i].check > 0) {
                            game->llamas[i].dx = -1;
                            game->llamas[i].check = -20;
                            game->llamas[i].gravedad = 1;

                        } else {
                            game->llamas[i].dx = 1;
                            game->llamas[i].check = 20;
                            game->llamas[i].gravedad = 1;
                        }


                    }
                }
            }
        }
    }

    /// Verifica choque de Mario con la Princesa.
    if (collide2d(game->mario.x, game->mario.y, game->princesa.x, game->princesa.y, 30, 30, 30, 30)) {
        initGameVictory(game);
        game->statusState = STATUS_STATE_WIN;
    }

    /// Verifica que Mario no se salga por la derecha.
    if (game->mario.x >= 600) {
        game->mario.x = 560;
    }

    /// Verifica que Mario no se salga por la izquierda.
    if (game->mario.x <= 0) {
        game->mario.x = 40;
    }

    /// Verifica la colision con el suelo.
    for (int i = 0; i < 135; i++) {
        float mw = 25, mh = 25;
        float mx = game->mario.x, my = game->mario.y;
        float bx = game->piso[i].x, by = game->piso[i].y, bw = game->piso[i].w, bh = game->piso[i].h;

        if (mx + mw / 2 > bx && mx + mw / 2 < bx + bw) {
            /// Nos estamos golpeando la cabeza (Mario)?
            if (my < by + bh && my > by && game->mario.dy < 0) {
                /// Corrige y
                game->mario.y = by + bh;
                my = by + bh;

                /// Si nos golpeamos la cabeza detiene la velocidad del salto.
                game->mario.dy = 0;
                game->mario.marioSuelo = 1;
            }
        }
        if (mx + mw > bx && mx < bx + bw) {
            /// Estamos cayendo en el suelo
            if (my + mh > by && my < by && game->mario.dy > 0) {
                /// Corrige y
                game->mario.y = by - mh;
                my = by - mh;

                /// Si cae en el suelo, detiene la velocidad del salto.
                game->mario.dy = 0;
                game->mario.marioSuelo = 1;
            }
        }

        if (my + mh > by && my < by + bh) {
            /// Choca con los costados del suelo (izquierdo).
            if (mx < bx + bw && mx + mw > bx + bw && game->mario.dx < 0) {
                /// Corrige x
                game->mario.x = bx + bw;
                mx = bx + bw;

                game->mario.dx = 0;
            }
                /// Choca con costados del suelo (derecho).
            else if (mx + mw > bx && mx < bx && game->mario.dx > 0) {
                /// Corrige x
                game->mario.x = bx - mw;
                mx = bx - mw;

                game->mario.dx = 0;
            }
        }
    }
}

/**
 * Metodo que verifica los posibles eventos que pueden pasar en el juego.
 * @param window
 * @param game
 * @param newBarril
 * @param newLlamas
 * @param newBarrilBaja
 * @return
 */
int processEvents(SDL_Window *window, GameState *game, int *newBarril, int *newLlamas, int *newBarrilBaja) {
    ///Se llama a una funcion de SDL que maneja los distintos eventos.
    SDL_Event event;
    int done = 0;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            /// Caso en que se cierre la ventana.
            case SDL_WINDOWEVENT_CLOSE: {
                if (window) {
                    SDL_DestroyWindow(window);
                    window = NULL;
                    done = 1;
                }
            }
                break;
                /// Caso en que se presiona la flcha de abajo.
            case SDL_KEYDOWN: {
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        done = 1;
                        break;
                        /// Caso en que se apreta la flecha de arriba.
                    case SDLK_UP:

                        if (game->mario.marioSuelo) {
                            game->mario.dy = -6;
                            game->mario.marioSuelo = 0;


                        }

                        break;
                }
            }
                break;
                /// Caso en que se cierra el juego.
            case SDL_QUIT:
                done = 1;
                break;
        }
    }

    /// Esto permite que Mario salte mas, al dejar la flecha de arriba presionada.
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_UP]) {
        game->mario.dy -= 0.2f;
        /// Verifica colision con la escalera.
        for (int i = 0; i < 12; i++) {

            if ((collide2d(game->mario.x, game->mario.y, game->escaleras[i].x, game->escaleras[i].y, 30, 30, 30, 40))) {
                if (!(collide2d(game->mario.x, game->mario.y, game->escaleras[i].x, game->escaleras[i].y, 30, 30, 30,
                                40))) {
                    if (state[SDL_SCANCODE_UP]) {
                        game->mario.dy += GRAVEDAD;
                    }

                }
                if (!(state[SDL_SCANCODE_UP])) {
                    game->mario.dy = 0;
                }

                if (state[SDL_SCANCODE_UP]) {
                    game->mario.dy -= 0.22;
                }


            }

        }
    }

    /// Tecla para lanzar el barril de tipo 1.
    if (state[SDL_SCANCODE_B]) {

        *newBarril = *newBarril + 1;
    }
    /// Tecla para lanzar barril de tipo 2.
    if (state[SDL_SCANCODE_V]) {

        *newBarrilBaja = *newBarrilBaja + 1;
    }

    if (!(state[SDL_SCANCODE_UP])) {
        game->mario.up = 0;
    }

    /// Tecla para lanzar llamas.
    if (state[SDL_SCANCODE_F]) {

        *newLlamas = *newLlamas + 1;
    }

    if (!(state[SDL_SCANCODE_UP])) {
        game->mario.up = 0;
    }

    /// Caminar a la izquierda.
    if (state[SDL_SCANCODE_LEFT]) {
        game->mario.dx -= 0.1;
        if (game->mario.dx < -1) {
            game->mario.dx = -1;
        }
        game->mario.izq = 0;
        game->mario.slowingDown = 0;
    }
        /// Caminar a la derecha.
    else if (state[SDL_SCANCODE_RIGHT]) {
        game->mario.dx += 0.1;
        if (game->mario.dx > 1) {
            game->mario.dx = 1;
        }
        game->mario.izq = 1;
        game->mario.slowingDown = 0;
    }
        /// Mario no camina, se queda estatico.
    else {
        game->mario.animTexture = 0;
        game->mario.dx *= 0.8f;
        game->mario.slowingDown = 1;
        if (fabsf(game->mario.dx) < 0.1f) {
            game->mario.dx = 0;
        }
    }

    return done;
}

/**
 * Metodo para dibujar en pantalla lo solicitado.
 * @param renderer
 * @param game
 * @param newBarril
 * @param newLlama
 * @param newBarrilBaja
 */
void doRender(SDL_Renderer *renderer, GameState *game, int newBarril, int newLlama, int newBarrilBaja) {
    int i;
    /// Si aun se tienen vidas disponibles.
    if (game->statusState == STATUS_STATE_LIVES) {
        drawLives(game);
    }
        /// Si se ha llegado a un GameOver.
    else if (game->statusState == STATUS_STATE_GAMEOVER) {
        drawGameOver(game);
    }
        /// Si se ha llegado a un Win.
    else if (game->statusState == STATUS_STATE_WIN) {
        drawGameVictory(game);
    }
        /// Si se esta jugando.
    else if (game->statusState == STATUS_STATE_GAME) {
        /// Establece al color negro como color de dibujo.
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

        /// Pinta la ventana de color negro.
        SDL_RenderClear(renderer);

        /// Establece al blanco como color de dibujo.
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        /// Dibuja las escaleras.
        for (i = 0; i < 12; i++) {
            SDL_Rect escaleraRect = {game->escaleras[i].x, game->escaleras[i].y, 30, 50};
            SDL_RenderCopy(renderer, game->escaleraTexture, NULL, &escaleraRect);
        }
        /// Dibuja los tanques.
        SDL_Rect estanonRect = {game->tanqueLlama.x, game->tanqueLlama.y, 40, 40};
        SDL_RenderCopy(renderer, game->tanqueTexture[game->tanqueLlama.tanqueTexture], NULL, &estanonRect);

        /// Dibuja el suelo.
        for (i = 0; i < 135; i++) {
            SDL_Rect sueloRect = {game->piso[i].x, game->piso[i].y, game->piso[i].w, game->piso[i].h};
            SDL_RenderCopy(renderer, game->ground, NULL, &sueloRect);
        }

        /// Dibuja a Donkey Kong.
        SDL_Rect DKRect = {game->donkey.x, game->donkey.y, 70, 70};
        SDL_RenderCopy(renderer, game->donkeyKongTexture[0], NULL, &DKRect);

        /// Dibuja a la Princesa.
        SDL_Rect paulineRect = {game->princesa.x, game->princesa.y, 30, 30};
        SDL_RenderCopy(renderer, game->paulineTexture[game->princesa.paulineTexture], NULL, &paulineRect);

        /// Dibuja a los barriles.
        for (i = 0; i < newBarril; i++) {
            SDL_Rect barrilRect = {game->barriles[i].x, game->barriles[i].y, 20, 20};
            SDL_RenderCopy(renderer, game->barril, NULL, &barrilRect);
        }

        /// Dibuja las llamas.
        for (i = 0; i < newLlama; i++) {
            SDL_Rect llamaRect = {game->llamas[i].x, game->llamas[i].y, 20, 20};
            SDL_RenderCopy(renderer, game->llamaTexture[game->llamas[i].llamaTexture], NULL, &llamaRect);
        }

        /// Dibuja los barriles de tipo 2..
        for (i = 0; i < newBarrilBaja; i++) {
            SDL_Rect BarrilBajaRect = {game->barrilBaja[i].x, game->barrilBaja[i].y, 20, 20};
            SDL_RenderCopy(renderer, game->barrilBajaTexture[game->barrilBaja[i].barrilBajaTexture], NULL,
                           &BarrilBajaRect);
        }

        /// Dibuja a Mario.
        SDL_Rect rect = {game->mario.x, game->mario.y, 30, 30};
        SDL_RenderCopyEx(renderer, game->marioTexture[game->mario.animTexture], NULL, &rect, 0, NULL,
                         (game->mario.izq == 0));


        /// Dibuja a Mario cuando muere.
        if (game->mario.deadMario) {
            SDL_Rect rect = {game->mario.x, game->mario.y, 30, 30};
            SDL_RenderCopy(renderer, game->deadMario,
                           NULL, &rect);
        }
    }

    /// Se dibuja el juego.
    SDL_RenderPresent(renderer);
}

/**
 * Metodo encargado de mover los barriles.
 * @param newBarril
 * @param game
 */
void moveBarril(int newBarril, GameState *game) {

    /// Verifica la colision con el ground.
    for (int i = 0; i < 135; i++) {
        float mw = 25, mh = 25;
        for (int j = 0; j < newBarril; j++) {
            float mx = game->barriles[j].x, my = game->barriles[j].y;
            float bx = game->piso[i].x, by = game->piso[i].y, bw = game->piso[i].w, bh = game->piso[i].h;

            if (mx + mw > bx && mx < bx + bw) {
                /// Estan cayendo en el suelo.
                if (my + mh > by && my < by && game->barriles[j].dy > 0) {
                    /// Corrige y
                    game->barriles[j].y = by - mh;
                    my = by - mh;
                    game->barriles[j].dy = 0;

                }
            }
        }

    }
    /// Se encarga de que los barriles no se salgan de la pantalla.
    for (int i = 0; i < newBarril; i++) {
        game->barriles[i].x += game->barriles[i].dx;
        game->barriles[i].y += game->barriles[i].dy;

        /// Verifica que el barril no se salga por la derecha.
        if (game->barriles[i].x >= 600) {
            game->barriles[i].dx *= -1;

        }
        /// Verifica que el barill no se salga por la izquierda.
        if (game->barriles[i].x <= 0) {
            game->barriles[i].dx *= -1;

        }
    }
}

/**
 * Metodo que se encarga de movar las llamas.
 * @param newLlamas
 * @param game
 */
void moveLlamas(int newLlamas, GameState *game) {

    //Verifica colision con el ground
    for (int i = 0; i < 135; i++) {
        float mw = 25, mh = 25;
        for (int j = 0; j < newLlamas; j++) {
            float mx = game->llamas[j].x, my = game->llamas[j].y;
            float bx = game->piso[i].x, by = game->piso[i].y, bw = game->piso[i].w, bh = game->piso[i].h;

            if (mx + mw > bx && mx < bx + bw) {

                if (my + mh > by && my < by && game->llamas[j].dy > 0) {

                    game->llamas[j].y = by - mh;
                    my = by - mh;
                    game->llamas[j].dy = 0;

                }
            }
        }

    }
    /// Se encarga de que las llamas no se salgan de la pantalla.
    for (int i = 0; i < newLlamas; i++) {
        game->llamas[i].x += game->llamas[i].dx;
        game->llamas[i].y += game->llamas[i].dy;

        /// Verifica que el llamas no se salgan por la derecha.
        if (game->llamas[i].x >= 600) {
            game->llamas[i].dx *= -1;

        }
        /// Verifica que el llamas no se salgan por la izquierda.
        if (game->llamas[i].x <= 0) {
            game->llamas[i].dx *= -1;

        }
    }

}

/**
 * Metodo que crea un barril de tipo 1.
 * @param newBarril
 * @param game
 */
void createBarril(int newBarril, GameState *game) {
    game->barriles[newBarril].x = 100;
    game->barriles[newBarril].y = 120;
    game->barriles[newBarril].dx = 1;
    game->barriles[newBarril].dy = 0;
}

/**
 * Metodo que crea las llamas.
 * @param newLlamas
 * @param game
 */
void createLlama(int newLlamas, GameState *game) {
    game->llamas[newLlamas].x = 50;
    game->llamas[newLlamas].y = 620;
    game->llamas[newLlamas].dx = 1;
    game->llamas[newLlamas].dy = 0;
    game->llamas[newLlamas].llamaTexture = 0;
    game->llamas[newLlamas].gravedad = 1;
    game->llamas[newLlamas].check = 1;

}

/**
 * Metodo que crea un barril de tipo 2.
 * @param newBarrilBaja
 * @param dy
 * @param game
 */
void createBarrilBaja(int newBarrilBaja, int dy, GameState *game) {
    int numero;
    numero = rand() % 600;
    game->barrilBaja[newBarrilBaja].x = numero;
    game->barrilBaja[newBarrilBaja].y = 120;
    game->barrilBaja[newBarrilBaja].dy = dy;
    game->barrilBaja[newBarrilBaja].barrilBajaTexture = 0;


}

/**
 * Metodo que se encarga de mover a la Princesa.
 * @param game
 */
void movePauline(GameState *game) {
    game->princesa.x += game->princesa.dx;


    /// Verifica que pauline no se salga por la derecha.
    if (game->princesa.x >= 300) {
        game->princesa.dx *= -1;

    }
    /// Verifica que pauline no se salga por la izquierda.
    if (game->princesa.x <= 100) {
        game->princesa.dx *= -1;

    }
}


/**
 * Metodo que se encarga de mover los barriles que bajan por el suelo.
 * @param newBarrilBaja
 * @param game
 */
void moveBarrilBaja(int newBarrilBaja, GameState *game) {
    int i;
    for (int i = 0; i < newBarrilBaja; i++) {
        game->barrilBaja[i].y += game->barrilBaja[i].dy;
    }
}

int barrel_event(char *buffer) {
    int n = 0;
    while (buffer[n] != '\0') {
        n++;
    }
    if (buffer[n - 1] == '1') {
        return 1;
    } else if (buffer[n - 1] == '2') {
        return 2;
    } else if (buffer[n - 1] == '3') {
        return 3;
    }
    return 0;
}

// /// Da la informacion del juego al servidor
//void send_info(int sockfd, GameState *game, int *newBarril, int *newBarrilBaja) {
//    printf("Mensaje a enviar: ");
//    char buffer[MAX];
//    char man_x[10];
//    char man_y[10];
//    int i = 0;
//    snprintf(man_x, sizeof man_x, "%f", game->mario.x);
//    snprintf(man_y, sizeof man_y, "%f", game->mario.y);
//    buffer[0] = '1';
//    buffer[1] = '/';
//
//    while (man_x[i] != '\0') {
//        buffer[i + 2] = man_x[i];
//        i++;
//    }
//    buffer[i] = '/';
//
//    int j = 0;
//
//    while (man_y[j] != '\0') {
//        buffer[i + 1] = man_y[j];
//        i++;
//        j++;
//    }
//
//    printf("%s\n", buffer);
//
//    write(sockfd, buffer, sizeof(buffer));
//    bzero(buffer, sizeof(buffer));
//    read(sockfd, buffer, sizeof(buffer));
//    printf("Mensaje del servidor: %s\n", buffer);
//
//    if (barrel_event(buffer) == 1) {
//        *newBarril = *newBarril + 1;
//    } else if (barrel_event(buffer) == 2) {
//        *newBarrilBaja = *newBarrilBaja + 1;
//    }
//
//    if ((strncmp(buffer, "exit", 4)) == 0) {
//        printf("El cliente ha salido...\n");
//    }
//}


/**
 * Pues el main.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
//
//    //Socket
//    int sockfd, connfd;
//    struct sockaddr_in servaddr, cli;
//
//    // socket create and varification
//    sockfd = socket(AF_INET, SOCK_STREAM, 0);
//    if (sockfd == -1) {
//        printf("Error al crear el socket...\n");
//        exit(0);
//    } else
//        printf("Socket creado exitosamente..\n");
//    bzero(&servaddr, sizeof(servaddr));
//
//    // assign IP, PORT
//    servaddr.sin_family = AF_INET;
//    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
//    servaddr.sin_port = htons(PORT);
//
//    // connect the client socket to server socket
//    if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) != 0) {
//        printf("Error en la conexion al servidor...\n");
//        exit(0);
//    } else
//        printf("Conectado al servidor...\n");

    GameState gameState;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("DonCEy Kong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 700, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    /// Asigna al render creado el render con el gameState
    gameState.renderer = renderer;
    SDL_RenderSetLogicalSize(renderer, 600, 700);

    /// Inicializar el font.
    TTF_Init();

    /// Llama al metodo loadGame que carga el juego.
    loadGame(&gameState);

    /// Abre la ventana
    int done = 0;
    /// Variables para crear barriles de tipo 1.
    int temporalBarril = 0;
    int newBarril = 0;
    /// Variables para crear llamas.
    int temporalLlama = 0;
    int newLlama = 0;
    /// Variables para crear barriles de tipo 2.
    int temporalBarrilBaja = 0;
    int newBarrilBaja = 0;

    /// Ciclo del evento principal del juego.
    while (!done) {

        /// Verifica eventos.
        done = processEvents(window, &gameState, &temporalBarril, &temporalLlama, &temporalBarrilBaja);

        /// Verifica  que los como se crean lo barriles para saber cuantos se deben pintar.
        if (temporalBarril > 0 && newBarril < NUM_BARRILES) {
            createBarril(newBarril, &gameState);
            newBarril += 1;
            temporalBarril = 0;
        }

        /// Verifica como se crean las llamas para saber cuantos se deben pintar.
        if (temporalLlama > 0 && newLlama < NUM_LLAMAS) {
            createLlama(newLlama, &gameState);
            newLlama += 1;
            temporalLlama = 0;
        }

        /// Verifica como se crean los barriles que bajan para saber cuantos se deben pintar.
        if (temporalBarrilBaja > 0 && newBarrilBaja < NUM_BARRIL_BAJA) {
            createBarrilBaja(newBarrilBaja, 1, &gameState);
            newBarrilBaja += 1;
            temporalBarrilBaja = 0;
        }

        /// Llama al metodo process que nos permite crear las animaciones de movimiento.
        process(newBarril, newLlama, newBarrilBaja, &gameState);

        /// Llama al metodo que verifica colosiones entre objetos.
        collisionDetect(&gameState);

        /// Llama al metodo que dezplega el render.
        doRender(renderer, &gameState, newBarril, newLlama, newBarrilBaja);

        /// Llama el método para rodar barril.
        moveBarril(newBarril, &gameState);

        /// Llama el método para mover llamas.
        moveLlamas(newLlama, &gameState);

        moveBarrilBaja(newBarrilBaja, &gameState);

        /// Mover Princesa.
        movePauline(&gameState);

    }

    /// Libera la memoria.
    SDL_DestroyTexture(gameState.marioTexture[0]);
    SDL_DestroyTexture(gameState.marioTexture[1]);
    SDL_DestroyTexture(gameState.ground);
    if (gameState.label != NULL) {
        SDL_DestroyTexture(gameState.label);
    }

    TTF_CloseFont(gameState.font);

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    TTF_Quit();
    SDL_Quit();

    return 0;
}