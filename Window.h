#ifndef WINDOW_H
#define WINDOW_H
#include<SDL2/SDL.h>
#include <string>


class Window
{
    public:
        Window();
        ~Window();

    void free();//free the memory
    bool init(std::string title,int w,int h);//init all necessary stuff
    void event_handle(SDL_Event&event,SDL_Renderer*render);//function that handles event

    SDL_Renderer*createRenderer(Uint32 flags);

    //functions that check our flags of focus
    bool checkMouseFocus(){return MouseFocus;}
    bool checkKeyboardFocus(){return KeyboardFocus;}
    bool isMinimized(){return minimized;}

    int getWidth(){return width;}//returns width
    int getHeight(){return height;}//retuyrn height

    private:
        SDL_Window*window;//the window
        //flags of focus
        bool minimized;//is minimized?,
        bool fullscreened;//is fullscreened?
        bool KeyboardFocus;//got it keyboard focus?
        bool MouseFocus;//got it mouse focus
        bool shown;//shown?
        int width;
        int height;
        int windowID;
        int windowDisplayID;
};

#endif // WINDOW_H
