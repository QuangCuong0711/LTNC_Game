#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "graphics.h"

void Graphics::logErrorAndExit(const char* msg, const char* error){
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
    SDL_Quit();
}

void Graphics::init() {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
            logErrorAndExit("SDL_Init", SDL_GetError());

        window = SDL_CreateWindow("BATTLESPACE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 540, SDL_WINDOW_SHOWN);
        //full screen
        //window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
        if (window == nullptr) logErrorAndExit("CreateWindow", SDL_GetError());

        if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
            logErrorAndExit( "SDL_image error:", IMG_GetError());

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
        //Khi chạy trong máy ảo (ví dụ phòng máy ở trường)
        //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));

        if (renderer == nullptr) logErrorAndExit("CreateRenderer", SDL_GetError());

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
        SDL_RenderSetLogicalSize(renderer, 960, 540);

        //Initialize SDL_mixer
        if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
            logErrorAndExit( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        }
}

void Graphics::prepareScene(SDL_Texture * background){
    SDL_RenderClear(renderer);
    SDL_RenderCopy( renderer, background, NULL, NULL);
}

void Graphics::presentScene(){
    SDL_RenderPresent(renderer);
}

SDL_Texture* Graphics::loadTexture(const char *filename){
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

    SDL_Texture *texture = IMG_LoadTexture(renderer, filename);
    if (texture == NULL)
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load texture %s", IMG_GetError());

    return texture;
}

void Graphics::renderTexture(SDL_Texture *texture, int x, int y){
    SDL_Rect dest;

    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

    SDL_RenderCopy(renderer, texture, NULL, &dest);
}

void Graphics::blitRect(SDL_Texture *texture, SDL_Rect *src, int x, int y){
    SDL_Rect dest;

    dest.x = x;
    dest.y = y;
    dest.w = src->w;
    dest.h = src->h;

    SDL_RenderCopy(renderer, texture, src, &dest);
}

void Graphics::quit(){
        Mix_Quit();
        IMG_Quit();

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
}

Mix_Music* Graphics::loadMusic(const char* path){
    Mix_Music *gMusic = Mix_LoadMUS(path);
    if (gMusic == nullptr) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,"Could not load music! SDL_mixer Error: %s", Mix_GetError());
    }
    return gMusic;
}

void Graphics::play(Mix_Music *gMusic){
    if (gMusic == nullptr) return;

    if (Mix_PlayingMusic() == 0) {
        Mix_PlayMusic( gMusic, -1 );
    }
    else if( Mix_PausedMusic() == 1 ) {
        Mix_ResumeMusic();
    }
}

Mix_Chunk* Graphics::loadSound(const char* path) {
    Mix_Chunk* gChunk = Mix_LoadWAV(path);
    if (gChunk == nullptr) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,"Could not load sound! SDL_mixer Error: %s", Mix_GetError());
    }
}

void Graphics::play(Mix_Chunk* gChunk) {
    if (gChunk != nullptr) {
        Mix_PlayChannel( -1, gChunk, 0 );
    }
}

void Graphics::in5thuyen(ship tau1,ship tau2,ship tau3,ship tau4,ship tau5){

        renderTexture(tau1.tau,tau1.x,tau1.y);
        renderTexture(tau2.tau,tau2.x,tau2.y);
        renderTexture(tau3.tau,tau3.x,tau3.y);
        renderTexture(tau4.tau,tau4.x,tau4.y);
        renderTexture(tau5.tau,tau5.x,tau5.y);

        presentScene();
    }

