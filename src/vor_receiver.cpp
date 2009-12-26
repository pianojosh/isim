#ifndef __VOR_RECEIVER_CPP
#define __VOR_RECEIVER_CPP

#include "../include/vor_receiver.h"
#include "../include/world.h"
#include "../include/vor.h"
#include "../include/cdi_gauge.h"
#include "../include/sdl_helper.h"
#include "../include/cdi_information.h"

#include <math.h>

int vor_receiver::get_standby_frequency() const
{
    return standby_frequency;
}

void vor_receiver::set_standby_frequency(int f)
{
    standby_frequency = f;
}

void vor_receiver::swap_frequencies()
{
    int t = standby_frequency;
    standby_frequency = active_frequency;
    active_frequency = t;
}

void vor_receiver::draw(const aircraft& a, const world& w) const
{
    sdl_helper::normal_rect_color(x_position, y_position, x_position + x_size, y_position + y_size, sdl_helper::WHITE);
    sdl_helper::normal_text(
        x_position + x_size * 0.1,
        y_position + y_size * 0.4,
            sdl_helper::to_string(active_frequency / 100) +
            "." +
            sdl_helper::to_string(active_frequency % 100) +
            " < - > " +
            sdl_helper::to_string(standby_frequency / 100) +
            "." +
            sdl_helper::to_string(standby_frequency % 100)

    );
    sdl_helper::normal_rect_color(
        x_position + x_size * 0.265,
        y_position + y_size * 0.34,
        x_position + x_size * 0.41,
        y_position + y_size * 0.6,
        sdl_helper::WHITE
    );
}

cdi_information vor_receiver::get_deviation(int selected_radial, const aircraft& a, const world& w) const
{
    cdi_information r;
    vor v = w.get_vor_by_frequency(active_frequency);
    if (v.get_frequency() == -1)
    {
        r.flag = true;
        return r;
    }
    double actual_radial = compute_actual_radial(v, a);
    sdl_helper::normal_text(0.05, 0.05, "ACTRAD: " + sdl_helper::to_string(actual_radial));
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

double vor_receiver::compute_actual_radial(const vor& v, const aircraft& a) const
{
    double theta = atan(fabs(a.get_x_position() - v.get_x_position()) / fabs(a.get_y_position() - v.get_y_position()));
    double degrees = radians_to_degrees(theta);
    if ((a.get_x_position() > v.get_x_position()) && a.get_y_position() < v.get_y_position())
    {
        degrees = 180 - degrees;
        sdl_helper::normal_text(0.05, 0.15, "CASE1");
    }
    else if ((a.get_x_position() > v.get_x_position()) && a.get_y_position() > v.get_y_position())
    {
        degrees = degrees;
        sdl_helper::normal_text(0.05, 0.15, "CASE2");
    }
    else if ((a.get_x_position() < v.get_x_position()) && a.get_y_position() > v.get_y_position())
    {
        degrees = 360 - degrees;
        sdl_helper::normal_text(0.05, 0.15, "CASE3");
    }
    else
    {
        degrees = 180 + degrees;
        sdl_helper::normal_text(0.05, 0.15, "CASE4");
    }
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
