#ifndef __ATTITUDE_INDICATOR_H
#define __ATTITUDE_INDICATOR_H

#include "aircraft.h"
#include "panel_element.h"
#include "world.h"

class attitude_indicator : public panel_element
{
    public:
        attitude_indicator() {}
        attitude_indicator(double xpos, double ypos, double xsz, double ysz) :
            panel_element(xpos, ypos, xsz, ysz)
        {}

        virtual void draw(const aircraft& a, const world& w);
};

#endif
