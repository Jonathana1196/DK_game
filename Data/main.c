#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include <pthread.h>
#include "game.c"
#include "cliente.h"
int main(int argc,char** argv) {
    pthread_t  thread_id;
    pthread_create(&thread_id, NULL, &ventana, NULL);
    pthread_t  thread_id2;
    pthread_create(&thread_id2, NULL, &conectar_Socket, NULL);
    pthread_join(thread_id, NULL);
    pthread_join(thread_id2, NULL);
    return 0;
}