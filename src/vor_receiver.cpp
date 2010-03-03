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
    const vor &v = w.get_vor_by_frequency(active_frequency);
    if (v.get_frequency() == -1)
    {
        r.flag = true;
        return r;
    }
    return v.get_deviation(a, selected_radial);
}

#endif
