#ifndef __AIRSPEED_INDICATOR_CPP
#define __AIRSPEED_INDICATOR_CPP

#include "../include/airspeed_indicator.h"
#include "../include/sdl_helper.h"

#include <math.h>

void airspeed_indicator::draw(const aircraft& a, const world& w)
{
    double theta = 2 * PI * (a.get_airspeed() - min_speed) / (max_speed - min_speed);
    if (theta < 0)
    {
        theta = 0;
    }
    if (theta > 2 * PI)
    {
        theta = 2 * PI;
    }
    theta -= PI / 2;

    double radius = radius_for_theta(theta);

    sdl_helper::normal_ellipse_color(x_position, y_position, x_size, y_size, sdl_helper::WHITE);
    //sdl_helper::normal_line_color(x_position, y_position, x_position + x_size * cos(theta), y_position + y_size * sin(theta), sdl_helper::BLUE);
    draw_needle(x_position, y_position, theta, radius, degrees_to_radians(15.0), 0.25, sdl_helper::WHITE);
    sdl_helper::normal_text(x_position, y_position + y_size / 10 - 0.1, sdl_helper::to_string(min_speed));
    sdl_helper::normal_text(x_position, y_position + y_size / 10 - 0.05, sdl_helper::to_string(max_speed));

    sdl_helper::normal_text(x_position, y_position + y_size / 10, sdl_helper::to_string(a.get_airspeed()));
    //sdl_helper::normal_text(x_position, y_position + y_size / 10 + 0.05, sdl_helper::to_string(theta));
}

#endif
