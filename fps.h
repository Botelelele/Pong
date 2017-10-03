#ifndef FPS_H_INCLUDED
#define FPS_H_INCLUDED
#include<SDL2/SDL.h>
#include"global.h"
#include <iostream>
class cfps
{
    Uint32 poczatek;
    Uint32 koniec;
    Uint32 roznica;
    float delay;
    short int fps;
  public:
      Uint32 frame;
      cfps();
      void start() {poczatek=SDL_GetTicks();frame++;}
      void meta()
      {
          koniec=SDL_GetTicks();
          roznica=koniec-poczatek;delay=1000.0/fps-roznica;
           if(delay>0){SDL_Delay(delay);}
    }
};
cfps::cfps():poczatek(0),koniec(0),roznica(0),frame(0),delay(0)
{
fps=refresh_rate;
}
#endif // FPS_H_INCLUDED
