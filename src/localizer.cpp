#ifndef __LOCALIZER_CPP
#define __LOCALIZER_CPP

#include "../include/localizer.h"
#include "../include/sdl_helper.h"
#include "../include/cdi_information.h"
#include "../include/panel_element.h"
#include <math.h>

void localizer::draw_moving_map_symbol(double xpos, double ypos, double xsize, double ysize) const
{
    xsize *= moving_map_size_factor();
    ysize *= moving_map_size_factor();

    sdl_helper::normal_line_color(
        xpos,
        ypos,
        xpos - 5 * xsize * sin(panel_element::degrees_to_radians(direction + 2 * get_variation())),
        ypos - 5 * ysize * cos(panel_element::degrees_to_radians(direction + 2 * get_variation())),
        sdl_helper::WHITE
    );
}

cdi_information localizer::get_deviation(const aircraft& a, int selected_radial) const
{
    sdl_helper::normal_text(0.05, 0.05, "localizer::get_deviation");
    cdi_information i = vor::get_deviation(a, direction);
    i.deviation = i.deviation * 10.0 / beam_width;
    if (i.deviation > 90.0)
    {
        i.deviation = 90.0;
    }
    else if (i.deviation < -90.0)
    {
        i.deviation = -90.0;
    }
    return i;
}
#endif
