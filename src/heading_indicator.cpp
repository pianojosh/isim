#ifndef __HEADING_INDICATOR_CPP
#define __HEADING_INDICATOR_CPP

#include "../include/heading_indicator.h"
#include "../include/sdl_helper.h"

#include <string>
#include <math.h>

void heading_indicator::draw(const aircraft& a, const world& w) const
{
    sdl_helper::normal_ellipse_color(x_position, y_position, x_size, y_size, sdl_helper::WHITE);
    double heading = a.get_heading();
    sdl_helper::normal_text(x_position, y_position + y_size / 10, sdl_helper::to_string(heading));

    double theta_offset = (2 * PI * heading / 360.0);

    for (int i = 0; i < 360; i += 30)
    {
        double theta = degrees_to_radians(i - 90) - theta_offset;
        std::string display;
        switch (i)
        {
            case 0:
                display = "N";
            break;
            case 90:
                display = "E";
            break;
            case 180:
                display = "S";
            break;
            case 270:
                display = "W";
            break;
            default:
                display = sdl_helper::to_string(i);
            break;
        }
        sdl_helper::normal_text(
            x_position + radius_for_theta(theta) * cos(theta) * 0.85 - x_size * 0.07,
            y_position + radius_for_theta(theta) * sin(theta) * 0.85 - y_size * 0.08,
            display
        );
    }
    draw_needle(x_position, y_position, 3 * PI / 2, 0.8 * y_size, degrees_to_radians(10), .2, sdl_helper::WHITE);
}

#endif
