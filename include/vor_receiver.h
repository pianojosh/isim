#ifndef __VOR_RECEIVER_H
#define __VOR_RECEIVER_H

#include "panel_element.h"
#include "world.h"

class vor_receiver : public panel_element
{
    private:
        int active_frequency;
        int standby_frequency;

    public:
        vor_receiver() {}

        vor_receiver(double xpos, double ypos, double xsz, double ysz) :
            panel_element(xpos, ypos, xsz, ysz),
            active_frequency(11250),
            standby_frequency(11440)
        {}

        double get_deviation(int selected_heading, const world& w);
};

#endif
