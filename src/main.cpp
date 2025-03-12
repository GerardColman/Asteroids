

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_log.h>

/* Constants */
constexpr int kScreenWidth{ 640 };
constexpr int kScreenHeight{ 480 };


/* Function Prototypes*/
bool init();
bool loadMedia();
void close();

/* Global Variables */
//The window we'll be rendering to
SDL_Window* gWindow{ nullptr };

//The renderer
SDL_Renderer *gRenderer{ nullptr };

int main(int argc, char *argv[]){
    
    // Initializing the Program
    if(!init()){
        SDL_Log("Unable to init");
        return 1;
    }


    // Initializing the Program
    if(!loadMedia){
        SDL_Log("Unable to load media");
        return 2;
    }


    /* Main Game Loop */

    // Quit flag
    bool quit = false;

    //The event data
    SDL_Event e;
    SDL_zero(e);

    while(quit == false){

        // Polling for Events
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_EVENT_QUIT){
                quit = true;
            }
        }

        //Rendering
        SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);  /* black, full alpha */
        SDL_RenderClear(gRenderer);  /* start with a blank canvas. */
    }

    

    return 0;
}

/* Function Implementation */
bool init(){
    bool success = true;

    if(!SDL_Init(SDL_INIT_AUDIO || SDL_INIT_VIDEO)){
        success = false;
    } else {

        // Creating window
        if( SDL_CreateWindowAndRenderer("Asteroids", kScreenWidth, kScreenHeight, 0, &gWindow, &gRenderer); gWindow == nullptr){
            SDL_Log("Window could not be created! SDL error: %s\n", SDL_GetError() );

            success = false;
        }
    }


    return success;
}

bool loadMedia(){
    bool success = true;

    return success;
}