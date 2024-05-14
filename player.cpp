#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "defs.h"
#include "ship.h"
#include "graphics.h"
#include "player.h"

void setup (ship tau1, int n) {

    int b = round((tau1.x-66)/35.3 + 1);
    int a = round((tau1.y-88)/35.4 + 1);

    if(abs(tau1.w-tau1.h)==32){
        if(tau1.pos == 0) {
            P[a][b] = n;
            P[a][b+1] = n;
        }
        else {
            P[a][b] = n;
            P[a+1][b] = n;
        }
    }
    else if(abs(tau1.w-tau1.h)==64){
         if(tau1.pos == 0) {
            P[a][b] = n;
            P[a][b+1] = n;
            P[a][b+2] = n;
        }
        else {
            P[a][b] = n;
            P[a+1][b] = n;
            P[a+2][b] = n;
        }
    }
    else if(abs(tau1.w-tau1.h)==96){
         if(tau1.pos == 0) {
            P[a][b] = n;
            P[a][b+1] = n;
            P[a][b+2] = n;
            P[a][b+3] = n;
        }
        else {
            P[a][b] = n;
            P[a+1][b] = n;
            P[a+2][b] = n;
            P[a+3][b] = n;
        }
    }
    else if(abs(tau1.w-tau1.h)==128){
         if(tau1.pos == 0) {
            P[a][b] = n;
            P[a][b+1] = n;
            P[a][b+2] = n;
            P[a][b+3] = n;
            P[a][b+4] = n;
        }
        else {
            P[a][b] = n;
            P[a+1][b] = n;
            P[a+2][b] = n;
            P[a+3][b] = n;
            P[a+4][b] = n;
        }
    }
}

void setup5 (ship tau2, ship tau31, ship tau32, ship tau4, ship tau5) {
    setup(tau2,2);
    setup(tau31,31);
    setup(tau32,32);
    setup(tau4,4);
    setup(tau5,5);
}

void PlayerShooting(Graphics graphics,int x , int y,SDL_Texture* dando,SDL_Texture* dantrang) {

    int n = 1;
    int b = ((x-546)/35.3 + 1);
    int a = ((y-89)/35.4 + 1);
    if ((x>=546 and x <= 900) and (y>=89 and y<=444)){
        if(E[a][b] == 0) {
            E[a][b] = 3;
            b = ((b-1)*35.3+546);
            a = ((a-1)*35.4 + 89);
            graphics.renderTexture(dantrang,b,a);
            graphics.presentScene();
            n=0;
        }
        else if (E[a][b] == 1 ){
            SDL_Event k;
            SDL_PollEvent(&k);

            bool check1 =true;
            while (check1) {
                SDL_PollEvent(&k);
                SDL_GetMouseState(&x, &y);
                if( k.type == SDL_MOUSEBUTTONDOWN) {
                    PlayerShooting( graphics, x , y,dando,dantrang);
                    check1 = false;
                    n=0;
                }
            }

        }
        else if (E[a][b] == 3 ){
            SDL_Event k;
            SDL_PollEvent(&k);

            bool check1 =true;
            while (check1) {
                SDL_PollEvent(&k);
                SDL_GetMouseState(&x, &y);
                if( k.type == SDL_MOUSEBUTTONDOWN) {
                    PlayerShooting( graphics, x , y,dando,dantrang);
                    check1 = false;
                    n=0;
                }
            }
        }
        else if ( E[a][b] == 2 ) {
            E[a][b] = 1;
            b = ((b-1)*35.3+546);
            a = ((a-1)*35.4 + 89);
            mauthuyen2enemy--;
            graphics.renderTexture(dando,b,a);
            graphics.presentScene();
            Playercheck(graphics,enemytau2,enemytau31,enemytau32,enemytau4,enemytau5);
        }
        else if ( E[a][b] == 31 ) {
            E[a][b] = 1;
            b = ((b-1)*35.3+546);
            a = ((a-1)*35.4 + 89);
            mauthuyen31enemy--;
            graphics.renderTexture(dando,b,a);
            graphics.presentScene();
            Playercheck(graphics,enemytau2,enemytau31,enemytau32,enemytau4,enemytau5);
        }
        else if ( E[a][b] == 32 ) {
            E[a][b] = 1;
            b = ((b-1)*35.3+546);
            a = ((a-1)*35.4 + 89);
            mauthuyen32enemy--;
            graphics.renderTexture(dando,b,a);
            graphics.presentScene();
            Playercheck(graphics,enemytau2,enemytau31,enemytau32,enemytau4,enemytau5);
        }
        else if ( E[a][b] == 4 ) {
            E[a][b] = 1;
            b = ((b-1)*35.3+546);
            a = ((a-1)*35.4 + 89);
            mauthuyen4enemy--;
            graphics.renderTexture(dando,b,a);
            graphics.presentScene();
            Playercheck(graphics,enemytau2,enemytau31,enemytau32,enemytau4,enemytau5);
        }
        else if ( E[a][b] == 5 ) {
            E[a][b] = 1;
            b = ((b-1)*35.3+546);
            a = ((a-1)*35.4 + 89);
            mauthuyen5enemy--;
            graphics.renderTexture(dando,b,a);
            graphics.presentScene();
            Playercheck(graphics,enemytau2,enemytau31,enemytau32,enemytau4,enemytau5);
        }
    }
    else {
            SDL_Event k;
            SDL_PollEvent(&k);

            bool check1 =true;
            while (check1) {
                SDL_PollEvent(&k);
                SDL_GetMouseState(&x, &y);
                if( k.type == SDL_MOUSEBUTTONDOWN) {
                    PlayerShooting( graphics, x , y,dando,dantrang);
                    check1 = false;
                }
            }
    }
    if(n==1) {
            SDL_Event k;
            SDL_PollEvent(&k);

            bool check1 =true;
            while (check1) {
                SDL_PollEvent(&k);
                SDL_GetMouseState(&x, &y);
                if( k.type == SDL_MOUSEBUTTONDOWN) {
                    PlayerShooting( graphics, x , y,dando,dantrang);
                    check1 = false;
                }
            }
    }

}

void Playercheck(Graphics graphics , SDL_Texture* enemytau2,SDL_Texture* enemytau31,SDL_Texture* enemytau32,SDL_Texture* enemytau4,SDL_Texture* enemytau5) {
    if ( mauthuyen2enemy == 0) {
        graphics.renderTexture(enemytau2, 546 + 35.3*(C[13]-1), 89 + 35.5*(C[12]-1));
        graphics.presentScene();
    }
    if ( mauthuyen31enemy == 0) {
        graphics.renderTexture(enemytau31, 546 + 35.3*(C[10]-1), 89 + 35.5*(C[9]-1));
        graphics.presentScene();
    }
    if ( mauthuyen32enemy == 0) {
        graphics.renderTexture(enemytau32, 546 + 35.3*(C[7]-1), 89 + 35.5*(C[6]-1));
        graphics.presentScene();
    }
    if ( mauthuyen4enemy == 0) {
        graphics.renderTexture(enemytau4, 546 + 35.3*(C[4]-1), 89 + 35.5*(C[3]-1));
        graphics.presentScene();
    }
    if ( mauthuyen5enemy == 0) {
        graphics.renderTexture(enemytau5, 546 + 35.3*(C[1]-1), 89 + 35.5*(C[0]-1));
        graphics.presentScene();
    }
    if(mauthuyen2enemy == 0 and mauthuyen31enemy == 0 and mauthuyen32enemy == 0 and mauthuyen4enemy == 0 and  mauthuyen5enemy == 0)  {
        graphics.quit();
    }
}
