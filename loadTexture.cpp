#include"global.h"
#include"functions.h"
#include<SDL2/SDL_image.h>
#include<SDL2/SDL.h>
#include<string>
#include<cstdlib>
using namespace std;
SDL_Texture*loadTexture(string nazwa,SDL_Renderer*render)
{
    SDL_Texture*wysylane;
    SDL_Surface*wczytane=IMG_Load(nazwa.c_str());
    if(wczytane==0){ SDL_Log("Cannot read file: ",nazwa.c_str());leave=true;}
    else
    {
        wysylane=SDL_CreateTextureFromSurface(render,wczytane);
    }
    SDL_FreeSurface(wczytane);
    return wysylane;
}
