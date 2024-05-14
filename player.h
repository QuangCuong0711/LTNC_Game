#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "defs.h"
#include "ship.h"
#include "graphics.h"

using namespace std;

void setup (ship tau1, int n) ;

void setup5 (ship tau2, ship tau31, ship tau32, ship tau4, ship tau5) ;

void Playercheck(Graphics graphics , SDL_Texture* enemytau2,SDL_Texture* enemytau31,
                 SDL_Texture* enemytau32,SDL_Texture* enemytau4,SDL_Texture* enemytau5);

void PlayerShooting(Graphics graphics,int x , int y,SDL_Texture* dando,SDL_Texture* dantrang);

#endif // PLAYER_H_INCLUDED
