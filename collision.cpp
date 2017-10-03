#include<cmath>
#include<SDL2/SDL.h>
#include"functions.h"
#include "global.h"

#ifdef NEED_PER_PIXEL
bool colission_PerPixel(SDL_Rect a,SDL_Rect b)
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;
    if( bottomA <= topB ) { return false; }
    if( topA >= bottomB ) { return false; }
    if( rightA <= leftB ) { return false; }
    if( leftA >= rightB ) { return false; }
    return true;
}
#endif // NEED_PER_PIXEL

bool colission_ball_block_upper(SDL_Rect R_Ball, SDL_Rect R_Block,int&side)
{
        if(R_Ball.x>R_Block.x&&R_Ball.x+R_Ball.w<R_Block.x+R_Block.w&&R_Ball.y<R_Block.y+R_Block.h)//middle side
        {
            side=SIDE_MIDDLE;
            return true;
        }
        else if(distance(R_Ball.x+R_Ball.w/2,R_Ball.y+R_Ball.h/2,R_Block.x,R_Block.y+R_Block.h,R_Ball.w/2+1))//left side
        {
            side=SIDE_LEFT;
            return true;
        }
        else if(distance(R_Ball.x+R_Ball.w/2,R_Ball.y+R_Ball.h/2,R_Block.x,R_Block.y+R_Block.h/2,R_Ball.w/2+1))//left side 2
        {
            side=SIDE_LEFT;
            return true;
        }
        else if(distance(R_Ball.x+R_Ball.w/2,R_Ball.y+R_Ball.h/2,R_Block.x,R_Block.y+R_Block.h*0.75,R_Ball.w/2+1))//left side 3
        {
            side=SIDE_LEFT;
            return true;
        }
        else if(distance(R_Ball.x+R_Ball.w/2,R_Ball.y+R_Ball.h/2,R_Block.x+R_Block.w,R_Block.y+R_Block.h,R_Ball.w/2+1))//right side
        {
            side=SIDE_RIGHT;
            return true;
        }
        else if(distance(R_Ball.x+R_Ball.w/2,R_Ball.y+R_Ball.h/2,R_Block.x+R_Block.w,R_Block.y+R_Block.h/2,R_Ball.w/2+1))//right side 2
        {
            side=SIDE_RIGHT;
            return true;
        }
        else if(distance(R_Ball.x+R_Ball.w/2,R_Ball.y+R_Ball.h/2,R_Block.x+R_Block.w,R_Block.y+R_Block.h*0.75,R_Ball.w/2+1))//right side 3
        {
            side=SIDE_RIGHT;
            return true;
        }
    return false;
}
bool colission_ball_block_lower(SDL_Rect R_Ball, SDL_Rect R_Block, int& side)
{
        if(R_Ball.x>R_Block.x&&R_Ball.x+R_Ball.w<R_Block.x+R_Block.w&&R_Ball.y+R_Ball.h>R_Block.y)//middle side
        {
            side=SIDE_MIDDLE;
            return true;
        }
        else if(distance(R_Ball.x+R_Ball.w/2,R_Ball.y+R_Ball.h/2,R_Block.x,R_Block.y,R_Ball.w/2+1))//left side
        {
            side=SIDE_LEFT;
            return true;
        }
        else if(distance(R_Ball.x+R_Ball.w/2,R_Ball.y+R_Ball.h/2,R_Block.x,R_Block.y+R_Block.h/2,R_Ball.w/2+1))//left side 2
        {
            side=SIDE_LEFT;
            return true;
        }
        else if(distance(R_Ball.x+R_Ball.w/2,R_Ball.y+R_Ball.h/2,R_Block.x,R_Block.y+R_Block.h*0.75,R_Ball.w/2+1))//left side 3
        {
            side=SIDE_LEFT;
            return true;
        }
        else if(distance(R_Ball.x+R_Ball.w/2,R_Ball.y+R_Ball.h/2,R_Block.x+R_Block.w,R_Block.y,R_Ball.w/2+1))//right side
        {
            side=SIDE_RIGHT;
            return true;
        }
        else if(distance(R_Ball.x+R_Ball.w/2,R_Ball.y+R_Ball.h/2,R_Block.x+R_Block.w,R_Block.y+R_Block.h/2,R_Ball.w/2+1))//right side 2
        {
            side=SIDE_RIGHT;
            return true;
        }
        else if(distance(R_Ball.x+R_Ball.w/2,R_Ball.y+R_Ball.h/2,R_Block.x+R_Block.w,R_Block.y+R_Block.h*0.75,R_Ball.w/2+1))//right side 3
        {
            side=SIDE_RIGHT;
            return true;
        }
}
