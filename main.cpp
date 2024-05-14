#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "defs.h"
#include "ship.h"
#include "graphics.h"
#include "player.h"
#include "Enemy.h"

using namespace std;


int main(int argc, char *argv[])
{
    srand(time(0));

    Graphics graphics;
    graphics.init();

    SDL_Texture* MENU = graphics.loadTexture("MENU.png");
    graphics.prepareScene(MENU);

    graphics.presentScene();

    SDL_Event event;
    int x, y;
    while (true) {
        SDL_GetMouseState(&x, &y);

        SDL_PollEvent(&event);

        if ( event.type==SDL_MOUSEBUTTONUP ) {

            if ( ( x >= 367 and x <= 573 ) and ( y >= 446 and y <= 526 ) ) {

                graphics.quit();

            }
            else if( ( x >= 367 and x <= 573 ) and ( y >= 357 and y <= 434 ) ) {

                 SDL_Texture* HELP = graphics.loadTexture("HELP.png");
                 graphics.prepareScene(HELP);
                 graphics.presentScene();

            }
            else if( ( x >= 367 and x <= 573 ) and ( y >= 267 and y <= 348 ) ) {

                SDL_Texture* PLAYSETUP = graphics.loadTexture("Setup11.png");
                graphics.prepareScene(PLAYSETUP);

                SDL_Texture* khay = graphics.loadTexture("khay.png");
                graphics.renderTexture(khay, 631, 80);

                tau2.tau = graphics.loadTexture("ship2ngang.png");
                tau31.tau = graphics.loadTexture("ship3ngang.png");
                tau32.tau = graphics.loadTexture("ship3ngang.png");
                tau4.tau = graphics.loadTexture("ship4ngang.png");
                tau5.tau = graphics.loadTexture("ship5ngang.png");

                graphics.in5thuyen(tau2,tau31,tau32,tau4,tau5);

                SDL_Event e2;

                while (true) {
                    SDL_GetMouseState(&x, &y);
                    SDL_PollEvent(&e2);

                    graphics.xepthuyen(tau2,tau31,tau32,tau4,tau5,x,y,e2,khay,PLAYSETUP);

                    if (e2.type == SDL_MOUSEBUTTONDOWN) {
                        if((x >=  861 and x<= 918) and (y >= 456 and y <= 513)) {

                            PLAYSETUP = graphics.loadTexture("Play.png");
                            graphics.prepareScene(PLAYSETUP);
                            graphics.in5thuyen(tau2,tau31,tau32,tau4,tau5);

                            SDL_Texture* dando = graphics.loadTexture("dando.png");
                            SDL_Texture* dantrang = graphics.loadTexture("dantrang.png");

                            setup5(tau2,tau31,tau32,tau4,tau5);

                            graphics.thuyenbiphahuy(tau2.tau,tau31.tau,tau32.tau,tau4.tau,tau5.tau,
                                                    tau2.pos,tau31.pos,tau32.pos,tau4.pos,tau5.pos,1);

                            graphics.thuyenbiphahuy(enemytau2,enemytau31,enemytau32,enemytau4,enemytau5,
                                                    C[14],C[11],C[8],C[5],C[2],0);


                            while(true) {

                                SDL_GetMouseState(&x, &y);
                                SDL_PollEvent(&e2);

                                if(e2.type == SDL_MOUSEBUTTONDOWN) {

                                    PlayerShooting(graphics,x,y,dando,dantrang);
                                    Playercheck(graphics,enemytau2,enemytau31,enemytau32,enemytau4,enemytau5);
                                    EnemyShooting( graphics, dando, dantrang);
                                    Enemycheck(graphics);

                                }
                            }
                        }
                    }
                }
            }
            if(event.type==SDL_MOUSEBUTTONUP){
                    if((x>=25 and x<=81) and (y>=32 and y<=88)){

                        graphics.prepareScene(MENU);
                        graphics.presentScene();

                    }
                }
            }
        SDL_Delay(100);
    }
    graphics.quit();
    return 0;
}

