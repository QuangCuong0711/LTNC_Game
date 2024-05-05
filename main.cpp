#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "defs.h"

using namespace std;

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}
/*
int madfgdgin(int argc, char *argv[])
{
    SDL_Window* window = initSDL(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SDL_Renderer* renderer = createRenderer(window);

    SDL_Texture* background = loadTexture("bikiniBottom.jpg", renderer);
    SDL_RenderCopy( renderer, background, NULL, NULL);

    SDL_RenderPresent( renderer );
    waitUntilKeyPressed();

    SDL_Texture* spongeBob = loadTexture("Spongebob.png", renderer);
    renderTexture(spongeBob, 200, 200, renderer);

    SDL_RenderPresent( renderer );
    waitUntilKeyPressed();

    SDL_DestroyTexture( spongeBob );
    spongeBob = NULL;
    SDL_DestroyTexture( background );
    background = NULL;

    quitSDL(window, renderer);
    return 0;
}*/

/*int main(int argc, char *argv[])
{
    Graphics graphics;
    graphics.init();

    SDL_Texture* background = graphics.loadTexture("MENU.png");
    graphics.prepareScene(background);

    graphics.presentScene();
    waitUntilKeyPressed();

      SDL_Event event;
    int x, y;
    while (true) {
        SDL_GetMouseState(&x, &y);
        //cerr << ((x > 100 && y > 100 && x < 200 && y < 200) ? "In\n" : "Out\n");

        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                 exit(0);
                 break;
            case SDL_MOUSEBUTTONDOWN:
                 cerr << "Down at (" << x << ", " << y << ")\n";
                 break;
            case SDL_MOUSEBUTTONUP:
                 cerr << "Up at (" << x << ", " << y << ")\n";
                 break;
        }
        SDL_Delay(100);
    }

    SDL_DestroyTexture( background );
    background = NULL;

    graphics.quit();
    return 0;
}*/
int main(int argc, char *argv[])
{
     Graphics graphics;
     graphics.init();

    SDL_Texture* background = graphics.loadTexture("Setup11.png");
    graphics.prepareScene(background);

    graphics.presentScene();

    SDL_Event event;
    int x, y;
    while (true) {
        SDL_GetMouseState(&x, &y);

        SDL_PollEvent(&event);
        /*if(event.type==SDL_MOUSEBUTTONUP) {
            if((x>=367 and x<=573) and (y>=446 and y<=526)){
                graphics.quit();
            }
            else if((x>=367 and x<=573) and (y>=357 and y<=434)){
                 SDL_Texture* HELP = graphics.loadTexture("HELP.png");

                 graphics.prepareScene(HELP);
                 graphics.presentScene();
            }

            if(event.type==SDL_MOUSEBUTTONUP){
                if((x>=21 and x<=55) and (y>=22 and y<=46)){
                    graphics.prepareScene(background);
                    graphics.presentScene();
                    }
                }
        }*/
        switch (event.type) {
            case SDL_QUIT:
                 exit(0);
                 break;
            case SDL_MOUSEBUTTONDOWN:
                 cerr << "Down at (" << x << ", " << y << ")\n";
                 break;
            case SDL_MOUSEBUTTONUP:
                 cerr << "Up at (" << x << ", " << y << ")\n";
                 break;

        }
        SDL_Delay(100);
    }

    graphics.quit();
    return 0;
}
