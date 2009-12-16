#ifndef __AIRSPEED_INDICATOR_H
#define __AIRSPEED_INDICATOR_H

#include "panel_element.h"

class airspeed_indicator : public panel_element
{
    private:
        int min_speed;
        int max_speed;

    public:
        airspeed_indicator() {}
        airspeed_indicator(double xpos, double ypos, double xsz, double ysz, int ls, int hs) :
            panel_element(xpos, ypos, xsz, ysz),
            min_speed(ls),
            max_speed(hs)
        {}

        virtual void draw(const aircraft& a, const world& w);

        virtual ~airspeed_indicator() {}
};

#endif
