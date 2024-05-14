#ifndef DEFS_H_INCLUDED
#define DEFS_H_INCLUDED

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "ship.h"

using namespace std;

const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 540;

extern int mauthuyen2enemy,mauthuyen31enemy,mauthuyen32enemy,mauthuyen4enemy,mauthuyen5enemy;

extern bool song[5]  ;

extern int P[11][11];
extern int E[11][11];

extern ship tau2;
extern ship tau31;
extern ship tau32;
extern ship tau4;
extern ship tau5;

extern SDL_Texture* enemytau2;
extern SDL_Texture* enemytau31;
extern SDL_Texture* enemytau32;
extern SDL_Texture* enemytau4;
extern SDL_Texture* enemytau5;

vector<int> Computer() ;

extern vector<int> C ;
extern vector<int> ES ;


void waitUntilKeyPressed() ;

#define WINDOW_TITLE "BattleSpace"

#endif // DEFS_H_INCLUDED