void Graphics::xoaythuyen(ship &tau1) {
        if(abs(tau1.w-tau1.h)==32){
                 if(tau1.w == 64 ) {
                    tau1.tau = loadTexture("ship2doc.png");
                    swap(tau1.w,tau1.h);
                    tau1.pos = 1;
                    }
                 else {
                    tau1.tau = loadTexture("ship2ngang.png");
                    swap(tau1.w,tau1.h);
                    tau1.pos =0;
                    }
            }
            else if(abs(tau1.w-tau1.h)==64){
                if(tau1.w == 96 ) {
                    tau1.tau = loadTexture("ship3doc.png");
                    swap(tau1.w,tau1.h);
                    tau1.pos = 1;
                    }
                 else {
                    tau1.tau = loadTexture("ship3ngang.png");
                    swap(tau1.w,tau1.h);
                    tau1.pos = 0;
                    }
            }
            else if(abs(tau1.w-tau1.h)==96){
                if(tau1.w == 128 ) {
                    tau1.tau = loadTexture("ship4doc.png");
                    swap(tau1.w,tau1.h);
                    tau1.pos = 1;
                    }
                 else {
                    tau1.tau = loadTexture("ship4ngang.png");
                    swap(tau1.w,tau1.h);
                    tau1.pos = 0;
                    }
            }
             else if(abs(tau1.w-tau1.h)==128){
                if(tau1.w == 160 ) {
                    tau1.tau = loadTexture("ship5doc.png");
                    swap(tau1.w,tau1.h);
                    tau1.pos = 1;
                    }
                 else {
                    tau1.tau = loadTexture("ship5ngang.png");
                    swap(tau1.w,tau1.h);
                    tau1.pos = 0;
                    }
            }
    }

