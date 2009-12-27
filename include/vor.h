#ifndef __VOR_H
#define __VOR_H

#include "ground_object.h"
#include "aircraft.h"
#include "cdi_information.h"

class vor : public ground_object
{
    private:
        int frequency;

        double compute_actual_radial(const aircraft& a) const;

    public:
        vor() {}
        vor(double xpos, double ypos, double elev, int var, std::string id, int freq) :
            ground_object(xpos, ypos, elev, var, id),
            frequency(freq)
        {}

        int get_frequency() const;
        virtual void draw_moving_map_symbol(double xpos, double ypos, double xsize, double ysize) const;
        virtual cdi_information get_deviation(const aircraft& a, int selected_radial) const;

        static vor nonexistent_vor;
};

#endif
