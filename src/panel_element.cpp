#ifndef __PANEL_ELEMENT_CPP
#define __PANEL_ELEMENT_CPP

#include "../include/panel_element.h"
#include "../include/sdl_helper.h"

#include <math.h>
#include <vector>

void panel_element::draw(const aircraft& a, const world& w)
{
    sdl_helper::normal_ellipse_color(x_position, y_position, x_size, y_size, sdl_helper::RED);
}

double panel_element::radius_for_theta(double theta)
{
    return (x_size * y_size) / sqrt(pow(x_size * sin(theta), 2) + pow(y_size * cos(theta), 2));
}

void panel_element::draw_needle(double x, double y, double theta, double length, double theta_offset, double length_offset, Uint32 color)
{
    double xp[4];
    double yp[4];

    double theta_fix = theta;
    while (theta_fix < 0)
    {
        theta_fix += PI;
    }
    while (theta_fix > PI)
    {
        theta_fix -= PI;
    }

    theta_fix = fabs(cos(theta));
    theta_fix *= (sdl_helper::aspect_ratio()) - 1.0;
    theta_fix += 1;

    theta_offset *= theta_fix;

    xp[0] = x;
    xp[1] = x + length * length_offset * cos(theta - theta_offset);
    xp[2] = x + length * cos(theta);
    xp[3] = x + length * length_offset * cos(theta + theta_offset);

    yp[0] = y;
    yp[1] = y + length * length_offset * sin(theta - theta_offset);
    yp[2] = y + length * sin(theta);
    yp[3] = y + length * length_offset * sin(theta + theta_offset);

    sdl_helper::normal_fillpoly_color(xp, yp, 4, color);
}

double panel_element::degrees_to_radians(double degrees)
{
    return degrees * PI / 180.0;
}

double panel_element::radians_to_degrees(double radians)
{
    return radians * 180.0 / PI;
}

#endif
