#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "ship.h"

ship::ship() {
    w = 0;
    h = 0;
    x = 0;
    y = 0;
    pos = 0;
    live =0;
}

ship::ship( int _w , int _h , int _x , int _y , int _pos  , int _live ) {
    w = _w;
    h = _h;
    x = _x;
    y = _y;
    pos = _pos;
    live =_live;
}

void ship::fix() {
    x = 66+35.3*((x-65)/35);
    if ( x +w > 414) x = 414 - w ;
    else if (x < 66) x = 66 ;
    y = 88+35.4*((y-88)/35);
    if ( y + h >437) y = 437-h ;
    else if ( y < 88) y =88;
}
