#ifndef __AIRPORT_H
#define __AIRPORT_H

#include "runway.h"

#include <string>
#include <vector>

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
};

#endif
