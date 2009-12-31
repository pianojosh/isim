#ifndef __AIRPORT_H
#define __AIRPORT_H

#include "runway.h"

#include <string>
#include <vector>

using std::vector;

class airport : public ground_object
{
    private:
        double size;
        vector<runway> runways;

    public:
        airport() {}
        airport(double xpos, double ypos, double elev, int var, std::string id, double s) :
            ground_object(xpos, ypos, elev, var, id),
            size(s)
        {}
        virtual ~airport() {}

        virtual void draw_moving_map_symbol(double xpos, double ypos, double xsize, double ysize) const;
};

#endif
