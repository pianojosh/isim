#ifndef __VOR_RECEIVER_H
#define __VOR_RECEIVER_H

#include "panel_element.h"

class vor_receiver : public panel_element
{
    private:
        int active_frequency;
        int standby_frequency;
        
    public:
        vor_receiver() {}
        
        vor_receiver(int xpos, int ypos, int xsz, int ysz) :
            panel_element(xpos, ypos, xsz, ysz),
            active_frequency(11000),
            standby_frequency(11015)
        {}
};

#endif
