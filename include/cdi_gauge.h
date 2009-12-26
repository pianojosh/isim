#ifndef __CDI_GAUGE_H
#define __CDI_GAUGE_H

#include "vor_receiver.h"
#include "panel_element.h"

class vor_receiver;

class cdi_gauge : public panel_element
{
    private:
        int selected_course;
        const vor_receiver &receiver;

    public:
        cdi_gauge(double xpos, double ypos, double xsz, double ysz, const vor_receiver &vor) :
            panel_element(xpos, ypos, xsz, ysz),
            selected_course(360),
            receiver(vor)
        {}

        virtual void draw(const aircraft& a, const world& w) const;

        int get_selected_course() const;
        void set_selected_course(int c);
};

#endif
