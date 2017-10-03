#ifndef FUNKCJE_H_INCLUDED
#define FUNKCJE_H_INCLUDED
#include<SDL2/SDL.h>
#include<string>
#include "global.h"
#define MODE_UPPER_BLOCK true
#define MODE_LOWER_BLOCK false
#define SIDE_LEFT -1
#define SIDE_MIDDLE 0
#define SIDE_RIGHT 1

#ifdef NEED_PER_PIXEL
bool colission_PerPixel(SDL_Rect a, SDL_Rect b);//works only with 2 Rects
#endif // NEED_PER_PIXEL

bool colission_ball_block_upper(SDL_Rect R_Ball, SDL_Rect R_Block,int&);
bool colission_ball_block_lower(SDL_Rect R_Ball, SDL_Rect R_Block,int&);
bool distance(int x1,int y1, int x2, int y2, float r);
#endif // FUNKCJE_H_INCLUDED
