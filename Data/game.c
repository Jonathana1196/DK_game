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
static int dificult=2;
static bool in=false;
static int walk=0;
static bool jum=true;
static int life=3;
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
static int length=1;
static int ini=0;
static int limit=0;
static SDL_Rect barrilesC[100];
static SDL_Rect barrilesN[100];
static SDL_Rect barrilesT[100];
static SDL_Rect barrilestC[100];
static SDL_Rect barrilestN[100];
static SDL_Rect barrilestT[100];
static SDL_Texture* barrilessC[100];
static SDL_Texture* barrilessN[100];
static SDL_Texture* barrilessT[100];
static SDL_Rect lifelist[10];
static SDL_Texture* lifelistS[10];
static SDL_Rect lifelistT[10];
static int bC=0;
static int bN=0;
static int bT=0;
static SDL_Rect tempBar;
void Getbarril(char* tipo){
    if(tipo=="C"){
        SDL_Rect windowRectB;
        SDL_Rect textureRectB;
        SDL_Surface* tempB = IMG_Load("../Data/barril2.png");
        SDL_Texture* spriteSheetB = SDL_CreateTextureFromSurface(renderer, tempB);
        SDL_FreeSurface(tempB);
        windowRectB.x = 200;
        windowRectB.y = 80;
        windowRectB.w = 30;
        windowRectB.h = 30;
        textureRectB.x = 0;
        textureRectB.y = 0;
        SDL_QueryTexture(spriteSheetB, NULL, NULL, &textureRectB.w, &textureRectB.h);
        textureRectB.w /= 4;
        barrilesC[bC]=windowRectB;
        barrilestC[bC]=textureRectB;
        barrilessC[bC]=spriteSheetB;
        barrilesC[bC].x=rand()%500;
        bC++;
    }
    else if(tipo=="N") {
        SDL_Rect windowRectB;
        SDL_Rect textureRectB;
        SDL_Surface* tempB = IMG_Load("../Data/barril1.png");
        SDL_Texture* spriteSheetB = SDL_CreateTextureFromSurface(renderer, tempB);
        SDL_FreeSurface(tempB);
        windowRectB.x = 180;
        windowRectB.y = 110;
        windowRectB.w = 30;
        windowRectB.h = 30;
        textureRectB.x = 0;
        textureRectB.y = 0;
        SDL_QueryTexture(spriteSheetB, NULL, NULL, &textureRectB.w, &textureRectB.h);
        textureRectB.w /= 4;
        barrilesN[bN]=windowRectB;
        barrilestN[bN]=textureRectB;
        barrilessN[bN]=spriteSheetB;
        bN++;
    }
    else if(tipo=="T"){
        SDL_Rect windowRectB;
        SDL_Rect textureRectB;
        SDL_Surface* tempB = IMG_Load("../Data/barril1.png");
        SDL_Texture* spriteSheetB = SDL_CreateTextureFromSurface(renderer, tempB);
        SDL_FreeSurface(tempB);
        windowRectB.x = 240;
        windowRectB.y = 25;
        windowRectB.w = 30;
        windowRectB.h = 30;
        textureRectB.x = 0;
        textureRectB.y = 0;
        SDL_QueryTexture(spriteSheetB, NULL, NULL, &textureRectB.w, &textureRectB.h);
        textureRectB.w /= 4;
        barrilesT[bT]=windowRectB;
        barrilestT[bT]=textureRectB;
        barrilessT[bT]=spriteSheetB;
        bT++;
    }
}
void lifes(){
    for (int i;i<life;i++){
        SDL_Rect windowRectML;
        SDL_Rect textureRectML;
        SDL_Surface* tempL = IMG_Load("../Data/mario.png");
        SDL_Texture* spriteSheetML = SDL_CreateTextureFromSurface(renderer, tempL);
        SDL_FreeSurface(tempL);
        windowRectML.x = 500+(i*20);
        windowRectML.y = 20;
        windowRectML.w = 20;
        windowRectML.h = 30;
        textureRectML.x = 0;
        textureRectML.y = 0;
        SDL_QueryTexture(spriteSheetML, NULL, NULL, &textureRectML.w, &textureRectML.h);
        lifelist[i]=windowRectML;
        lifelistS[i]=spriteSheetML;
        lifelistT[i]=textureRectML;
    }
}
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
void death(){
    for(int i=0;i<bN;i++){
        if((barrilesN[i].x-10)<windowRectM.x && windowRectM.x<(barrilesN[i].x+10)&& (barrilesN[i].y-10)<windowRectM.y && windowRectM.y<(barrilesN[i].y+10)){
            Mix_Chunk* death=Mix_LoadWAV("../Data/death.wav");
            Mix_PlayChannel(-1,death,0);
            life-=1;
            bC=0;
            bN=0;
            bT=0;
            lifes();
            jump=0;
            bool jumping = false;
            bool stop=true;
            bool stairs=false;
            bool in=false;
            walk=0;
            bool jum=true;
            Mario();

        }

    }
    for(int i=0;i<bC;i++){
        if((barrilesC[i].x-10)<windowRectM.x && windowRectM.x<(barrilesC[i].x+10)&& (barrilesC[i].y-10)<windowRectM.y && windowRectM.y<(barrilesC[i].y+10)){
            Mix_Chunk* death=Mix_LoadWAV("../Data/death.wav");
            Mix_PlayChannel(-1,death,0);
            life-=1;
            bC=0;
            bN=0;
            bT=0;
            lifes();
            jump=0;
            bool jumping = false;
            bool stop=true;
            bool stairs=false;
            bool in=false;
            walk=0;
            bool jum=true;
            Mario();
        }

    }
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
    else if(event.key.keysym.sym==SDLK_c){
        Getbarril("C");

    }
    else if(event.key.keysym.sym==SDLK_t){
        Getbarril("T");


    }
    else if(event.key.keysym.sym==SDLK_n){
        Getbarril("N");


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
            }
            if(windowRectM.y<45){
                win();
            }
            if (event.key.keysym.sym == SDLK_UP) {
                windowRectM.y -= 2;
                length++;
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
void moveB(SDL_Rect* bar){
    if((bar->x>=519)&&(bar->x<=525) ){
        for(int x=0;x!=60;x++){
            bar->y++;
        }
        bar->x-=dificult;
    }
    if(bar->x<=50 && bar->x>=45 && bar->y<515){
        for(int c=0;c!=60;c++){
            bar->y++;
        }
        bar->x+=dificult;
    }

    else if ((bar->x<520 && bar->y<170) || (bar->y<283 &&bar->y>200)||(bar->y<465 &&bar->y>420)){
        bar->x+=dificult;
    }

    else if((bar->x>50 && bar->y<200) ||(bar->y<370 &&bar->y>300)||(bar->y<520 &&bar->y>500)){
        bar->x-=dificult;
    }

    if((515>=bar->y) && (bar->x<275)&&(495<=bar->y)){
        bar->y+=1;
    }
    else if((508>=bar->y) && (bar->x<325)&&(495<=bar->y)){
        bar->y+=1;
    }
    else if((505>=bar->y) && (bar->x<375)&&(495<=bar->y)){
        bar->y+=1;

    }
    else if((502>=bar->y)&&(bar->x<425)&&(495<=bar->y)){
        bar->y+=1;
    }
    else if((500>=bar->y)&&(bar->x<475)&&(495<=bar->y)){
        bar->y+=1;
    }
    else if((440>=bar->y) && (bar->x>425)&&(410<=bar->y)){
        bar->y+=1;
    }
    else if((437>=bar->y) && (bar->x>375)&&(410<=bar->y)){
        bar->y+=1;
    }
    else if((435>=bar->y) && (bar->x>325)&&(410<=bar->y)){
        bar->y+=1;
    }
    else if((432>=bar->y) && (bar->x>275)&&(410<=bar->y)){
        bar->y+=1;
    }
    else if((429>=bar->y) && (bar->x>220)&&(410<=bar->y)){
        bar->y+=1;
    }
    else if((425>=bar->y) && (bar->x>175)&&(410<=bar->y)){
        bar->y+=1;
    }
    else if((422>=bar->y) && (bar->x>75)&&(410<=bar->y)){
        bar->y+=1;

    }
    else if((362>=bar->y) && (bar->x<135)&&(335<=bar->y)){
        bar->y+=1;

    }
    else if((356>=bar->y) && (bar->x<175)&&(335<=bar->y)){
        bar->y+=1;

    }
    else if((355>=bar->y) && (bar->x<205)&&(335<=bar->y)){
        bar->y+=1;

    }
    else if((352>=bar->y) && (bar->x<230)&&(335<=bar->y)){
        bar->y+=1;

    }
    else if((348>=bar->y) && (bar->x<290)&&(335<=bar->y)){
        bar->y+=1;

    }
    else if((345>=bar->y) && (bar->x<330)&&(335<=bar->y)){
        bar->y+=1;

    }
    else if((340>=bar->y) && (bar->x<430)&&(335<=bar->y)){
        bar->y+=1;

    }
    else  if((281>=bar->y) && (bar->x>460)&&(190<=bar->y)){
        bar->y+=1;
    }
    else  if((279>=bar->y) && (bar->x>450)&&(190<=bar->y)){
        bar->y+=1;
    }
    else  if((277>=bar->y) && (bar->x>430)&&(190<=bar->y)){
        bar->y+=1;
    }
    else  if((275>=bar->y) && (bar->x>400)&&(190<=bar->y)){
        bar->y+=1;
    }
    else if((272>=bar->y) && (bar->x>330)&&(190<=bar->y)){
        bar->y+=1;
    }
    else if((270>=bar->y) && (bar->x>290)&&(190<=bar->y)){
        bar->y+=1;
    }
    else if((265>=bar->y) && (bar->x>230)&&(190<=bar->y)){
        bar->y+=1;
    }
    else if((263>=bar->y) && (bar->x>200)&&(190<=bar->y)){
        bar->y+=1;
    }
    else if((260>=bar->y) && (bar->x>175)&&(190<=bar->y)){
        bar->y+=1;
    }
    else if((197>=bar->y) && (bar->x<135)&&(170<=bar->y)){
        bar->y+=1;
    }
    else if((192>=bar->y) && (bar->x<175)&&(170<=bar->y)){
        bar->y+=1;
    }
    else if((187>=bar->y) && (bar->x<230)&&(170<=bar->y)){
        bar->y+=1;
    }
    else if((185>=bar->y) && (bar->x<330)&&(170<=bar->y)){
        bar->y+=1;
    }
    else if((183>=bar->y) && (bar->x<390)&&(170<=bar->y)){
        bar->y+=1;
    }
    else if((182>=bar->y) && (bar->x<430)&&(170<=bar->y)){
        bar->y+=1;

    }
    else if((180>=bar->y) && (bar->x<480)&&(170<=bar->y)){
        bar->y+=1;

    }
    else if((122>=bar->y) && (bar->x>230)&&(75<=bar->y)){
        bar->y+=1;
    }
    else if((117>=bar->y) && (bar->x>180)&&(75<=bar->y)){
        bar->y+=1;
    }
    else if((112>=bar->y) && (bar->x>150)&&(75<=bar->y)){
        bar->y+=1;
    }
}
void win(){
    Mix_Chunk* winning=Mix_LoadWAV("../Data/win1.wav");
    Mix_PlayChannel(-1,winning,0);
    life+=1;
    bC=0;
    bN=0;
    bT=0;
    lifes();
    jump=0;
    bool jumping = false;
    bool stop=true;
    bool stairs=false;
    dificult+=1;
    bool in=false;
    walk=0;
    bool jum=true;
    Mario();

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
    lifes();
    bool running = true;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, background);
    IMG_Init(IMG_INIT_PNG);
    Donkey1();
    Princesa();
    Mario();
    lifes();
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            eventos(event);
        }
        if (jumping) {
            jum = false;
            if (jump == 50) {
                jump = 0;
                jum = true;
                jumping = false;
                windowRectM.y -= 2;
            } else if (jump <= 24) {
                windowRectM.y -= 2;

            } else {
                windowRectM.y += 2;

            }
            jump++;
        }
        int totalFramesB = 4;
        int delayPerFrameB = 100;
        int frameB = (SDL_GetTicks() / delayPerFrameB) % totalFramesB;
        for(int i=0;i<bC;i++){
            barrilestC[i].x = frameB * barrilestC[i].w;
            barrilesC[i].y+=dificult;
            SDL_RenderCopy(renderer, barrilessC[i], &barrilestC[i], &barrilesC[i]);
        }
        for(int i=0;i<bN;i++) {
            barrilestN[i].x = frameB * barrilestN[i].w;
            moveB(&barrilesN[i]);
            SDL_RenderCopy(renderer, barrilessN[i], &barrilestN[i], &barrilesN[i]);

        }
        for(int i=0;i<bT;i++) {
            barrilestT[i].x = frameB * barrilestT[i].w;
            SDL_RenderCopy(renderer, barrilessT[i], &barrilestT[i], &barrilesT[i]);
        }
        for(int i=0;i<life;i++){
            SDL_RenderCopy(renderer, lifelistS[i], &lifelistT[i], &lifelist[i]);
        }
        death();
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
    SDL_DestroyTexture(barrilessC);
    SDL_DestroyTexture(barrilessT);
    SDL_DestroyTexture(barrilessN);
    SDL_DestroyTexture(spriteSheetD);
    SDL_DestroyTexture(spriteSheetM);
    SDL_DestroyTexture(spriteSheetP);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_FreeSurface(background);
    Mix_CloseAudio();
    SDL_Quit();
}