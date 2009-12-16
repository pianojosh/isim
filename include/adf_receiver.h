#ifndef __ADF_RECEIVER_H
#define __ADF_RECEIVER_H

#include "panel_element.h"

class adf_receiver : public panel_element
{
    private:
        int channel;
        
    public:
        adf_receiver() {}
        
        adf_receiver(int xpos, int ypos, int xsz, int ysz) :
            panel_element(xpos, ypos, xsz, ysz),
            channel(123)
        {}
};

#endif
