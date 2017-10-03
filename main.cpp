#include <SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include"global.h"
#include"functions.h"
#include"fps.h"
#include<cstdlib>
#include <time.h>
#include <math.h>
#include <iostream>
#include "Window.h"
#include "Texture.h"
using namespace std;


int main(int argc,char *argv[])
{
    TTF_Init();
    SDL_Init(SDL_INIT_EVERYTHING);
    {//calculating hz of monitor
    SDL_DisplayMode DM;
    SDL_GetDesktopDisplayMode(0, &DM);
    if(DM.refresh_rate<120)
    {
    refresh_rate=120;
    }
    else
    {
    refresh_rate=DM.refresh_rate;
    }
    }
    long double proportion_hz=refresh_rate/120.0;//proportion of screen's hz to wanted hz
    float increasing=1;//this variable will  be * to every motion variable
    Uint32 seconds=0;//seconds that passed
    cfps fps;//class for managing fps
    degree BlockL_degree(0,-15,15);//degree of lower block velocity
    degree BlockU_degree(0,-15,15);//degree of upper block velocity
    {//definition of window and renderer
        if(!window.init("Pong",1600,900)){leave=1;cerr<<"Window error!"<<"\n";}
        render=window.createRenderer(0);
    }
    //{movement of ball
        short int current_movementX=MOVEMENT_STOP;
        short int current_movementY=MOVEMENT_Y_DOWN;
        float velBall_x=2;
        const float velBall_y=4;
        float realVelX=0;
        float realVelY=0;
        float velBlockU_x=0;
        float velBlockL_x=0;
    //}
    //SDL_Rect rect{x,y,w,h};
    //{declaring rects
        //SDL_Rect rLblock{680,859,320,40};//rect of lower block
        //SDL_Rect rUblock{740,1,320,40};//rect of upper block
        //SDL_Rect r1{0,0,1600,900};//it's rect of screen and background
        //SDL_Rect rBall{650,420,60,60};//rect of ball
    //}
        Texture background;
        background.LoadFromFile("Graphics/background.png",render);
        background.setRect(0,0,1600,900);
        Texture ball;
        ball.LoadFromFile("Graphics/ball.png",render);
        ball.setRect(770,420,60,60);
        Texture Lblock;
        Lblock.LoadFromFile("Graphics/block.png",render);
        Lblock.setRect(680,859,320,40);
        Texture Ublock;
        Ublock.LoadFromFile("Graphics/block.png",render);
        Ublock.setRect(740,1,320,40);
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1");//antyaliasing
        while(leave==false){
        srand(time(NULL));
        fps.start();
        {//movement
            if(!window.isMinimized())
            {
                realVelX=((velBall_x*current_movementX)/proportion_hz)*increasing;
                realVelY=velBall_y*current_movementY/proportion_hz*increasing;
                ball.setY(ball.getY()+realVelY);
                ball.setX(ball.getX()+realVelX);
                velBlockL_x=BlockL_degree.return_current()*0.6/proportion_hz;
                velBlockU_x=BlockU_degree.return_current()*0.6/proportion_hz;
                Ublock.setX(Ublock.getX()+velBlockU_x);
                Lblock.setX(Lblock.getX()+velBlockL_x);
            }
        }
        {//changing rects
            if(!window.isMinimized())
            {
                background.setWidth(window.getWidth());
                background.setHeight(window.getHeight());
                Lblock.setY(window.getHeight()-41);
            }
        }
        {//calculating frame
            if(!window.isMinimized())
            {
            if(fps.frame%refresh_rate==0)
            {
                seconds++;
                if(seconds%3==0)
                {
                 increasing+=0.1;
                }
            }
            }
        }
        {//events
                while(SDL_PollEvent(&event))
                {
                if(event.type==SDL_QUIT) leave=1;
                window.event_handle(event,render);
                }
                if(!window.isMinimized())
                {
                    {//colision of ball with blocks
                    int side_upper(-99);
                    int side_lower(-99);
                    {//upper block
                   if(colission_ball_block_upper(ball.getRect(),Ublock.getRect(),side_upper))
                    {
                        current_movementY=MOVEMENT_Y_DOWN;
                        switch(side_upper)
                        {
                        case SIDE_LEFT:
                            {
                                current_movementX=MOVEMENT_X_LEFT;
                                velBall_x+=velBlockU_x/10;
                                velBall_x+=0.2;
                                break;
                            }
                        case SIDE_RIGHT:
                            {
                                current_movementX=MOVEMENT_X_RIGHT;
                                velBall_x+=velBlockU_x/10;
                                velBall_x+=0.2;
                                break;
                            }
                        case SIDE_MIDDLE:{
                                velBall_x+=velBlockU_x/8;
                                if(velBall_x-0.4>=0){velBall_x-=0.3;}
                                else{velBall_x=0.3;}
                                if(BlockU_degree.return_current()!=0)
                                {
                                    if(BlockU_degree.check_plus())
                                    {
                                        current_movementX=MOVEMENT_X_RIGHT;
                                    }
                                    else
                                    {
                                        current_movementX=MOVEMENT_X_LEFT;
                                    }
                                }
                                break;
                            }
                        }
                   }
                 }
                 {//lower block

                    if(colission_ball_block_lower(ball.getRect(),Lblock.getRect(),side_lower)){
                        current_movementY=MOVEMENT_Y_UP;
                        switch(side_lower)
                        {
                        case SIDE_LEFT:
                            {
                                current_movementX=MOVEMENT_X_LEFT;
                                velBall_x+=velBlockU_x/10;
                                velBall_x+=0.2;
                                break;
                            }
                        case SIDE_RIGHT:
                            {
                                current_movementX=MOVEMENT_X_RIGHT;
                                velBall_x+=velBlockU_x/10;
                                velBall_x+=0.2;
                                break;
                            }
                        case SIDE_MIDDLE:
                            {
                                velBall_x+=velBlockU_x/8;
                                if(velBall_x-0.4>=0){velBall_x-=0.3;}
                                else{velBall_x=0.3;}
                                if(BlockL_degree.return_current()!=0)
                                {
                                    if(BlockL_degree.check_plus())
                                    {
                                        current_movementX=MOVEMENT_X_RIGHT;
                                    }
                                    else
                                    {
                                        current_movementX=MOVEMENT_X_LEFT;
                                    }
                                }
                                break;
                            }
                        }
                   }
                    }
                }
                  {//colission of blocks with walls
                    if(Ublock.getX()>window.getWidth()-Ublock.getWidth()){Ublock_movX_Plus=false;Ublock.setX(window.getWidth()-Ublock.getWidth());}
                    else{Ublock_movX_Plus=true;}
                    if(Ublock.getX()<0){Ublock_movX_Min=false;Ublock.setX(0);}
                    else{Ublock_movX_Min=true;}
                    if(Lblock.getX()>window.getWidth()-Lblock.getWidth()){Lblock_movX_Plus=false;Lblock.setX(window.getWidth()-Lblock.getWidth());}
                    else{Lblock_movX_Plus=true;}
                    if(Lblock.getX()<0){Ublock_movX_Min=false;Lblock.setX(0);}
                    else{Lblock_movX_Min=true;}
                }
                {//colission of ball with walls
                    if(ball.getX()<=0)
                    {
                            ball.setX(0);current_movementX=MOVEMENT_X_RIGHT;
                            if(Ublock.getX()<=5&&Lblock.getX()<=5)
                            {
                                velBall_x+=2;
                            }
                    }
                    if(ball.getX()>=window.getWidth()-ball.getWidth())
                    {
                            ball.setX(window.getWidth()-ball.getWidth());current_movementX=MOVEMENT_X_LEFT;
                            if(Ublock.getX()>=window.getWidth()-Ublock.getWidth()-1&&Lblock.getX()>=window.getWidth()-Lblock.getWidth()-1)
                            {
                                velBall_x+=2;
                            }
                    }
                    if(ball.getY()<=0)//if upper(upper block) player lost
                    {
                            ball.setX(window.getWidth()/2-30);
                            ball.setY(window.getHeight()/2-30);
                            current_movementX=MOVEMENT_STOP;
                            Ublock.setX(window.getWidth()/2-220);
                            Lblock.setX(Ublock.getX());
                            Ublock.setY(1);
                            Lblock.setY(window.getHeight()-41);
                            increasing=1;
                    }
                    if(ball.getY()+ball.getWidth()>=window.getHeight())//if lower(lower block) player lost
                    {
                            ball.setX(window.getWidth()/2-30);
                            ball.setY(window.getHeight()/2-30);
                            current_movementX=MOVEMENT_STOP;
                            Ublock.setX(window.getWidth()/2-220);
                            Lblock.setX(Ublock.getX());
                            Ublock.setY(1);
                            Lblock.setY(window.getHeight()-41);
                            increasing=1;
                    }
                }
                 }

        }
        {//render
            if(!window.isMinimized())
            {
                SDL_SetRenderDrawColor(render,0xff,0xff,0xff,0xff);
                SDL_RenderClear(render);
                background.setColorMod(rand()%256,rand()%256,rand()%256);
                background.Render(render);
                ball.setColorMod(rand()%256,rand()%256,rand()%256);
                ball.Render(render);
                Ublock.setColorMod(rand()%256,rand()%256,rand()%256);
                Ublock.Render(render);
                Lblock.setColorMod(rand()%256,rand()%256,rand()%256);
                Lblock.Render(render);
                SDL_RenderPresent(render);
            }
        }
        {//keyboard
            if(!window.isMinimized()&&window.checkKeyboardFocus())
            {
                keystate=SDL_GetKeyboardState(NULL);
            if(keystate[SDL_SCANCODE_ESCAPE]) {leave=1;}
            if(keystate[SDL_SCANCODE_RIGHT]){BlockL_degree++;}
            else if(keystate[SDL_SCANCODE_LEFT]){BlockL_degree--;}
            else
            {
                 if(BlockL_degree.return_current()>0){BlockL_degree--;}
                else if(BlockL_degree.return_current()<0){BlockL_degree++;}
            }
            if(keystate[SDL_SCANCODE_A]){BlockU_degree--;}
            else if(keystate[SDL_SCANCODE_D]){BlockU_degree++;}
            else
            {
                if(BlockU_degree.return_current()>0){BlockU_degree--;}
                else if(BlockU_degree.return_current()<0){BlockU_degree++;}
            }
            if(keystate[SDL_SCANCODE_R])
            {
                ball.setX(window.getWidth()/2-30);
                ball.setY(window.getHeight()/2-30);
                current_movementX=MOVEMENT_STOP;
                Ublock.setX(window.getWidth()/2-220);
                Lblock.setX(Ublock.getX());
                Ublock.setY(1);
                Lblock.setY(window.getHeight()-41);
                increasing=1;
            }
            }
        }
        fps.meta();
    }
    {//deallocating
    SDL_DestroyRenderer(render);
    render=nullptr;
    window.free();
    }
    return 0;
}
