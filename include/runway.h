#ifndef __RUNWAY_H
#define __RUNWAY_H

#include <string>
#include "../include/ground_object.h"

using std::string;

class runway : public ground_object
{
    private:
        int heading;
        int length;
        int width;

    public:
        runway() {}
        runway(double xpos, double ypos, double elev, int var, string id, int hdg, int lgth, int wdth) :
            ground_object(xpos, ypos, elev, var, id),
            heading(hdg),
            length(lgth),
            width(wdth)
        {}
        virtual ~runway() {}
};

#endif
