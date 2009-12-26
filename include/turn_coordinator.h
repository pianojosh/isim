#ifndef __TURN_COORDINATOR_H
#define __TURN_COORDINATOR_H

#include "panel_element.h"

class turn_coordinator : public panel_element
{
    public:
        turn_coordinator() {}
        turn_coordinator(double xpos, double ypos, double xsz, double ysz) :
            panel_element(xpos, ypos, xsz, ysz)
        {}

        virtual void draw(const aircraft& a, const world& w) const;
        virtual ~turn_coordinator() {}
};

#endif
