#ifndef __VOR_H
#define __VOR_H

#include "ground_object.h"

class vor : public ground_object
{
    private:
        int frequency;

    public:
        vor() {}
        vor(double xpos, double ypos, double elev, int var, std::string id, int freq) :
            ground_object(xpos, ypos, elev, var, id),
            frequency(freq)
        {}

        int get_frequency();
        virtual void draw_moving_map_symbol(double xpos, double ypos, double xsize, double ysize);
};

#endif
