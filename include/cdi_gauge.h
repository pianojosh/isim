#ifndef __CDI_GAUGE_H
#define __CDI_GAUGE_H

#include "vor_receiver.h"

class vor_receiver;

class cdi_gauge : public panel_element
{
    private:
        int selected_course;
        vor_receiver &receiver;

    public:
        cdi_gauge(int xpos, int ypos, int xsz, int ysz, vor_receiver &vor) :
            panel_element(xpos, ypos, xsz, ysz),
            receiver(vor)
        {}

        virtual void draw(const aircraft& a, const world& w);

        struct cdi_information
        {
            bool flag;
            enum {TO, FROM} direction;
            double deviation;
        };
};

#endif
