#ifndef __PANEL_ELEMENT_H
#define __PANEL_ELEMENT_H

#include "panel.h"

class panel_element
{
    protected:
        double x_position;
        double y_position;
        double x_size;
        double y_size;

        void draw_needle(double x, double y, double theta, double length, double theta_offset, double length_offset, Uint32 color);
        double radius_for_theta(double theta);

    public:
        panel_element() {}

        panel_element(double xpos, double ypos, double xsz, double ysz) :
            x_position(xpos),
            y_position(ypos),
            x_size(xsz),
            y_size(ysz)
        {}

        //children can implement whichever of these is appropriate
        virtual void draw(const aircraft& a, const world& w);

        static double degrees_to_radians(double degrees);
        static double radians_to_degrees(double radians);

};

#endif
