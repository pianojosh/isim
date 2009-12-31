#ifndef __AIRPORT_CPP
#define __AIRPORT_CPP

#include "../include/airport.h"
#include "../include/sdl_helper.h"

void airport::draw_moving_map_symbol(double xpos, double ypos, double xsize, double ysize) const
{
    xsize *= moving_map_size_factor();
    ysize *= moving_map_size_factor();

    sdl_helper::normal_fill_rect_color(xpos, ypos, xpos + xsize, ypos + ysize, sdl_helper::PURPLE);
}








#endif
