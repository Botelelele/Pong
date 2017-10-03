#include "Texture.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "global.h"
#include<iostream>

Texture::Texture():texture(nullptr),flip(SDL_FLIP_NONE),texture_center(nullptr),angle(0),width(0),height(0),x(0),y(0)
{
    texture_center=new SDL_Point;
    texture_center->x=TEXTURE_CENTER_NONE;
    texture_center->y=TEXTURE_CENTER_NONE;
}
Texture::~Texture()
{
    Free();
    delete texture_center;
    Texture::texture_center=nullptr;
}
void Texture::Free()
{
    SDL_DestroyTexture(texture);
    texture=nullptr;
}
#ifdef _SDL_TTF_H
SDL_Texture* Texture::RenderText(std::string text,SDL_Renderer* render, SDL_Color color, TTF_Font* font)//function that creates text texture and return it
{
    SDL_Surface*surface=TTF_RenderText_Blended(font,text.c_str(),color);
    SDL_Texture*created=SDL_CreateTextureFromSurface(render,surface);
    SDL_FreeSurface(surface);
    return created;
}
#endif // _SDL_TTF_H
void Texture::setRect(int x, int y, int w, int h)
{
    Texture::x=x;
    Texture::y=y;
    Texture::width=w;
    Texture::height=h;
}
void Texture::setXandY(int x, int y)
{
    Texture::x=x;
    Texture::y=y;
}
void Texture::setX(int x)
{
    Texture::x=x;
}
void Texture::setY(int y)
{
    Texture::y=y;
}
void Texture::setAlpha(Uint8 alpha)
{
    SDL_SetTextureAlphaMod(texture,alpha);
}
void Texture::setAngle(double angle)
{
    Texture::angle=angle;
}
void Texture::setFlip(SDL_RendererFlip mode)
{
    flip=mode;
}

void Texture::Render(SDL_Renderer* renderer)
{
    SDL_Rect dstrect{x,y,width,height};
    SDL_RenderCopy(renderer,texture,NULL,&dstrect);
}
void Texture::RenderPart(SDL_Renderer* renderer,SDL_Rect part_rect)
{
    SDL_Rect dstrect{x,y,width,height};
    SDL_RenderCopy(renderer,texture,&part_rect,&dstrect);
}
void Texture::RenderEx(SDL_Renderer* renderer)
{
    SDL_Rect dstrect{x,y,width,height};
    if(texture_center->x==TEXTURE_CENTER_NONE&&texture_center->y==TEXTURE_CENTER_NONE)
    {
        SDL_RenderCopyEx(renderer,texture,NULL,&dstrect,angle,texture_center,flip);
    }
    else
    {
        SDL_RenderCopyEx(renderer,texture,NULL,&dstrect,angle,NULL,flip);
    }
}
void Texture::RenderPartEx(SDL_Renderer* renderer,SDL_Rect part_rect)
{
    SDL_Rect dstrect{x,y,width,height};
    if(texture_center->x==0xffff&&texture_center->y==0xffff)
    {
        SDL_RenderCopyEx(renderer,texture,&part_rect,&dstrect,angle,texture_center,flip);
    }
    else
    {
        SDL_RenderCopyEx(renderer,texture,&part_rect,&dstrect,angle,NULL,flip);
    }
}

bool Texture::LoadFromFile(std::string path,SDL_Renderer* renderer)
{
    SDL_Surface*surface=IMG_Load(path.c_str());
    if(surface!=nullptr)
    {
        texture=SDL_CreateTextureFromSurface(renderer,surface);
        if(texture!=nullptr){return false;}
        else{std::cerr<<"Cannot create texture from surface. Error code: "<<SDL_GetError()<<"\n";return true;}
    }
    else
    {
        std::cerr<<"Cannot load image from: "<<path.c_str()<<" Error code: "<<SDL_GetError()<<"\n";
        return true;
    }
    return true;
}

void Texture::setColorMod(Uint8 r, Uint8 g, Uint8 b)
{
    SDL_SetTextureColorMod(texture,r,g,b);
}
void Texture::setBlendMode(SDL_BlendMode mode)
{
    SDL_SetTextureBlendMode(texture,mode);
}
void Texture::setWidth(int width)
{
    Texture::width=width;
}
void Texture::setHeight(int height)
{
    Texture::height=height;
}
void Texture::setTextureCenter(SDL_Point* center)
{
    texture_center->x=center->x;
    texture_center->y=center->y;
}
void Texture::setTextureCenter(int x, int y)
{
    texture_center->x=x;
    texture_center->y=y;
}
void Texture::setTextureCenter(void)
{
    texture_center->x=x;
    texture_center->y=y;
}
