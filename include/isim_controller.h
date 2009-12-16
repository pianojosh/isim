#ifndef __ISIM_CONTROLLER_H
#define __ISIM_CONTROLLER_H

#include <SDL.h>

#include "aircraft.h"
#include "panel.h"
#include "panel_element.h"
#include "vor_receiver.h"
#include "adf_receiver.h"
#include "cdi_gauge.h"
#include "adf_gauge.h"
#include "ils_gauge.h"
#include "ground_object.h"
#include "ndb.h"
#include "vor.h"
#include "localizer.h"
#include "ils.h"
#include "airport.h"
#include "runway.h"
#include "world.h"

class isim_controller
{
    private:
        world isim_world;
        aircraft isim_aircraft;
        panel isim_panel;

        void initialize_video();

        void step();
        void draw();

        Uint32 last_frame_tick;

    public:
        isim_controller() {}
        void initialize();
        void print_world_state();
        void run();
};

#endif
