#ifndef __GROUND_OBJECT_CPP
#define __GROUND_OBJECT_CPP

#include "../include/ground_object.h"
#include "../include/sdl_helper.h"

#include <iostream>
using std::cout;
using std::endl;

double ground_object::get_x_position() const
{
    return x_position;
}

double ground_object::get_y_position() const
{
    return y_position;
}

int ground_object::compare_by_x_dimension(ground_object* l, ground_object* r)
{
    if (l->x_position < r->x_position)
    {
        return true;
    }
    return false;
}

int ground_object::compare_by_y_dimension(ground_object* l, ground_object* r)
{
    if (l->y_position < r->y_position)
    {
        return true;
    }
    return false;
}

void ground_object::draw_moving_map_symbol(double xpos, double ypos, double xsize, double ysize) const
{
    xsize *= moving_map_size_factor();
    ysize *= moving_map_size_factor();
    Uint32 color = sdl_helper::GREEN;
    sdl_helper::normal_fill_rect_color(xpos, ypos, xpos + xsize, ypos + ysize, color);
}

double ground_object::moving_map_size_factor() const
{
    return 0.025;
}

int ground_object::get_variation() const
{
    return variation;
}

#endif
