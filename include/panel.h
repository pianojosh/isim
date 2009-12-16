#ifndef __PANEL_H
#define __PANEL_H

#include <map>
#include "aircraft.h"
#include "world.h"

using std::map;

class panel_element;

class panel
{
    private:
        map<int, panel_element*> elements;

        enum {
            AIRSPEED_INDICATOR = 1,
            ATTITUDE_INDICATOR = 2,
            ALTIMETER = 3,
            VOR_1_CDI = 4,
            TURN_COORDINATOR = 5,
            HEADING_INDICATOR = 6,
            VERTICAL_SPEED_INDICATOR = 7,
            VOR_2_CDI = 8,
            ADF_GAUGE = 9,
            MANIFOLD_PRESSURE_GAUGE = 10,
            MARKER_RADIO = 11,
            VOR_1_RADIO = 12,
            VOR_2_RADIO = 13,
            ADF_RADIO = 14
        };

    public:
        panel() {}

        void initialize();
        void draw(const aircraft& a, const world& w);
};

#endif
