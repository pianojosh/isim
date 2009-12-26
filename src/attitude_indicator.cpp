#ifndef __ATTITUDE_INDICATOR_CPP
#define __ATTITUDE_INDICATOR_CPP

#include "../include/attitude_indicator.h"
#include "../include/sdl_helper.h"

#include <math.h>

void attitude_indicator::draw(const aircraft& a, const world& w) const
{
    // special thanks to Rebecca Sobel for deriving the formulas for this
    // these can probably be simplified
    double omega = -a.get_bank_angle();
    double phi = a.get_pitch_angle();

    if (phi < -40.0)
    {
        phi = -40.0;
    }
    else if (phi > 40.0)
    {
        phi = 40.0;
    }

    if (omega < -65.0)
    {
        omega = -65.0;
    }
    else if (omega > 65.0)
    {
        omega = 65.0;
    }
    double upsilon = y_size * omega / 100.0;

    double alpha = phi + 90.0;
    double beta = radians_to_degrees(asin(upsilon * sin(degrees_to_radians(alpha)) / x_size));
    double gamma = 180.0 - beta - phi - 90.0;
    double delta = 90 - gamma;
    double x_max = x_position + x_size * cos(degrees_to_radians(delta));
    double y_max = y_position + y_size * sin(degrees_to_radians(delta));

    double epsilon = 90 - phi;
    double zeta = radians_to_degrees(asin(upsilon * sin(degrees_to_radians(epsilon)) / x_size));
    double kappa = 180 - epsilon - zeta;
    double lambda = kappa - 90;
    double x_min = x_position - x_size * cos(degrees_to_radians(lambda));
    double y_min = y_position + y_size * sin(degrees_to_radians(lambda));

    sdl_helper::normal_ellipse_color(x_position, y_position, x_size, y_size, sdl_helper::BLUE);
    sdl_helper::normal_line_color(x_min, y_min, x_max, y_max, sdl_helper::BLUE);
    sdl_helper::normal_floodfill_color(x_position, y_position - y_size * 0.9, sdl_helper::BLUE);
    sdl_helper::normal_ellipse_color(x_position, y_position, x_size, y_size, sdl_helper::BROWN);
    sdl_helper::normal_line_color(x_min, y_min, x_max, y_max, sdl_helper::BROWN);
    sdl_helper::normal_floodfill_color(x_position, y_position + y_size * 0.9, sdl_helper::BROWN);
    sdl_helper::normal_ellipse_color(x_position, y_position, x_size, y_size, sdl_helper::WHITE);
    sdl_helper::normal_line_color(x_position - x_size * 0.4, y_position + y_size * 0.05, x_position, y_position, sdl_helper::WHITE);
    sdl_helper::normal_line_color(x_position, y_position, x_position + x_size * 0.4, y_position + y_size * 0.05, sdl_helper::WHITE);

    sdl_helper::normal_text(x_position - x_size * 0.333, y_position + y_size * 0.15, "PITCH:" + sdl_helper::to_string(a.get_pitch_angle()));
    sdl_helper::normal_text(x_position - x_size * 0.333, y_position + y_size * 0.30, "BANK: " + sdl_helper::to_string(a.get_bank_angle()));
}

#endif
