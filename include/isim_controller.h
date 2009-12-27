#ifndef __ISIM_CONTROLLER_H
#define __ISIM_CONTROLLER_H

#include <SDL.h>

#include "aircraft.h"
#include "panel.h"
#include "panel_element.h"
//#include "vor_receiver.h"
//#include "adf_receiver.h"
#include "cdi_gauge.h"
//#include "adf_gauge.h"
//#include "ils_gauge.h"
#include "ground_object.h"
//#include "ndb.h"
#include "vor.h"
//#include "localizer.h"
//#include "ils.h"
//#include "airport.h"
//#include "runway.h"
#include "world.h"

class isim_controller
{
    private:
        world isim_world;
        aircraft isim_aircraft;
        panel isim_panel;

        map<int, bool> keys_pressed;
        map<int, void(*)(isim_controller&) > key_actions;
        map<int, int> key_delay;
        map<int, int> delay_values;

        void initialize_video();

        void step();
        void draw();
        void initialize_keys_pressed();
        void initialize_key_actions();
        void decrease_key_delays(int step_millis);

        Uint32 last_frame_tick;

        static void key_press_pitch_down(isim_controller& c);
        static void key_press_pitch_up(isim_controller& c);
        static void key_press_bank_left(isim_controller& c);
        static void key_press_bank_right(isim_controller& c);
        static void key_press_power_down(isim_controller& c);
        static void key_press_power_up(isim_controller& c);
        static void key_press_vor1_broad_freq_up(isim_controller& c);
        static void key_press_vor1_broad_freq_down(isim_controller& c);
        static void key_press_vor1_fine_freq_up(isim_controller& c);
        static void key_press_vor1_fine_freq_down(isim_controller& c);
        static void key_press_vor1_swap_frequencies(isim_controller& c);
        static void key_press_vor2_broad_freq_up(isim_controller& c);
        static void key_press_vor2_broad_freq_down(isim_controller& c);
        static void key_press_vor2_fine_freq_up(isim_controller& c);
        static void key_press_vor2_fine_freq_down(isim_controller& c);
        static void key_press_vor2_swap_frequencies(isim_controller& c);
        static void key_press_cdi1_course_left(isim_controller& c);
        static void key_press_cdi1_course_right(isim_controller& c);
        static void key_press_cdi2_course_left(isim_controller& c);
        static void key_press_cdi2_course_right(isim_controller& c);



    public:
        isim_controller() {}
        void initialize();
        void run();
};

#endif

