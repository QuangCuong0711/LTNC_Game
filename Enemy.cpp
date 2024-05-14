#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "defs.h"
#include "ship.h"
#include "graphics.h"
#include "Enemy.h"

using namespace std;

void updateES(int x,int y){
    if (ES.empty()) {
        if (y - 1 >= 1) {
            if ( P[x][y-1] == 0) {

                ES.push_back(x);
                ES.push_back(y - 1);

            }
            else if (P[x][y-1] == 2 or P[x][y-1] == 31 or P[x][y-1] == 32 or P[x][y-1] == 4 or P[x][y-1] == 5) {
                ES.push_back(x);
                ES.push_back(y - 1);

                if (y - 2 >= 1) {
                    if (P[x][y-2] == 0) {

                        ES.push_back(x);
                        ES.push_back(y - 2);

                    }
                    else if (P[x][y-2] == 2 or P[x][y-2] == 31 or P[x][y-2] == 32 or P[x][y-2] == 4 or P[x][y-2] == 5) {
                        ES.push_back(x);
                        ES.push_back(y - 2);

                        if (y - 3 >= 1) {
                            if (P[x][y-3] == 0) {

                                ES.push_back(x);
                                ES.push_back(y - 3);

                            }
                            else if (P[x][y-3] == 2 or P[x][y-3] == 31 or P[x][y-3] == 32 or P[x][y-3] == 4 or P[x][y-3] == 5) {
                                ES.push_back(x);
                                ES.push_back(y - 3);

                                if(y - 4 >= 1) {
                                    if (P[x][y-4] == 0) {
                                        ES.push_back(x);
                                        ES.push_back(y - 4);
                                    }
                                    else if (P[x][y-4] == 2 or P[x][y-4] == 31 or P[x][y-4] == 32 or P[x][y-4] == 4 or P[x][y-4] == 5) {
                                        ES.push_back(x);
                                        ES.push_back(y - 4);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (y + 1 <= 10) {
            if (P[x][y + 1] == 0) {
                ES.push_back(x);
                ES.push_back(y + 1);
            }
            else if (P[x][y+1] == 2 or P[x][y+1] == 31 or P[x][y+1] == 32 or P[x][y+1] == 4 or P[x][y+1] == 5) {
                ES.push_back(x);
                ES.push_back(y + 1);

                if (y + 2 <= 10) {
                    if (P[x][y + 2] == 0) {
                        ES.push_back(x);
                        ES.push_back(y + 2);
                    }
                    else if (P[x][y+2] == 2 or P[x][y+2] == 31 or P[x][y+2] == 32 or P[x][y+2] == 4 or P[x][y+2] == 5) {
                        ES.push_back(x);
                        ES.push_back(y + 2);

                        if (y + 3 <= 10) {
                            if (P[x][y + 3] == 0) {
                                ES.push_back(x);
                                ES.push_back(y + 3);
                            }
                            else if (P[x][y+3] == 2 or P[x][y+3] == 31 or P[x][y+3] == 32 or P[x][y+3] == 4 or P[x][y+3] == 5) {
                                ES.push_back(x);
                                ES.push_back(y + 3);

                                if(y + 4 <= 10) {
                                    if (P[x][y + 4] == 0) {
                                        ES.push_back(x);
                                        ES.push_back(y + 4);
                                    }
                                    else if (P[x][y+4] == 2 or P[x][y+4] == 31 or P[x][y+4] == 32 or P[x][y+4] == 4 or P[x][y+4] == 5) {
                                        ES.push_back(x);
                                        ES.push_back(y + 4);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (x - 1 >= 1) {
            if (P[x - 1][y] == 0) {
                ES.push_back(x - 1);
                ES.push_back(y);
            }
            else if (P[x-1][y] == 2 or P[x-1][y] == 31 or P[x-1][y] == 32 or P[x-1][y] == 4 or P[x-1][y] == 5) {
                ES.push_back(x - 1);
                ES.push_back(y);

                if (x - 2 >= 1) {
                    if (P[x - 2][y] == 0) {
                        ES.push_back(x - 2);
                        ES.push_back(y);
                    }
                    else if (P[x-2][y] == 2 or P[x-2][y] == 31 or P[x-2][y] == 32 or P[x-2][y] == 4 or P[x-2][y] == 5) {
                        ES.push_back(x - 2);
                        ES.push_back(y);

                        if (x - 3 >= 1) {
                            if (P[x - 3][y] == 0) {
                                ES.push_back(x - 3);
                                ES.push_back(y);
                            }
                            else if (P[x-3][y] == 2 or P[x-3][y] == 31 or P[x-3][y] == 32 or P[x-3][y] == 4 or P[x-3][y] == 5) {
                                ES.push_back(x - 3);
                                ES.push_back(y);

                                if(x - 4 >= 1) {
                                    if (P[x - 4][y] == 0) {
                                        ES.push_back(x - 4);
                                        ES.push_back(y);
                                    }
                                    else if (P[x-4][y] == 2 or P[x-4][y] == 31 or P[x-4][y] == 32 or P[x-4][y] == 4 or P[x-4][y] == 5) {
                                        ES.push_back(x - 4);
                                        ES.push_back(y);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (x + 1 <= 10) {
            if (P[x + 1][y] == 0) {
                ES.push_back(x + 1);
                ES.push_back(y);
            }
            else if (P[x+1][y] == 2 or P[x+1][y] == 31 or P[x+1][y] == 32 or P[x+1][y] == 4 or P[x+1][y] == 5) {
                ES.push_back(x + 1);
                ES.push_back(y);

                if (x + 2 <= 10) {
                    if (P[x + 2][y] == 0) {
                        ES.push_back(x + 2);
                        ES.push_back(y);
                    }
                    else if (P[x+2][y] == 2 or P[x+2][y] == 31 or P[x+2][y] == 32 or P[x+2][y] == 4 or P[x+2][y] == 5) {
                        ES.push_back(x + 2);
                        ES.push_back(y);

                        if (x + 3 <= 10) {
                            if (P[x + 3][y] == 0) {
                                ES.push_back(x+3);
                                ES.push_back(y);
                            }
                            else if (P[x+3][y] == 2 or P[x+3][y] == 31 or P[x+3][y] == 32 or P[x+3][y] == 4 or P[x+3][y] == 5) {
                                ES.push_back(x + 3);
                                ES.push_back(y);

                                if(x + 4 <= 10) {
                                    if (P[x + 4][y] == 0) {
                                        ES.push_back(x + 4);
                                        ES.push_back(y);
                                    }
                                    else if (P[x+4][y] == 2 or P[x+4][y] == 31 or P[x+4][y] == 32 or P[x+4][y] == 4 or P[x+4][y] == 5) {
                                        ES.push_back(x + 4);
                                        ES.push_back(y);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void EnemyShooting(Graphics graphics,SDL_Texture* dando,SDL_Texture* dantrang) {
        SDL_Delay(1000);
        int a, b,n=1;
        if(!ES.empty()) {
            a =  ES.front();
            ES.erase(ES.begin());
            b = ES.front();
            ES.erase(ES.begin());
        }
        else {
            a = 1+(rand()%10);
            b = 1+(rand()%10);
        }


        bool check = true;

        while(check) {
            if(P[a][b] == 3 or P[a][b] == 1) {
                a = 1+(rand()%10);
                b = 1+(rand()%10);
            }
            else check = false;
        }

        if(P[a][b] == 0) {
            P[a][b] = 3;
            b = ( ( b - 1 ) * 35.3 + 66);
            a = ( ( a - 1 ) * 35.4 + 89);
            graphics.renderTexture(dantrang,b,a);
            graphics.presentScene();
            n=0;
        }
        else if ( P[a][b] == 2 ) {
            P[a][b] = 1;
            updateES(a,b);
            b = ( ( b - 1 ) * 35.3 + 66);
            a = ( ( a - 1 ) * 35.4 + 89);
            tau2.live--;
            graphics.renderTexture(dando,b,a);
            graphics.presentScene();
            Enemycheck(graphics);
        }
        else if ( P[a][b] == 31 ) {
            updateES(a,b);
            P[a][b] = 1;
            b = ( ( b - 1 ) * 35.3 + 66);
            a = ( ( a - 1 ) * 35.4 + 89);
            tau31.live--;
            graphics.renderTexture(dando,b,a);
            graphics.presentScene();
            Enemycheck(graphics);
        }
        else if ( P[a][b] == 32 ) {
            updateES(a,b);
            P[a][b] = 1;
            b = ( ( b - 1 ) * 35.3 + 66);
            a = ( ( a - 1 ) * 35.4 + 89);
            tau32.live--;
            graphics.renderTexture(dando,b,a);
            graphics.presentScene();
            Enemycheck(graphics);
        }
        else if ( P[a][b] == 4 ) {
            updateES(a,b);
            P[a][b] = 1;
            b = ( ( b - 1 ) * 35.3 + 66);
            a = ( ( a - 1 ) * 35.4 + 89);
            tau4.live--;
            graphics.renderTexture(dando,b,a);
            graphics.presentScene();
            Enemycheck(graphics);
        }
        else if ( P[a][b] == 5 ) {
            updateES(a,b);
            P[a][b] = 1;
            b = ( ( b - 1 ) * 35.3 + 66);
            a = ( ( a - 1 ) * 35.4 + 89);
            tau5.live--;
            graphics.renderTexture(dando,b,a);
            graphics.presentScene();
            Enemycheck(graphics);
        }
    if(n) {
            EnemyShooting(graphics,dando,dantrang);
    }
}
void Enemycheck(Graphics graphics){
    if(song[0]){
        if ( tau2.live == 0) {
            graphics.renderTexture(tau2.tau,tau2.x ,tau2.y );
            graphics.presentScene();
            song[0] = false;
            ES.clear();
        }
    }
    if(song[1]){
        if ( tau31.live == 0) {
            graphics.renderTexture(tau31.tau,tau31.x ,tau31.y );
            graphics.presentScene();
            song[1] = false;
            ES.clear();
        }
    }
    if(song[2]){
        if ( tau32.live == 0) {
            graphics.renderTexture(tau32.tau,tau32.x ,tau32.y );
            graphics.presentScene();
            song[2] = false;
            ES.clear();
        }
    }
    if(song[3]){
        if ( tau4.live == 0) {
            graphics.renderTexture(tau4.tau,tau4.x ,tau4.y );
            graphics.presentScene();
            song[3] = false;
            ES.clear();
        }
    }
    if(song[4]){
        if ( tau5.live == 0) {
            graphics.renderTexture(tau5.tau,tau5.x ,tau5.y );
            graphics.presentScene();
            song[4] = false;
            ES.clear();
        }
    }
    if(tau2.live == 0 and tau31.live == 0 and tau32.live == 0 and tau4.live == 0 and tau5.live == 0)  {

        graphics.quit();

    }
}
