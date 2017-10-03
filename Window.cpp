#include "Window.h"
#include "global.h"
#include <SDL2/SDL.h>
#include <iostream>
Window::Window():window(nullptr),minimized(false),fullscreened(false),KeyboardFocus(false),MouseFocus(false),shown(false),width(0),height(0),windowID(0),windowDisplayID(0){}

Window::~Window()
{
    free();
    //dtor
}
bool Window::init(std::string title,int w,int h)
{
    free();
    window = SDL_CreateWindow( title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE );
    if( window != NULL )
    {
        MouseFocus = true;
        KeyboardFocus = true;
        width = w;
        height = h;
        shown=true;
    }

    return window != NULL;
}
SDL_Renderer* Window::createRenderer(Uint32 flags)
{
    return SDL_CreateRenderer(window,-1,flags);
}
void Window::free()
{
    if(window!=nullptr)
    {
        SDL_DestroyWindow(window);
        window=nullptr;
        SDL_Log("Window destroyed");
    }
        minimized=false;
        KeyboardFocus=false;
        MouseFocus=false;
        width=0;
        height=0;
}
void Window::event_handle(SDL_Event& event,SDL_Renderer * render)
{
    if(event.type==SDL_WINDOWEVENT)
    {
    switch(event.window.event)
    {
            case SDL_WINDOWEVENT_SHOWN:
            shown=true;
            break;
            case SDL_WINDOWEVENT_HIDDEN:
                shown=false;
                break;
            case SDL_WINDOWEVENT_SIZE_CHANGED:
			width = event.window.data1;
			height = event.window.data2;
			SDL_RenderPresent( render);
			break;

			//Repaint on exposure
			case SDL_WINDOWEVENT_EXPOSED:
			SDL_RenderPresent( render );
			break;

			//Mouse entered window
			case SDL_WINDOWEVENT_ENTER:
			MouseFocus = true;
			break;

			//Mouse left window
			case SDL_WINDOWEVENT_LEAVE:
			MouseFocus = false;
			break;

			//Window has keyboard focus
			case SDL_WINDOWEVENT_FOCUS_GAINED:
			KeyboardFocus = true;
			break;

			//Window lost keyboard focus
			case SDL_WINDOWEVENT_FOCUS_LOST:
			KeyboardFocus = false;
			break;

			//Window minimized
			case SDL_WINDOWEVENT_MINIMIZED:
            minimized = true;
            break;

			//Window maxized
			case SDL_WINDOWEVENT_MAXIMIZED:
			minimized = false;
            break;

			//Window restored
			case SDL_WINDOWEVENT_RESTORED:
			minimized = false;
            break;
            case SDL_WINDOWEVENT_MOVED:
            windowDisplayID=SDL_GetWindowDisplayIndex(window);
            SDL_RenderPresent(render);
            break;
            case SDL_WINDOWEVENT_CLOSE:
            leave=1;
            break;
    }
    }
}
