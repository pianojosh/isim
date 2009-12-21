#ifndef __VOR_RECEIVER_CPP
#define __VOR_RECEIVER_CPP

#include "../include/vor_receiver.h"
#include "../include/world.h"
#include "../include/vor.h"
#include "../include/cdi_gauge.h"
#include <math.h>

cdi_gauge::cdi_information vor_receiver::get_deviation(int selected_radial, const aircraft& a, const world& w)
{
    cdi_gauge::cdi_information r;
    vor v = w.get_vor_by_frequency(active_frequency);
    if (v.get_frequency() == -1)
    {
        r.flag = true;
        return r;
    }
    double actual_radial = compute_actual_radial(v, a);
    double min_to_radial = selected_radial - 90;
    if (min_to_radial < 0)
    {
        min_to_radial += 360;
    }
    double max_to_radial = selected_radial + 90;
    if (max_to_radial >= 360)
    {
        max_to_radial -= 360;
    }
    if (actual_radial > min_to_radial && actual_radial < max_to_radial)
    {
        r.direction = cdi_gauge::cdi_information::TO;
    }
    else
    {
        r.direction = cdi_gauge::cdi_information::FROM;
    }
    r.deviation = actual_radial - selected_radial;
    return r;
}


double vor_receiver::compute_actual_radial(const vor& v, const aircraft& a)
{
    double theta = atan((a.get_x_position() - v.get_x_position()) / (a.get_y_position() - v.get_y_position()));
    double degrees = 90.0 + radians_to_degrees(theta);
    if (a.get_x_position() < v.get_x_position())
    {
        return 180 + degrees;
    }
    return degrees;
}

#endif
