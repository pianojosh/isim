#ifndef __SDL_HELPER_H
#define __SDL_HELPER_H

#include "SDL.h"
#include "SGE.h"

#include <string>

class sdl_helper
{
    public:
        static void initialize();

        static SDL_Surface* get_surface();
        static void set_surface(SDL_Surface* s);

        static Uint32 color_for_screen(Uint8 R, Uint8 G, Uint8 B);
        static void draw_line_color(int startx, int starty, int endx, int endy, Uint32 color);
        static void fill_rect_color(int startx, int starty, int endx, int endy, Uint32 color);

        static void normal_line_color(double startx, double starty, double endx, double endy, Uint32 color);
        static void normal_fill_rect_color(double startx, double starty, double endx, double endy, Uint32 color);
        static void normal_ellipse_color(double x, double y, double rx, double ry, Uint32 color);
        static void normal_floodfill_color(double x, double y, Uint32 color);
        static void normal_text(double x, double y, const std::string& s);
        static void normal_fillpoly_color(double* x, double* y, int n, Uint32 color);
        static void flip();

        static std::string to_string(double x);
        static std::string to_string(int x);

        static double aspect_ratio();

        static Uint32 WHITE;
        static Uint32 RED;
        static Uint32 GREEN;
        static Uint32 BLUE;
        static Uint32 BROWN;
        static Uint32 BLACK;
//        static double PI;

    private:
        static SDL_Surface* surface;
        static sge_bmpFont* sgefont;

};

#endif
