#ifndef __VOR_CPP
#define __VOR_CPP

#include "../include/vor.h"
#include "../include/sdl_helper.h"
#include "../include/cdi_information.h"
#include "../include/panel_element.h"
#include <math.h>

#define ANGLE_APPROX 0.5

vor vor::nonexistent_vor = vor(0, 0, 0, 0, "NONEXISTENT", -1);

int vor::get_frequency() const
{
    return frequency;
}

void vor::draw_moving_map_symbol(double xpos, double ypos, double xsize, double ysize) const
{
    xsize *= moving_map_size_factor();
    ysize *= moving_map_size_factor();
    Uint32 color = sdl_helper::WHITE;
    sdl_helper::normal_line_color(xpos + ANGLE_APPROX * xsize, ypos - ysize, xpos + xsize, ypos, color);
    sdl_helper::normal_line_color(xpos + xsize, ypos, xpos + ANGLE_APPROX * xsize, ypos + ysize, color);
    sdl_helper::normal_line_color(xpos + ANGLE_APPROX * xsize, ypos + ysize, xpos - ANGLE_APPROX * xsize, ypos + ysize  , color);
    sdl_helper::normal_line_color(xpos - ANGLE_APPROX * xsize, ypos + ysize, xpos-xsize, ypos   , color);
    sdl_helper::normal_line_color(xpos - xsize, ypos, xpos - ANGLE_APPROX * xsize, ypos - ysize ,color);
    sdl_helper::normal_line_color(xpos - ANGLE_APPROX * xsize, ypos - ysize , xpos + ANGLE_APPROX * xsize, ypos - ysize,color);
    sdl_helper::normal_text(xpos - xsize, ypos + ysize, identifier);
}

cdi_information vor::get_deviation(const aircraft& a, int selected_radial) const
{
    cdi_information r;
    r.flag = false;
    double actual_radial = compute_actual_radial(a);

    r.deviation = actual_radial - selected_radial;
    if (r.deviation > 180)
    {
        r.deviation -= 360;
    }
    if (r.deviation < -180)
    {
        r.deviation += 360;
    }
    if (r.deviation >= 90.0)
    {
        r.direction = cdi_information::TO;
        r.deviation -= 180.0;
        r.deviation *= -1;
    }
    else if (r.deviation <= -90.0)
    {
        r.direction = cdi_information::TO;
        r.deviation += 180.0;
        r.deviation *= -1;
    }
    else
    {
        r.direction = cdi_information::FROM;
    }
    return r;
}

double vor::compute_actual_radial(const aircraft& a) const
{
    double theta = atan(fabs(a.get_x_position() - get_x_position()) / fabs(a.get_y_position() - get_y_position()));
    double degrees = panel_element::radians_to_degrees(theta);
    if ((a.get_x_position() > get_x_position()) && a.get_y_position() < get_y_position())
    {
        degrees = 180 - degrees;
    }
    else if ((a.get_x_position() > get_x_position()) && a.get_y_position() > get_y_position())
    {
        degrees = degrees;
    }
    else if ((a.get_x_position() < get_x_position()) && a.get_y_position() > get_y_position())
    {
        degrees = 360 - degrees;
    }
    else
    {
        degrees = 180 + degrees;
    }
    degrees -= get_variation();
    while (degrees < 0)
    {
        degrees = degrees + 360;
    }
    while (degrees > 360)
    {
        degrees = degrees - 360;
    }
    return degrees;
}

#endif
