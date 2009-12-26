#ifndef __VOR_RECEIVER_H
#define __VOR_RECEIVER_H

#include "panel_element.h"
#include "world.h"
#include "cdi_gauge.h"
#include "cdi_information.h"

class vor_receiver : public panel_element
{
    private:
        int active_frequency;
        int standby_frequency;

        double compute_actual_radial(const vor& v, const aircraft& a) const;

    public:
        vor_receiver() {}

        vor_receiver(double xpos, double ypos, double xsz, double ysz) :
            panel_element(xpos, ypos, xsz, ysz),
            active_frequency(11250),
            standby_frequency(11440)
        {}

        virtual void draw(const aircraft& a, const world& w) const;

        cdi_information get_deviation(int selected_heading, const aircraft& a, const world& w) const;
};

#endif
