#ifndef __MANIFOLD_PRESSURE_GAUGE_CPP
#define __MANIFOLD_PRESSURE_GAUGE_CPP

#include "../include/manifold_pressure_gauge.h"

#include "../include/sdl_helper.h"
#include <math.h>

void manifold_pressure_gauge::draw(const aircraft& a, const world& w) const
{
    const double max_power = 28;
    const double min_power = 15;
    const double max_theta = degrees_to_radians(120);
    const double min_theta = degrees_to_radians(0);
    const double theta_offset = degrees_to_radians(-180);

    sdl_helper::normal_ellipse_color(x_position, y_position, x_size, y_size, sdl_helper::WHITE);
    double power_setting = a.get_power_setting();
    sdl_helper::normal_text(x_position, y_position + y_size / 10, sdl_helper::to_string(power_setting));

    double theta = min_theta + theta_offset + (max_theta - min_theta) * (a.get_power_setting() - min_power) / (max_power - min_power);
    draw_needle(x_position, y_position, theta, radius_for_theta(theta), degrees_to_radians(10), 0.3, sdl_helper::WHITE);
}

#endif
