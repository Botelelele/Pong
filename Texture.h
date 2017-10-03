#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#define TEXTURE_CENTER_NONE 0xffff
class Texture//class to manage a texture
{
private:
    SDL_Texture * texture;//texture
    SDL_RendererFlip flip;//flip mode for texture rendering(renderer)
    SDL_Point* texture_center;//point that is center of our texture
    double angle;//angle(for RenderEx and RenderPartEx)
    int width;//width of texture
    int height;//height of texture
    int x;//x of texture
    int y;//y of texture
public:
    Texture();//constructor
    ~Texture();//destructor
    //functions
    bool LoadFromFile(std::string path,SDL_Renderer*renderer);//loading texture from file

    void Free();//free texture memory

    void setRect(int x,int y, int w, int h);//setting rect parameters
    void setXandY(int x,int y);
    void setX(int x);//setting X
    void setY(int y);//setting Y
    void setWidth(int width);//setting width
    void setHeight(int height);//setting height
    void setAlpha(Uint8 alpha);//SDL_SetTextureAlphaMod(SDL_Texture* texture, Uint8 alpha)
    void setAngle(double angle);//setting angle
    void setColorMod(Uint8 r,Uint8 g,Uint8 b);//SDL_SetTextureColorMod(SDL_Texture* texture, Uint8 r, Uint8 g, Uint8 b)
    void setBlendMode(SDL_BlendMode mode);//SDL_SetTextureBlendMode(SDL_Texture* texture, SDL_BlendMode blendMode)
    void setFlip(SDL_RendererFlip mode);//setting flip
    void setTextureCenter(SDL_Point*center);//setting texture center
    void setTextureCenter(int x,int y);//setting texture center with 2 variables
    void setTextureCenter(void);

    void Render(SDL_Renderer* renderer);//rendering whole texture on x and y
    void RenderPart(SDL_Renderer* renderer,SDL_Rect part_rect);//rendering part of texture on x and y
    void RenderPartEx(SDL_Renderer* renderer,SDL_Rect part_rect);//rendering part of texture on x and y EXTENDED
    void RenderEx(SDL_Renderer* renderer);//rendering whole texture on x and y EXTENDED
    #ifdef _SDL_TTF_H//if we use SDL TTF
    SDL_Texture* RenderText(std::string  text,SDL_Renderer*render, SDL_Color color, TTF_Font*font);//creating text texture
    #endif // _SDL_TTF_H

    int getWidth(){return width;}
    int getHeight(){return height;}
    double getAngle(){return angle;}
    int getX(){return x;}
    int getY(){return y;}
    SDL_Rect getRect()
    {
        return SDL_Rect{x,y,width,height};
    }

};


#endif // TEXTURE_H_INCLUDED
