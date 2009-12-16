#ifndef __HEADING_INDICATOR_H
#define __HEADING_INDICATOR_H

#include "panel_element.h"

class heading_indicator : public panel_element
{
    public:
        heading_indicator() {}
        heading_indicator(double xpos, double ypos, double xsz, double ysz) :
            panel_element(xpos, ypos, xsz, ysz)
        {}

        virtual void draw(const aircraft& a, const world& w);
        virtual ~heading_indicator() {}
};

#endif
