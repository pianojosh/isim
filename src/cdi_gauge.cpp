#ifndef __CDI_GAUGE_CPP
#define __CDI_GAUGE_CPP

#include "../include/cdi_gauge.h"
#include "../include/sdl_helper.h"
#include "../include/cdi_information.h"
#include <math.h>

void cdi_gauge::draw(const aircraft& a, const world& w) const
{
    const double MAX_DEFLECTION_DEVIATION = 10.0;
    const double MAX_DEFLECTION_ANGLE = 25.0;

    cdi_information deviation_info = receiver.get_deviation(selected_course, a, w);

    sdl_helper::normal_ellipse_color(x_position, y_position, x_size, y_size, sdl_helper::WHITE);

    if (deviation_info.flag == true)
    {
        sdl_helper::normal_text(x_position, y_position, "NAV FLAGGED");
    }
    else
    {
        sdl_helper::normal_text(x_position, y_position - y_size * 0.75, sdl_helper::to_string(selected_course));
        sdl_helper::normal_text(x_position, y_position, sdl_helper::to_string(deviation_info.deviation));
        sdl_helper::normal_text(
            x_position,
            y_position + y_size * 0.4,
            (deviation_info.direction == cdi_information::TO ? "TO" : "FROM" )
        );

        double display_deviation = deviation_info.deviation;
        if (display_deviation > MAX_DEFLECTION_DEVIATION)
        {
            display_deviation = MAX_DEFLECTION_DEVIATION;
        }
        if (display_deviation < -MAX_DEFLECTION_DEVIATION)
        {
            display_deviation = -MAX_DEFLECTION_DEVIATION;
        }
        double needle_angle = 90 + display_deviation * (MAX_DEFLECTION_ANGLE / MAX_DEFLECTION_DEVIATION);
        draw_needle(
            x_position,
            y_position - y_size,
            degrees_to_radians(needle_angle),
            y_size * 1.6,
            degrees_to_radians(5),
            0.05,
            sdl_helper::WHITE
        );

        double max_dot_x = sin(degrees_to_radians(MAX_DEFLECTION_ANGLE)) * y_size / sin(degrees_to_radians(90.0 - MAX_DEFLECTION_ANGLE));
        double min_dot_x = -max_dot_x;
        for (double d = min_dot_x; d <= max_dot_x; d += ((max_dot_x - min_dot_x) / 10.0))
        {
            sdl_helper::normal_ellipse_color(x_position + d, y_position, x_size * 0.005, y_size * 0.005, sdl_helper::WHITE);
        }
    }
}

int cdi_gauge::get_selected_course() const
{
    return selected_course;
}

void cdi_gauge::set_selected_course(int c)
{
    selected_course = c;
}

#endif
