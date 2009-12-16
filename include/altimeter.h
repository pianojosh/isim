#ifndef __ALTIMETER_H
#define __ALTIMETER_H

#include "../include/panel_element.h"

class altimeter : public panel_element
{
    public:
        altimeter(double xpos, double ypos, double xsz, double ysz) :
            panel_element(xpos, ypos, xsz, ysz)
        {}
        virtual ~altimeter() {}

        virtual void draw(const aircraft& a, const world& w);
};

#endif
