#ifndef __CDI_GAUGE_CPP
#define __CDI_GAUGE_CPP

#include "../include/cdi_gauge.h"
#include "../include/sdl_helper.h"
#include "../include/cdi_information.h"

void cdi_gauge::draw(const aircraft& a, const world& w) const
{
    const double MAX_DEFLECTION_DEVIATION = 10.0;
    const double MAX_DEFLECTION_ANGLE = 30.0;

    cdi_information deviation_info = receiver.get_deviation(20, a, w);
    sdl_helper::normal_ellipse_color(x_position, y_position, x_size, y_size, sdl_helper::WHITE);
    sdl_helper::normal_text(x_position, y_position, sdl_helper::to_string(deviation_info.deviation));
    sdl_helper::normal_text(x_position, y_position + y_size * 0.2, sdl_helper::to_string(deviation_info.direction));
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
        y_size,
        degrees_to_radians(5),
        0.05,
        sdl_helper::WHITE
    );
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
