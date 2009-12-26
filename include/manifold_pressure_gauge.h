#ifndef __MANIFOLD_PRESSURE_GAUGE_H
#define __MANIFOLD_PRESSURE_GAUGE_H

#include "panel_element.h"

class manifold_pressure_gauge : public panel_element
{
    public:
        manifold_pressure_gauge();
        manifold_pressure_gauge(double xpos, double ypos, double xsz, double ysz) :
            panel_element(xpos, ypos, xsz, ysz)
        {}

        virtual void draw(const aircraft& a, const world& w) const;
        virtual ~manifold_pressure_gauge() {}
};

#endif
