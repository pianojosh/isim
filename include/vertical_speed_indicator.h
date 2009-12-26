#ifndef __VERTICAL_SPEED_INDICATOR_H
#define __VERTICAL_SPEED_INDICATOR_H

#include "panel_element.h"

class vertical_speed_indicator : public panel_element
{
    public:
        vertical_speed_indicator();
        vertical_speed_indicator(double xpos, double ypos, double xsz, double ysz) :
            panel_element(xpos, ypos, xsz, ysz)
        {}

        virtual void draw(const aircraft& a, const world& w) const;
        virtual ~vertical_speed_indicator() {}
};

#endif
