#ifndef __SDL_HELPER_CPP
#define __SDL_HELPER_CPP

#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif
#ifdef __APPLE__
#include <SDL/SDL.h>
#else
#include <SDL.h>
#endif

#include "SGE.h"

#include <iostream>
#include <string>
#include <sstream>

#include "../include/sdl_helper.h"

SDL_Surface* sdl_helper::surface = NULL;
sge_bmpFont* sdl_helper::sgefont = NULL;

Uint32 sdl_helper::WHITE = 0;
Uint32 sdl_helper::RED = 0;
Uint32 sdl_helper::GREEN = 0;
Uint32 sdl_helper::BLUE = 0;
Uint32 sdl_helper::BLACK = 0;
Uint32 sdl_helper::BROWN = 0;
Uint32 sdl_helper::PURPLE = 0;

std::string sdl_helper::to_string(double x)
{
    std::ostringstream o;
    o << x;
    return o.str();
}

std::string sdl_helper::to_string(int x)
{
    std::ostringstream o;
    o << x;
    return o.str();
}

Uint32 sdl_helper::color_for_screen(Uint8 R, Uint8 G, Uint8 B)
{
    return SDL_MapRGB(surface->format, R, G, B);
}

void sdl_helper::flip()
{
    SDL_Flip(surface);
}

void sdl_helper::draw_line_color(int startx, int starty, int endx, int endy, Uint32 color)
{
    sge_AALine(surface, startx, starty, endx, endy, color);
}

void sdl_helper::fill_rect_color(int startx, int starty, int endx, int endy, Uint32 color)
{
    sge_FilledRect(surface, startx, starty, endx, endy, color);
}

void sdl_helper::normal_rect_color(double startx, double starty, double endx, double endy, Uint32 color)
{
    sge_Rect(surface, (int)(surface->w*startx), (int)(surface->h*starty), (int)(surface->w*endx), (int)(surface->h*endy), color);
}

void sdl_helper::normal_fill_rect_color(double startx, double starty, double endx, double endy, Uint32 color)
{
    sge_FilledRect(surface, (int)(surface->w*startx), (int)(surface->h*starty), (int)(surface->w*endx), (int)(surface->h*endy), color);
}

void sdl_helper::normal_line_color(double startx, double starty, double endx, double endy, Uint32 color)
{
    sge_AALine(surface, (int)(surface->w*startx), (int)(surface->h*starty), (int)(surface->w*endx), (int)(surface->h*endy), color);
}

void sdl_helper::normal_ellipse_color(double x, double y, double rx, double ry, Uint32 color)
{
    sge_AAEllipse(surface, (int)(surface->w*x), (int)(surface->h*y), (int)(surface->w*rx), (int)(surface->h*ry), color);
}

void sdl_helper::normal_floodfill_color(double x, double y, Uint32 color)
{
    sge_FloodFill(surface, (int)(surface->w*x), (int)(surface->h*y), color);
}

void sdl_helper::normal_text(double x, double y, const std::string& s)
{
    sge_BF_textout(surface, sgefont, (char*)s.c_str(), (int)(surface->w*x), (int)(surface->h*y));
}

void sdl_helper::normal_fillpoly_color(double* x, double* y, int n, Uint32 color)
{
    Sint16* px = new Sint16[n];
    Sint16* py = new Sint16[n];
    for (int i = 0; i < n; i++)
    {
        px[i] = (Sint16)(surface->w*x[i]);
        py[i] = (Sint16)(surface->h*y[i]);
    }
    sge_AAFilledPolygon(surface, n, px, py, color);
    delete[] px;
    delete[] py;
}

double sdl_helper::aspect_ratio()
{
    return (double)surface->w / (double)surface->h;
}

void sdl_helper::set_surface(SDL_Surface* s)
{
    surface = s;
}

SDL_Surface* sdl_helper::get_surface()
{
    return surface;
}

void sdl_helper::initialize()
{
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        throw 1;
    }
    atexit(SDL_Quit);
    surface = SDL_SetVideoMode(1024, 768, 32, SDL_SWSURFACE);
    if ( !surface )
    {
        printf("Unable to set video: %s\n", SDL_GetError());
        throw 2;
    }
    sge_Update_OFF();

    WHITE = color_for_screen(255, 255, 255);
    RED = color_for_screen(255, 0, 0);
    GREEN = color_for_screen(0, 255, 0);
    BLUE = color_for_screen(0, 0, 255);
    BLACK = color_for_screen(0, 0, 0);
    BROWN = color_for_screen(175, 175, 127);
    PURPLE = color_for_screen(255, 0, 255);

    sgefont = sge_BF_OpenFont("font.bmp", SGE_BFTRANSP);
    sge_BF_SetColor(sgefont, 255, 255, 255);
}

#endif
