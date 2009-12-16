#ifndef __ILS_GAUGE_H
#define __ILS_GAUGE_H

#include "cdi_gauge.h"
#include "vor_receiver.h"

class ils_gauge : public cdi_gauge
{
    public:
        ils_gauge(int xpos, int ypos, int xsz, int ysz, vor_receiver &vor) :
            cdi_gauge(xpos, ypos, xsz, ysz, vor)
        {}
};

#endif
