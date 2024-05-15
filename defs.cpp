#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "ship.h"
#include "defs.h"

using namespace std;

int mauthuyen2enemy =2,mauthuyen31enemy = 3, mauthuyen32enemy = 3, mauthuyen4enemy = 4, mauthuyen5enemy = 5;

bool song[5] = {true,true,true,true,true} ;

Mix_Chunk *bantrung ;
Mix_Chunk *banxit ;
int thangthua =1;

int P[12][12] = {0};
int E[12][12] = {0};

ship tau2(64,32,644,390,0,2);
ship tau31(96,32,644,318,0,3);
ship tau32(96,32,644,246,0,3);
ship tau4(128,32,644,177,0,4);
ship tau5(160,32,644,103,0,5);

SDL_Texture* enemytau2;
SDL_Texture* enemytau31;
SDL_Texture* enemytau32;
SDL_Texture* enemytau4;
SDL_Texture* enemytau5;

vector<int> Computer() {

    vector<int> C;
    int x, y, pos;

    srand(time(0));

    for ( int i = 1; i <= 5; i++ ) {

        x= 1 + (rand() % 10);
        y= 1 + (rand() % 10);
        pos = rand() % 2;

        bool r = false;

        while(true) {
            if (E[x][y] == 0) break;
            else {
			srand((unsigned int)time(NULL));

			x = 1 + (rand() % 10);
			y = 1 + (rand() % 10);
            pos = rand() % 2;
			}
		}
		while (true) {
			if(pos==0) {
				if (i==1) {
					if(x<7) {
						if(E[x+1][y] == 0 and E[x+2][y] == 0 and E[x+3][y] == 0 and E[x+4][y] == 0) {

							E[x][y] = 5;
							E[x+1][y] = 5;
							E[x+2][y] = 5;
							E[x+3][y] = 5;
							E[x+4][y] = 5;

							C.push_back(x);
							C.push_back(y);
							C.push_back(pos);

							break;
						}
						else {
							r = true;
						}
					}
					else {
						r = true;
					}
				}
				else if(i == 2) {
					if(x  < 8) {
						if(E[x+1][y] == 0 and E[x+2][y] == 0 and E[x+3][y] == 0) {

							E[x][y] = 4;
							E[x+1][y] = 4;
							E[x+2][y] = 4;
							E[x+3][y] = 4;

							C.push_back(x);
							C.push_back(y);
							C.push_back(pos);

							break;
						}
						else {
							r = true;
						}
					}
					else {
						r = true;
					}
				}
				else if(i == 3) {
					if(x < 9) {
						if(E[x+1][y] == 0 and E[x+2][y] == 0) {

							E[x][y] = 32;
							E[x+1][y] = 32;
							E[x+2][y] = 32;

							C.push_back(x);
							C.push_back(y);
							C.push_back(pos);

							break;
						}
						else {
							r = true;
						}
					}
					else {
						r = true;
					}
				}
				else if(i == 4) {
					if(x < 9) {
						if(E[x+1][y] == 0 and E[x+2][y] == 0) {

							E[x][y] = 31;
							E[x+1][y] = 31;
							E[x+2][y] = 31;

							C.push_back(x);
							C.push_back(y);
							C.push_back(pos);

							break;
						}
						else {
							r = true;
						}
					}
					else {
						r = true;
					}
				}
				else if(i == 5) {
					if(x < 10) {
						if(E[x+1][y] == 0) {

                            E[x][y] = 2;
							E[x+1][y] = 2;

							C.push_back(x);
							C.push_back(y);
							C.push_back(pos);

							break;
						}
						else {
							r = true;
						}
					}
					else {
						r = true;
					}
				}
			}
			else if(pos == 1) {
				if(i == 1) {
					if(y < 7) {
						if(E[x][y+1] == 0 and E[x][y+2] == 0 and E[x][y+3] == 0 and E[x][y+4] == 0) {

							E[x][y] = 5;
							E[x][y+1] = 5;
							E[x][y+2] = 5;
							E[x][y+3] = 5;
							E[x][y+4] = 5;

							C.push_back(x);
							C.push_back(y);
							C.push_back(pos);

							break;
						}
						else {
							r = true;
						}
					}
					else {
						r = true;
					}
				}
				else if(i == 2) {
                    if(y < 8) {
						if(E[x][y+1] == 0 and E[x][y+2] == 0 and E[x][y+3] == 0) {

							E[x][y] = 4;
							E[x][y+1] = 4;
							E[x][y+2] = 4;
                            E[x][y+3] = 4;

							C.push_back(x);
							C.push_back(y);
							C.push_back(pos);

							break;
						}
						else {
							r = true;
						}
					}
					else {
						r = true;
					}
				}
				else if(i == 3) {
					if(y < 9) {
						if(E[x][y+1] == 0 and E[x][y+2] == 0) {

							E[x][y] = 32;
							E[x][y+1] = 32;
							E[x][y+2] = 32;

							C.push_back(x);
							C.push_back(y);
							C.push_back(pos);

							break;
						}
						else {
							r = true;
						}
					}
					else {
						r = true;
					}
				}
				else if(i == 4) {
					if(y < 9) {
						if(E[x][y+1] == 0 and E[x][y+2] == 0) {

							E[x][y] = 31;
							E[x][y+1] = 31;
							E[x][y+2] = 31;

							C.push_back(x);
							C.push_back(y);
							C.push_back(pos);

							break;
						}
						else {
							r = true;
						}
					}
					else {
						r = true;
					}
				}
				else if(i == 5) {
					if(y < 10) {
						if (E[x][y+1] == 0) {

							E[x][y] = 2;
							E[x][y+1] = 2;

							C.push_back(x);
							C.push_back(y);
							C.push_back(pos);

							break;
						}
						else {
							r = true;
						}
					}
					else {
						r = true;
					}
				}
			}


				if (r) {
					srand((unsigned int)time(NULL));

					x = 1 + (rand() % 10);
					y = 1 + (rand() % 10);
                    pos = rand() % 2;
					}
        }
    }
    return C;
}

void waitUntilKeyPressed() {
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}

vector<int> C = Computer();
vector<int> ES ;

void reset() {
    mauthuyen2enemy =2;
    mauthuyen31enemy = 3;
    mauthuyen32enemy = 3;
    mauthuyen4enemy = 4;
    mauthuyen5enemy = 5;

    thangthua =1;
    fill(song,song+5,true);

    for(int i =1;i<=10;i++) {
        for(int j =1 ;j<=10;j++) {
            P[i][j]=0;
        }
    }

    for(int i =1;i<=10;i++) {
        for(int j =1 ;j<=10;j++) {
            E[i][j]=0;
        }
    }

    tau2.update(64,32,644,390,0,2);
    tau31.update(96,32,644,318,0,3);
    tau32.update(96,32,644,246,0,3);
    tau4.update(128,32,644,177,0,4);
    tau5.update(160,32,644,103,0,5);

    C.clear();
    ES.clear();

    C=Computer();
}
