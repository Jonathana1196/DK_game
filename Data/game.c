#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
static SDL_Window* window;
static SDL_Surface* surface;
static SDL_Renderer* renderer;
static int jump=0;
static  bool jumping = false;
static bool stop=true;
static bool stairs=false;
static bool in=false;
static int walk=0;
static bool jum=true;
static SDL_Rect textureRectM;
static SDL_Rect windowRectM;
static SDL_Rect textureRectP;
static SDL_Rect windowRectP;
static SDL_Rect textureRectD;
static SDL_Rect windowRectD;
static SDL_Texture* spriteSheetD;
static SDL_Texture* spriteSheetP;
static SDL_Texture* spriteSheetM;
static SDL_Surface* tempM;
int length=1;
static int ini=0;
static int limit=0;
void moveR(int x){
    if((510<=windowRectM.y) && (x>275) &&!jumping){
        windowRectM.y-=1;
    }
    else if((505<=windowRectM.y) && (x>375)&&!jumping){
        windowRectM.y-=1;
    }
    else if((500<=windowRectM.y) && (x>550)&&!jumping){
        windowRectM.y-=1;
    }
    else if((435>=windowRectM.y) && (x>375)&&(410<=windowRectM.y)&&!jumping){
        windowRectM.y+=1;
    }
    else if((430>=windowRectM.y) && (x>275)&&(410<=windowRectM.y)&&!jumping){
        windowRectM.y+=1;
    }
    else if((425>=windowRectM.y) && (x>175)&&(410<=windowRectM.y)&&!jumping){
        windowRectM.y+=1;
    }
    else if((420>=windowRectM.y) && (x>75)&&(410<=windowRectM.y)&&!jumping){
        windowRectM.y+=1;
    }
    else if((355<=windowRectM.y) && (x>175)&&(500>=windowRectM.y)&&!jumping){
        windowRectM.y-=1;
    }
    else if((350<=windowRectM.y) && (x>230)&&(500>=windowRectM.y)&&!jumping){
        windowRectM.y-=1;
    }
    else if((345<=windowRectM.y) && (x>330)&&(500>=windowRectM.y)&&!jumping){
        windowRectM.y-=1;
    }
    else if((340<=windowRectM.y) && (x>430)&&(500>=windowRectM.y)&&!jumping){
        windowRectM.y-=1;
    }
    else  if((270>=windowRectM.y) && (x>430)&&(190<=windowRectM.y)&&!jumping){
        windowRectM.y+=1;
    }
    else if((265>=windowRectM.y) && (x>330)&&(190<=windowRectM.y)&&!jumping){
        windowRectM.y+=1;
    }
    else if((260>=windowRectM.y) && (x>230)&&(190<=windowRectM.y)&&!jumping){
        windowRectM.y+=1;
    }
    else if((255>=windowRectM.y) && (x>175)&&(190<=windowRectM.y)&&!jumping){
        windowRectM.y+=1;
    }
    else if((190<=windowRectM.y) && (x>75)&&(230>=windowRectM.y)&&!jumping){
        windowRectM.y-=1;
    }
    else if((185<=windowRectM.y) && (x>130)&&(230>=windowRectM.y)&&!jumping){
        windowRectM.y-=1;
    }
    else if((180<=windowRectM.y) && (x>230)&&(230>=windowRectM.y)&&!jumping){
        windowRectM.y-=1;
    }
    else if((175<=windowRectM.y) && (x>330)&&(230>=windowRectM.y)&&!jumping){
        windowRectM.y-=1;
    }
    else if((115>=windowRectM.y) && (x>430)&&(75<=windowRectM.y)&&!jumping){
        windowRectM.y+=1;
    }
    else if((110>=windowRectM.y) && (x>330)&&(75<=windowRectM.y)&&!jumping){
        windowRectM.y+=1;
    }
    else if((105>=windowRectM.y) && (x>275)&&(75<=windowRectM.y)&&!jumping){
        windowRectM.y+=1;
    }

}
void moveL(int x){
    if((510>=windowRectM.y) && (x<275) &&!jumping &&(495<=windowRectM.y)){
        windowRectM.y+=1;
    }
    else if((505>=windowRectM.y) && (x<375)&&!jumping &&(495<=windowRectM.y)){
        windowRectM.y+=1;
    }
    else if((500>=windowRectM.y) && (x<475)&&!jumping &&(495<=windowRectM.y)){
        windowRectM.y+=1;
    }
    else if((435<=windowRectM.y) && (x<375)&&(470>=windowRectM.y)&&!jumping){
        windowRectM.y-=1;
    }
    else if((430<=windowRectM.y) && (x<275)&&(470>=windowRectM.y)&&!jumping){
        windowRectM.y-=1;
    }
    else if((425<=windowRectM.y) && (x<175)&&(470>=windowRectM.y)&&!jumping){
        windowRectM.y-=1;
    }
    else if((420<=windowRectM.y) && (x<75)&&(470>=windowRectM.y)&&!jumping){
        windowRectM.y-=1;
    }
    else if((355>=windowRectM.y) && (x<175)&&(335<=windowRectM.y)&&!jumping){
        windowRectM.y+=1;
    }
    else if((350>=windowRectM.y) && (x<230)&&(335<=windowRectM.y)&&!jumping){
        windowRectM.y+=1;
    }
    else if((345>=windowRectM.y) && (x<330)&&(335<=windowRectM.y)&&!jumping){
        windowRectM.y+=1;
    }
    else if((340>=windowRectM.y) && (x<430)&&(335<=windowRectM.y)&&!jumping){
        windowRectM.y+=1;
    }
    else if((270<=windowRectM.y) && (x<430)&&(340>=windowRectM.y)&&!jumping){
        windowRectM.y-=1;
    }
    else if((265<=windowRectM.y) && (x<330)&&(340>=windowRectM.y)&&!jumping){
        windowRectM.y-=1;
    }
    else if((260<=windowRectM.y) && (x<230)&&(340>=windowRectM.y)&&!jumping){
        windowRectM.y-=1;
    }
    else if((255<=windowRectM.y) && (x<175)&&(340>=windowRectM.y)&&!jumping){
        windowRectM.y-=1;
    }
    else if((190>=windowRectM.y) && (x<175)&&(170<=windowRectM.y)&&!jumping){
        windowRectM.y+=1;
    }
    else if((185>=windowRectM.y) && (x<230)&&(170<=windowRectM.y)&&!jumping){
        windowRectM.y+=1;
    }
    else if((180>=windowRectM.y) && (x<330)&&(170<=windowRectM.y)&&!jumping){
        windowRectM.y+=1;
    }
    else if((175>=windowRectM.y) && (x<430)&&(170<=windowRectM.y)&&!jumping){
        windowRectM.y+=1;
    }
    else if((115<=windowRectM.y) && (x<430)&&(175>=windowRectM.y)&&!jumping){
        windowRectM.y-=1;
    }
    else if((110<=windowRectM.y) && (x<330)&&(175>=windowRectM.y)&&!jumping){
        windowRectM.y-=1;
    }
    else if((105<=windowRectM.y) && (x<275)&&(175>=windowRectM.y)&&!jumping){
        windowRectM.y-=1;
    }

}
void Donkey1(){
    SDL_Surface* tempD = IMG_Load("../Data/Donkey1.png");
    spriteSheetD = SDL_CreateTextureFromSurface(renderer, tempD);
    SDL_FreeSurface(tempD);
    windowRectD.x = 65;
    windowRectD.y = 65;
    windowRectD.w = 120;
    windowRectD.h = 80;
    textureRectD.x = 0;
    textureRectD.y = 0;
    SDL_QueryTexture(spriteSheetD, NULL, NULL, &textureRectD.w, &textureRectD.h);
    textureRectD.w /= 2;

}
void Princesa(){
    SDL_Surface* tempP = IMG_Load("../Data/Princesa.png");
    spriteSheetP = SDL_CreateTextureFromSurface(renderer, tempP);
    SDL_FreeSurface(tempP);
    windowRectP.x = 240;
    windowRectP.y = 25;
    windowRectP.w = 60;
    windowRectP.h = 50;
    textureRectP.x = 0;
    textureRectP.y = 0;
    SDL_QueryTexture(spriteSheetP, NULL, NULL, &textureRectP.w, &textureRectP.h);
    textureRectP.w /= 2;
}
void Mario(){
    tempM = IMG_Load("../Data/marioR.png");
    spriteSheetM = SDL_CreateTextureFromSurface(renderer, tempM);
    SDL_FreeSurface(tempM);
    windowRectM.x = 100;
    windowRectM.y = 515;
    windowRectM.w = 30;
    windowRectM.h = 30;
    textureRectM.x = 0;
    textureRectM.y =0;
    SDL_QueryTexture(spriteSheetM, NULL, NULL, &textureRectM.w, &textureRectM.h);
    textureRectM.w /= 1;
}
void eventos(SDL_Event event){
    Mix_Chunk *jumpsund=Mix_LoadWAV("../Data/jump.wav");
    Mix_Chunk* walking=Mix_LoadWAV("../Data/walking.wav");
    if (event.key.keysym.sym == SDLK_RIGHT && !stairs) {
        stop=true;
        tempM = IMG_Load("../Data/marioML.png");
        spriteSheetM = SDL_CreateTextureFromSurface(renderer, tempM);
        textureRectM.w = 18;
        int totalFramesM = 2;
        int delayPerFrameM = 100;
        windowRectM.w = 35;
        windowRectM.h = 35;
        windowRectM.x += 2;
        moveR(windowRectM.x);
        printf("\neje X:%i",windowRectM.x);
        printf("\neje Y: %i",windowRectM.y);
        int frameM = (SDL_GetTicks() / delayPerFrameM) % totalFramesM;
        textureRectM.x = frameM * textureRectM.w;
        if(walk==45){
            walk=0;
        }
        if(walk==0 && !jumping){
            Mix_PlayChannel(-1,walking,0);
            walk=0;
        }
        walk++;
    }
    else if (event.key.keysym.sym == SDLK_LEFT && !stairs) {
        stop=true;
        tempM = IMG_Load("../Data/marioM.png");
        spriteSheetM = SDL_CreateTextureFromSurface(renderer, tempM);
        textureRectM.w = 18;
        int totalFramesM = 2;
        int delayPerFrameM = 100;
        windowRectM.w = 35;
        windowRectM.h = 35;
        int frameM = (SDL_GetTicks() / delayPerFrameM) % totalFramesM;
        textureRectM.x = frameM * textureRectM.w;
        windowRectM.x -= 2;
        moveL(windowRectM.x);
        printf("\neje X:%i",windowRectM.x);
        printf("\neje Y: %i",windowRectM.y);
        if(walk==45){
            walk=0;
        }
        if(walk==0 && !jumping){
            Mix_PlayChannel(-1,walking,0);
            walk=0;
        }
        walk++;

    } else if ((event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_DOWN)) {
        onStairs();
        if (in){
            tempM = IMG_Load("../Data/marioU.png");
            spriteSheetM = SDL_CreateTextureFromSurface(renderer, tempM);
            textureRectM.w = 15;
            int totalFramesM = 2;
            int delayPerFrameM = 100;
            windowRectM.w = 35;
            windowRectM.h = 35;
            int frameM = (SDL_GetTicks() / delayPerFrameM) % totalFramesM;
            textureRectM.x = frameM * textureRectM.w;
            if(length==0|| length>limit){
                stairs=false;
                in=false;
                length=-limit;
                stop=false;
                printf("FIN ESCALERS");
            }
            if (event.key.keysym.sym == SDLK_UP) {
                windowRectM.y -= 2;
                length++;
                printf("\nNUMERO%i",length);
            }
             if (event.key.keysym.sym == SDLK_DOWN) {
                windowRectM.y += 2;
                length++;
            }
        }

    }
    if (event.key.keysym.sym == SDLK_SPACE && !stairs) {
        jumping = true;
        if(jum){
            Mix_PlayChannel(-1,jumpsund,0);
        }
    }
}
void onStairs(){
    if(stop){
        if(!stairs){
            if (windowRectM.x<475&&windowRectM.x>455 && (windowRectM.y>=435 && windowRectM.y<=505)){
                in=true;
                stairs=true;
                limit=30;
                length=1;
            }
            else if (windowRectM.x<260&&windowRectM.x>235 && (windowRectM.y>=345 && windowRectM.y<=429)){
                in=true;
                stairs=true;
                limit=40;
                length=1;
            }
            else if (windowRectM.x<100&&windowRectM.x>80 && (windowRectM.y>=355 && windowRectM.y<=425)){
                in=true;
                stairs=true;
                limit=30;
                length=1;
            }
            else if (windowRectM.x<305&&windowRectM.x>275 && (windowRectM.y>=260 && windowRectM.y<=350)){
                in=true;
                stairs=true;
                limit=40;
                length=1;
            }
            else if (windowRectM.x<475&&windowRectM.x>455 && (windowRectM.y>=270 && windowRectM.y<=340)){
                in=true;
                stairs=true;
                limit=30;
                length=1;
            }
            else if (windowRectM.x<200&&windowRectM.x>180 && (windowRectM.y>=185 && windowRectM.y<=260)){
                in=true;
                stairs=true;
                limit=35;
                length=1;

            }
            else if (windowRectM.x<100&&windowRectM.x>80 && (windowRectM.y>=190 && windowRectM.y<=255)){
                in=true;
                stairs=true;
                limit=30;
                length=1;

            }
            else if (windowRectM.x<475&&windowRectM.x>455 && (windowRectM.y>=106 && windowRectM.y<=176)){
                in=true;
                stairs=true;
                limit=30;
                length=1;
            }
            else if (windowRectM.x<340&&windowRectM.x>320 && (windowRectM.y>=45 && windowRectM.y<=112)) {
                in = true;
                stairs = true;
                limit = 35;
                length=1;

            }
        }
    }

}
void ventana() {
    SDL_Init(SDL_INIT_EVERYTHING);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2018);
    Mix_Music *back = Mix_LoadMUS("../Data/bacmusic.wav");
    Mix_PlayMusic(back, -1);
    window = SDL_CreateWindow("DK GAME", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, SDL_WINDOW_OPENGL);
    surface = SDL_GetWindowSurface(window);
    SDL_Surface *background;
    background = SDL_LoadBMP("../Data/background.bmp");
    SDL_BlitSurface(background, NULL, surface, NULL);
    SDL_UpdateWindowSurface(window);
    SDL_Event event;
    bool running = true;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, background);
    IMG_Init(IMG_INIT_PNG);
    Donkey1();
    Princesa();
    Mario();
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            eventos(event);
        }
        if (jumping) {
            jum = false;
            if (jump == 40) {
                jump = 0;
                jum = true;
                jumping = false;
                windowRectM.y -= 2;
            } else if (jump <= 19) {
                windowRectM.y -= 2;

            } else {
                windowRectM.y += 2;

            }
            jump++;
        }
        ///DONKEY///
        int totalFramesD = 2;
        int delayPerFrameD = 300;
        int frameD = (SDL_GetTicks() / delayPerFrameD) % totalFramesD;
        textureRectD.x = frameD * textureRectD.w;
        ////PRINCESA////
        int totalFramesP = 2;
        int delayPerFrameP = 250;
        int frameP = (SDL_GetTicks() / delayPerFrameP) % totalFramesP;
        textureRectP.x = frameP * textureRectP.w;
        SDL_RenderCopy(renderer, spriteSheetM, &textureRectM, &windowRectM);
        SDL_RenderCopy(renderer, spriteSheetD, &textureRectD, &windowRectD);
        SDL_RenderCopy(renderer, spriteSheetP, &textureRectP, &windowRectP);
        SDL_RenderPresent(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);


    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_FreeSurface(background);
    Mix_CloseAudio();
    SDL_Quit();
}