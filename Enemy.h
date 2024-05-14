#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "defs.h"
#include "ship.h"
#include "graphics.h"

using namespace std;

void updateES(int x,int y);

void EnemyShooting(Graphics graphics,SDL_Texture* dando,SDL_Texture* dantrang);

void Enemycheck(Graphics graphics);

#endif // ENEMY_H_INCLUDED
