#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED

#include "ship.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>


struct Graphics {
    SDL_Renderer *renderer;
	SDL_Window *window;

	void logErrorAndExit(const char* msg, const char* error);

	void init() ;

	void prepareScene(SDL_Texture * background);

    void presentScene();

    SDL_Texture *loadTexture(const char *filename);

    void renderTexture(SDL_Texture *texture, int x, int y);

    void blitRect(SDL_Texture *texture, SDL_Rect *src, int x, int y);

    void quit();

    Mix_Music *loadMusic(const char* path);

    void play(Mix_Music *gMusic) ;

    Mix_Chunk* loadSound(const char* path);

    void play(Mix_Chunk* gChunk);

    void in5thuyen(ship tau1,ship tau2,ship tau3,ship tau4,ship tau5) ;

    void xoaythuyen(ship &tau1);

    void xepthuyen(ship &tau2,ship &tau31,ship &tau32,ship &tau4,ship &tau5,int &x, int &y, SDL_Event &e2,SDL_Texture* khay,SDL_Texture* PLAYSETUP);

    void thuyenbiphahuy(SDL_Texture* &tau2,SDL_Texture* &tau31,SDL_Texture* &tau32,SDL_Texture* &tau4,
                     SDL_Texture* &tau5,int pos2, int pos31, int pos32, int pos4, int pos5,int k) ;
};


#endif // GRAPHICS_H_INCLUDED
