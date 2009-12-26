#ifndef __VERTICAL_SPEED_INDICATOR_CPP
#define __VERTICAL_SPEED_INDICATOR_CPP

#include "../include/vertical_speed_indicator.h"

#include "../include/sdl_helper.h"
#include <math.h>

void vertical_speed_indicator::draw(const aircraft& a, const world& w) const
{
    const double standard_rate_angle = 45;
    const double standard_rate_climb = 500;
    const double angle_fix = 7.10;

    sdl_helper::normal_ellipse_color(x_position, y_position, x_size, y_size, sdl_helper::WHITE);

    double climb_rate = a.get_climb_rate();

    double theta_degrees = (climb_rate / standard_rate_climb) * standard_rate_angle;
    if (theta_degrees > 170)
    {
        theta_degrees = 170;
    }
    if (theta_degrees < -170)
    {
        theta_degrees = -170;
    }
    double theta = degrees_to_radians(theta_degrees);

    sdl_helper::normal_text(x_position, y_position + y_size / 10, sdl_helper::to_string(climb_rate));
    sdl_helper::normal_text(x_position, y_position + y_size / 3, sdl_helper::to_string(theta_degrees));
    sdl_helper::normal_line_color(
        x_position - x_size * 0.8 * cos(degrees_to_radians(standard_rate_angle - angle_fix)),
        y_position - y_size * 0.8 * sin(degrees_to_radians(standard_rate_angle - angle_fix)),
        x_position - x_size * cos(degrees_to_radians(standard_rate_angle - angle_fix)),
        y_position - y_size * sin(degrees_to_radians(standard_rate_angle - angle_fix)),
        sdl_helper::WHITE
    );

    sdl_helper::normal_line_color(
        x_position - x_size * 0.8 * cos(degrees_to_radians(standard_rate_angle - angle_fix)),
        y_position + y_size * 0.8 * sin(degrees_to_radians(standard_rate_angle - angle_fix)),
        x_position - x_size * cos(degrees_to_radians(standard_rate_angle - angle_fix)),
        y_position + y_size * sin(degrees_to_radians(standard_rate_angle - angle_fix)),
        sdl_helper::WHITE
    );

    sdl_helper::normal_line_color(
        x_position + 0.8 * x_size,
        y_position,
        x_position + x_size,
        y_position,
        sdl_helper::WHITE
    );

    sdl_helper::normal_line_color(
        x_position - 0.8 * x_size,
        y_position,
        x_position - x_size,
        y_position,
        sdl_helper::WHITE
    );

    draw_needle(x_position, y_position, theta - PI, radius_for_theta(theta - PI), degrees_to_radians(10), 0.25, sdl_helper::WHITE);
}

#endif
