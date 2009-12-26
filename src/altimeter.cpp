#ifndef __ALTIMETER_CPP
#define __ALTIMETER_CPP

#include "../include/altimeter.h"
#include "../include/sdl_helper.h"

#include <math.h>

void altimeter::draw(const aircraft& a, const world& w) const
{
    double alt = a.get_altitude();
    double thousands = (alt - ((int)(alt / 10000.0)) * 10000.0) / 1000.0;
    double hundreds = (alt - ((int)(alt / 1000.0)) * 1000.0) / 100.0;

    double thousands_theta = (thousands / 10.0) * 2 * PI - PI / 2;
    double hundreds_theta = (hundreds / 10.0) * 2 * PI - PI / 2;

    sdl_helper::normal_ellipse_color(x_position, y_position, x_size, y_size, sdl_helper::WHITE);
    draw_needle(x_position, y_position, thousands_theta, radius_for_theta(thousands_theta) * 0.5, degrees_to_radians(30), 0.3, sdl_helper::WHITE);
    draw_needle(x_position, y_position, hundreds_theta, radius_for_theta(hundreds_theta), degrees_to_radians(10), 0.3, sdl_helper::WHITE);
    sdl_helper::normal_text(x_position, y_position + y_size * 0.25, sdl_helper::to_string(alt));

    for (int i = 0; i < 10; i++)
    {
        double angle = ((double)i / 10.0) * 2 * PI - PI / 2;
        sdl_helper::normal_text(
            x_position + radius_for_theta(angle) * cos(angle) * 0.85 - x_size * 0.05,
            y_position + radius_for_theta(angle) * sin(angle) * 0.85 - y_size * 0.08,
            sdl_helper::to_string((double)i)
        );
    }

}

#endif
