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
static bool stairs=false;
static int walk=0;
static bool jum=true;
static SDL_Rect textureRectM;
static SDL_Rect windowRectM;
static SDL_Rect textureRectP;
static SDL_Rect windowRectP;
static SDL_Rect textureRectD;
static SDL_Rect windowRectD;
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
void ventana(){
    SDL_Init(SDL_INIT_EVERYTHING);
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2018);
    Mix_Music*back=Mix_LoadMUS("../Data/bacmusic.wav");
    Mix_Chunk *jumpsund=Mix_LoadWAV("../Data/jump.wav");
    Mix_Chunk* walking=Mix_LoadWAV("../Data/walking.wav");
    Mix_PlayMusic(back,-1);
    window=SDL_CreateWindow("DK GAME",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,600,600,SDL_WINDOW_OPENGL);
    surface=SDL_GetWindowSurface(window);
    SDL_Surface* background;
    background=SDL_LoadBMP("../Data/background.bmp");
    SDL_BlitSurface(background,NULL,surface,NULL);
    SDL_UpdateWindowSurface(window);
    SDL_Event event;
    bool running=true;
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_PRESENTVSYNC|SDL_RENDERER_ACCELERATED);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, background);
    IMG_Init(IMG_INIT_PNG);
    ////DONKEY1////
    SDL_Surface* tempD = IMG_Load("../Data/Donkey1.png");
    SDL_Texture* spriteSheetD = SDL_CreateTextureFromSurface(renderer, tempD);
    SDL_FreeSurface(tempD);
    windowRectD.x = 65;
    windowRectD.y = 65;
    windowRectD.w = 120;
    windowRectD.h = 80;
    textureRectD.x = 0;
    textureRectD.y = 0;
    SDL_QueryTexture(spriteSheetD, NULL, NULL, &textureRectD.w, &textureRectD.h);
    textureRectD.w /= 2;
    ///PRINCESA///
    SDL_Surface* tempP = IMG_Load("../Data/Princesa.png");
    SDL_Texture* spriteSheetP = SDL_CreateTextureFromSurface(renderer, tempP);
    SDL_FreeSurface(tempP);
    windowRectP.x = 240;
    windowRectP.y = 25;
    windowRectP.w = 60;
    windowRectP.h = 50;
    textureRectP.x = 0;
    textureRectP.y = 0;
    SDL_QueryTexture(spriteSheetD, NULL, NULL, &textureRectP.w, &textureRectP.h);
    textureRectP.w /= 4;
    ///MARIO///
    SDL_Surface* tempM = IMG_Load("../Data/marioR.png");
    SDL_Texture* spriteSheetM = SDL_CreateTextureFromSurface(renderer, tempM);
    SDL_FreeSurface(tempM);
    windowRectM.x = 100;
    windowRectM.y = 515;
    windowRectM.w = 30;
    windowRectM.h = 30;
    textureRectM.x = 0;
    textureRectM.y =0;
    SDL_QueryTexture(spriteSheetM, NULL, NULL, &textureRectM.w, &textureRectM.h);
    textureRectM.w /= 1;
    while (running){
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            } else if (event.key.keysym.sym == SDLK_RIGHT && !stairs) {
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

            } else if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_DOWN) {
                tempM = IMG_Load("../Data/marioU.png");
                spriteSheetM = SDL_CreateTextureFromSurface(renderer, tempM);
                textureRectM.w = 15;
                int totalFramesM = 2;
                int delayPerFrameM = 100;
                windowRectM.w = 35;
                windowRectM.h = 35;
                int frameM = (SDL_GetTicks() / delayPerFrameM) % totalFramesM;
                textureRectM.x = frameM * textureRectM.w;
                if (event.key.keysym.sym == SDLK_UP) {
                    windowRectM.y -= 2;
                } else if (event.key.keysym.sym == SDLK_DOWN) {
                    windowRectM.y += 2;
                }


            }
            if (event.key.keysym.sym == SDLK_SPACE && !stairs) {
                jumping = true;
                if(jum){
                    Mix_PlayChannel(-1,jumpsund,0);
                }
            }

        }
        if (jumping) {
            jum=false;
            if (jump==40){
                jump=0;
                jum=true;
                jumping=false;
                windowRectM.y -= 2;
            }
            else if (jump <= 19) {
                windowRectM.y -= 2;

            }
            else {
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
int main(int argc,char** argv) {
    ventana();
    return 0;
}