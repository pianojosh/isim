#ifndef __TURN_COORDINATOR_CPP
#define __TURN_COORDINATOR_CPP

#include "../include/turn_coordinator.h"
#include "../include/sdl_helper.h"

#include <math.h>

void turn_coordinator::draw(const aircraft& a, const world& w)
{
    const double standard_rate_angle = 30;
    const double standard_rate_turn = 3;
    const double angle_fix = 5.75;

    sdl_helper::normal_ellipse_color(x_position, y_position, x_size, y_size, sdl_helper::WHITE);

    double turn_rate = a.get_turn_rate();

    double theta_degrees = (turn_rate / standard_rate_turn) * standard_rate_angle;
    if (theta_degrees > 60)
    {
        theta_degrees = 60;
    }
    if (theta_degrees < -60)
    {
        theta_degrees = -60;
    }
    double theta = degrees_to_radians(theta_degrees);

    sdl_helper::normal_text(x_position, y_position + y_size / 10, sdl_helper::to_string(turn_rate));
    sdl_helper::normal_text(x_position, y_position + y_size / 3, sdl_helper::to_string(theta_degrees));
    sdl_helper::normal_line_color(
        x_position + x_size * 0.8 * cos(degrees_to_radians(standard_rate_angle - angle_fix)),
        y_position + y_size * 0.8 * sin(degrees_to_radians(standard_rate_angle - angle_fix)),
        x_position + x_size * cos(degrees_to_radians(standard_rate_angle - angle_fix)),
        y_position + y_size * sin(degrees_to_radians(standard_rate_angle - angle_fix)),
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

    draw_needle(x_position, y_position, theta, radius_for_theta(theta), 5, 0.0, sdl_helper::WHITE);
    draw_needle(x_position, y_position, theta + PI, radius_for_theta(theta + PI), 5, 0.0, sdl_helper::WHITE);
}

#endif