void Graphics::xepthuyen(ship &tau2,ship &tau31,ship &tau32,ship &tau4,ship &tau5,int &x, int &y, SDL_Event &e2,SDL_Texture* khay,SDL_Texture* PLAYSETUP) {
        if (e2.type == SDL_MOUSEBUTTONDOWN) {
                    int a = x;
                    int b = y;
                    int A[10] ={tau2.x,tau2.y,tau31.x,tau31.y,tau32.x,tau32.y,tau4.x,tau4.y,tau5.x,tau5.y};
                    if ((x >= tau2.x and x <= tau2.x + tau2.w) and (y >= tau2.y and y <= tau2.y + tau2.h)) {
                        while (true) {


                            SDL_GetMouseState(&x, &y);

                            tau2.x = A[0] + (x - a);
                            tau2.y = A[1] + (y - b);

                            prepareScene(PLAYSETUP);
                            renderTexture(khay, 631, 80);

                            in5thuyen(tau2,tau31,tau32,tau4,tau5);

                            SDL_PollEvent(&e2);
                            if (e2.type == SDL_MOUSEBUTTONUP) {

                            tau2.fix();

                            prepareScene(PLAYSETUP);
                            renderTexture(khay, 631, 80);

                            in5thuyen(tau2,tau31,tau32,tau4,tau5);

                            break;
                            }
                            else if (e2.type == SDL_KEYDOWN && e2.key.keysym.sym == SDLK_r) {

                                xoaythuyen(tau2);
                                tau2.fix();

                                prepareScene(PLAYSETUP);
                                renderTexture(khay, 631, 80);

                                in5thuyen(tau2,tau31,tau32,tau4,tau5);

                                break;
                            }
                        }
                    }
                    else if ((x >= tau31.x and x <= tau31.x + tau31.w) and (y >= tau31.y and y <= tau31.y + tau31.h)) {
                        while (true) {


                            SDL_GetMouseState(&x, &y);

                            tau31.x = A[2] + (x - a);
                            tau31.y = A[3] + (y - b);

                            prepareScene(PLAYSETUP);
                            renderTexture(khay, 631, 80);

                            in5thuyen(tau2,tau31,tau32,tau4,tau5);

                            SDL_PollEvent(&e2);
                            if (e2.type == SDL_MOUSEBUTTONUP) {

                            tau31.fix();

                            prepareScene(PLAYSETUP);
                            renderTexture(khay, 631, 80);

                            in5thuyen(tau2,tau31,tau32,tau4,tau5);

                            break;
                            }
                            else if (e2.type == SDL_KEYDOWN && e2.key.keysym.sym == SDLK_r) {

                                xoaythuyen(tau31);
                                tau31.fix();

                                prepareScene(PLAYSETUP);
                                renderTexture(khay, 631, 80);

                                in5thuyen(tau2,tau31,tau32,tau4,tau5);

                                break;
                            }
                        }
                    }
                    else if ((x >= tau32.x and x <= tau32.x + tau32.w) and (y >= tau32.y and y <= tau32.y + tau32.h)) {
                        while (true) {


                            SDL_GetMouseState(&x, &y);

                            tau32.x = A[4] + (x - a);
                            tau32.y = A[5] + (y - b);

                            prepareScene(PLAYSETUP);
                            renderTexture(khay, 631, 80);

                            in5thuyen(tau2,tau31,tau32,tau4,tau5);

                            SDL_PollEvent(&e2);
                            if (e2.type == SDL_MOUSEBUTTONUP) {

                                tau32.fix();

                                prepareScene(PLAYSETUP);
                                renderTexture(khay, 631, 80);

                                in5thuyen(tau2,tau31,tau32,tau4,tau5);

                            break;
                            }
                            else if (e2.type == SDL_KEYDOWN && e2.key.keysym.sym == SDLK_r) {

                                xoaythuyen(tau32);
                                tau32.fix();

                                prepareScene(PLAYSETUP);
                                renderTexture(khay, 631, 80);

                                in5thuyen(tau2,tau31,tau32,tau4,tau5);

                                break;
                            }
                        }
                    }
                    else if ((x >= tau4.x and x <= tau4.x + tau4.w) and (y >= tau4.y and y <= tau4.y + tau4.h)) {
                        while (true) {


                            SDL_GetMouseState(&x, &y);

                            tau4.x = A[6] + (x - a);
                            tau4.y = A[7] + (y - b);

                            prepareScene(PLAYSETUP);
                            renderTexture(khay, 631, 80);

                            in5thuyen(tau2,tau31,tau32,tau4,tau5);

                            SDL_PollEvent(&e2);
                            if (e2.type == SDL_MOUSEBUTTONUP) {

                                tau4.fix();

                                prepareScene(PLAYSETUP);
                                renderTexture(khay, 631, 80);

                                in5thuyen(tau2,tau31,tau32,tau4,tau5);

                            break;
                            }
                            else if (e2.type == SDL_KEYDOWN && e2.key.keysym.sym == SDLK_r) {

                                xoaythuyen(tau4);
                                tau4.fix();

                                prepareScene(PLAYSETUP);
                                renderTexture(khay, 631, 80);

                                in5thuyen(tau2,tau31,tau32,tau4,tau5);

                                break;
                            }
                        }
                    }
                    else if ((x >= tau5.x and x <= tau5.x + tau5.w) and (y >= tau5.y and y <= tau5.y + tau5.h)) {
                        while (true) {


                            SDL_GetMouseState(&x, &y);

                            tau5.x = A[8] + (x - a);
                            tau5.y = A[9] + (y - b);

                            prepareScene(PLAYSETUP);
                            renderTexture(khay, 631, 80);

                            in5thuyen(tau2,tau31,tau32,tau4,tau5);

                            SDL_PollEvent(&e2);
                            if (e2.type == SDL_MOUSEBUTTONUP) {

                                tau5.fix();

                                prepareScene(PLAYSETUP);
                                renderTexture(khay, 631, 80);

                                in5thuyen(tau2,tau31,tau32,tau4,tau5);

                            break;
                            }
                            else if (e2.type == SDL_KEYDOWN && e2.key.keysym.sym == SDLK_r) {

                                xoaythuyen(tau5);
                                tau5.fix();

                                prepareScene(PLAYSETUP);
                                renderTexture(khay, 631, 80);

                                in5thuyen(tau2,tau31,tau32,tau4,tau5);

                                break;
                            }
                        }
                    }
                }
    }

void Graphics::thuyenbiphahuy(SDL_Texture* &tau2,SDL_Texture* &tau31,SDL_Texture* &tau32,SDL_Texture* &tau4,
                     SDL_Texture* &tau5,int pos2, int pos31, int pos32, int pos4, int pos5 , int k) {

        if(pos2 == k)  tau2 = loadTexture("ship2destroydoc.png");
        else  tau2 = loadTexture("ship2destroyngang.png");
        if(pos31 == k)  tau31 = loadTexture("ship3destroydoc.png");
        else  tau31 = loadTexture("ship3destroyngang.png");
        if(pos32 == k)  tau32 = loadTexture("ship3destroydoc.png");
        else tau32 = loadTexture("ship3destroyngang.png");
        if(pos4 == k) tau4 = loadTexture("ship4destroydoc.png");
        else tau4 = loadTexture("ship4destroyngang.png");
        if(pos5 == k) tau5 = loadTexture("ship5destroydoc.png");
        else tau5 = loadTexture("ship5destroyngang.png");
    }
