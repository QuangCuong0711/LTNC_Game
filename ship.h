#ifndef SHIP_H_INCLUDED
#define SHIP_H_INCLUDED

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>


using namespace std;

struct ship {
    public:

        int w,h,x,y,pos,live;

        SDL_Texture* tau;

        ship();

        ship(int _w = 0, int _h = 0, int _x = 0, int _y = 0, int _pos =0 , int _live = 0) ;

        void fix() ;

        void update(int _w , int _h , int _x , int _y , int _pos  , int _live);

};


#endif // SHIP_H_INCLUDED
