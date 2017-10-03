#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED
#include<SDL2/SDL.h>
#define MOVEMENT_X_RIGHT 1
#define MOVEMENT_X_LEFT -1
#define MOVEMENT_Y_DOWN 1
#define MOVEMENT_Y_UP -1
#define MOVEMENT_STOP 0
#include "Window.h"
extern bool leave;
extern SDL_Event event;
extern Window window;
extern SDL_Renderer*render;
extern const Uint8* keystate;
extern short int movementY;
extern short int movementX;
extern bool Ublock_movX_Min;//upper block movement X minus
extern bool Ublock_movX_Plus;//upper block movement X plus
extern bool Lblock_movX_Plus;//lower block movement X plus
extern bool Lblock_movX_Min;//lower block movement X minus
extern unsigned int refresh_rate;
class degree
{
    const int maximum;
    const int minimum;
    mutable int current;
public:
    degree(const int starter, const int minim, const int maxim):minimum(minim),maximum(maxim)
    {
        if(minimum>maximum){leave=1;}
        if(starter<minimum){leave=1;}
        if(starter>maximum){leave=1;}
        current=starter;
    }
    int operator++(int)
    {
        if(current!=maximum)
        {
            current++;
            return current;
        }
        return -1;
    }
    int operator--(int)
    {
        if(current!=minimum)
        {
            current--;
            return current;
        }
        return -1;
    }
    bool check_plus()//if current is greater than 0 return true
    {
        if(current>0){return true;}
        return false;
    }
    bool check_minus()//if current is lower than 0 return true
    {
        if(current<0){return true;}
        return false;
    }
    void reset()
    {
        current=0;
    }
    int& return_current()
    {
        return current;
    }
};
#endif // GLOBAL_H_INCLUDED
