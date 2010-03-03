#ifndef __LOCALIZER_H
#define __LOCALIZER_H

#include <string>
#include "vor.h"
#include "cdi_information.h"

class localizer : public vor
{
    private:
        int frequency;
        int direction;
        double beam_width;

    public:
        localizer() {}
        localizer(double xpos, double ypos, double elev, int var, std::string id, int freq, int dir) :
            vor(xpos, ypos, elev, var, id, freq),
            direction(dir),
            beam_width(5.0)
        {}

        localizer(double xpos, double ypos, double elev, int var, std::string id, int freq, int dir, double width) :
            vor(xpos, ypos, elev, var, id, freq),
            direction(dir),
            beam_width(width)
        {}

        virtual void draw_moving_map_symbol(double xpos, double ypos, double xsize, double ysize) const;
        virtual cdi_information get_deviation(const aircraft& a, int selected_radial) const;
};

#endif
