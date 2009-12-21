#ifndef __VOR_CPP
#define __VOR_CPP

#include "../include/vor.h"
#include "../include/sdl_helper.h"

#define ANGLE_APPROX 0.5

vor vor::nonexistent_vor = vor(0, 0, 0, 0, "NONEXISTENT", -1);

int vor::get_frequency()
{
    return frequency;
}

void vor::draw_moving_map_symbol(double xpos, double ypos, double xsize, double ysize)
{
    xsize *= moving_map_size_factor();
    ysize *= moving_map_size_factor();
    Uint32 color = sdl_helper::color_for_screen(255, 255, 255);
    sdl_helper::normal_line_color(xpos + ANGLE_APPROX * xsize, ypos - ysize, xpos + xsize, ypos, color);
    sdl_helper::normal_line_color(xpos + xsize, ypos, xpos + ANGLE_APPROX * xsize, ypos + ysize, color);
    sdl_helper::normal_line_color(xpos + ANGLE_APPROX * xsize, ypos + ysize, xpos - ANGLE_APPROX * xsize, ypos + ysize  , color);
    sdl_helper::normal_line_color(xpos - ANGLE_APPROX * xsize, ypos + ysize, xpos-xsize, ypos   , color);
    sdl_helper::normal_line_color(xpos - xsize, ypos, xpos - ANGLE_APPROX * xsize, ypos - ysize ,color);
    sdl_helper::normal_line_color(xpos - ANGLE_APPROX * xsize, ypos - ysize , xpos + ANGLE_APPROX * xsize, ypos - ysize,color);
    sdl_helper::normal_text(xpos - xsize, ypos + ysize, identifier);
}

#endif
