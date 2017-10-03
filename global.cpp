#include"global.h"
#include<SDL2/SDL.h>
#include "Window.h"
bool leave=false;
SDL_Event event;
Window window;
SDL_Renderer* render;
const Uint8* keystate;
short int movementX=MOVEMENT_STOP;//ball movement
short int movementY=MOVEMENT_Y_DOWN;//ball movement
bool Ublock_movX_Min=true;//upper block movement X minus
bool Ublock_movX_Plus=true;//upper block movement X plus
bool Lblock_movX_Plus=true;//lower block movement X plus
bool Lblock_movX_Min=true;//lower block movement X minus
unsigned int refresh_rate;
