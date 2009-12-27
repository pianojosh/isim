#ifndef __ISIM_CONTROLLER_CPP
#define __ISIM_CONTROLLER_CPP

#include "../include/isim_controller.h"
#include "../include/sdl_helper.h"
#include "../include/cdi_gauge.h"
#include "../include/panel.h"

#include <iostream>
#include <string>
#include <SDL.h>
#include "sge.h"
#include <ctime>
#include <map>

using std::cout;
using std::endl;

void isim_controller::initialize_keys_pressed()
{
    keys_pressed[SDLK_UP] = false;
    keys_pressed[SDLK_DOWN] = false;
    keys_pressed[SDLK_LEFT] = false;
    keys_pressed[SDLK_RIGHT] = false;
    keys_pressed[SDLK_z] = false;
    keys_pressed[SDLK_x] = false;
    keys_pressed[SDLK_RIGHTBRACKET] = false;
    keys_pressed[SDLK_LEFTBRACKET] = false;
    keys_pressed[SDLK_p] = false;
    keys_pressed[SDLK_o] = false;
    keys_pressed[SDLK_i] = false;
    keys_pressed[SDLK_y] = false;
    keys_pressed[SDLK_u] = false;
}

void isim_controller::initialize_key_actions()
{
    key_actions[SDLK_UP] = key_press_pitch_down;
    key_actions[SDLK_DOWN] = key_press_pitch_up;
    key_actions[SDLK_LEFT] = key_press_bank_left;
    key_actions[SDLK_RIGHT] = key_press_bank_right;
    key_actions[SDLK_z] = key_press_power_down;
    key_actions[SDLK_x] = key_press_power_up;
    key_actions[SDLK_RIGHTBRACKET] = key_press_vor1_broad_freq_up;
    key_actions[SDLK_LEFTBRACKET] = key_press_vor1_fine_freq_up;
    key_actions[SDLK_p] = key_press_vor1_fine_freq_down;
    key_actions[SDLK_o] = key_press_vor1_broad_freq_down;
    key_actions[SDLK_i] = key_press_vor1_swap_frequencies;
    key_actions[SDLK_y] = key_press_cdi1_course_left;
    key_actions[SDLK_u] = key_press_cdi1_course_right;
}

void isim_controller::key_press_cdi1_course_left(isim_controller& c)
{
    cdi_gauge& g = dynamic_cast<cdi_gauge&>(c.isim_panel.get_element(panel::VOR_1_CDI));
    int course = g.get_selected_course();
    course--;
    if (course <= 0)
    {
        course = 360;
    }
    g.set_selected_course(course);
}

void isim_controller::key_press_cdi1_course_right(isim_controller& c)
{
    cdi_gauge& g = dynamic_cast<cdi_gauge&>(c.isim_panel.get_element(panel::VOR_1_CDI));
    int course = g.get_selected_course();
    course++;
    if (course > 360)
    {
        course = 1;
    }
    g.set_selected_course(course);
}

void isim_controller::key_press_vor1_broad_freq_down(isim_controller& c)
{
    int freq = c.isim_panel.get_vor_frequency(1);
    int freq_fine = freq % 100;
    int freq_broad = 100 * (freq / 100);
    freq_broad -= 100;
    if (freq_broad < 10800)
    {
        freq_broad = 11700;
    }
    c.isim_panel.set_vor_frequency(1, freq_broad + freq_fine);
    c.keys_pressed[SDLK_o] = false;
}

void isim_controller::key_press_vor1_broad_freq_up(isim_controller& c)
{
    int freq = c.isim_panel.get_vor_frequency(1);
    int freq_fine = freq % 100;
    int freq_broad = 100 * (freq / 100);
    freq_broad += 100;
    if (freq_broad > 11700)
    {
        freq_broad = 10800;
    }
    c.isim_panel.set_vor_frequency(1, freq_broad + freq_fine);
    c.keys_pressed[SDLK_RIGHTBRACKET] = false;
}

void isim_controller::key_press_vor1_fine_freq_down(isim_controller& c)
{
    int freq = c.isim_panel.get_vor_frequency(1);
    int freq_fine = freq % 100;
    int freq_broad = 100 * (freq / 100);
    freq_fine -= 5;
    if (freq_fine < 0)
    {
        freq_fine = 95;
    }
    c.isim_panel.set_vor_frequency(1, freq_broad + freq_fine);
    c.keys_pressed[SDLK_p] = false;
}

void isim_controller::key_press_vor1_fine_freq_up(isim_controller& c)
{
    int freq = c.isim_panel.get_vor_frequency(1);
    int freq_fine = freq % 100;
    int freq_broad = 100 * (freq / 100);
    freq_fine += 5;
    if (freq_fine > 95)
    {
        freq_fine = 0;
    }
    c.isim_panel.set_vor_frequency(1, freq_broad + freq_fine);
    c.keys_pressed[SDLK_LEFTBRACKET] = false;
}

void isim_controller::key_press_vor1_swap_frequencies(isim_controller& c)
{
    c.isim_panel.swap_vor_frequencies(1);
    c.keys_pressed[SDLK_i] = false;
}

void isim_controller::key_press_bank_left(isim_controller& c)
{
    c.isim_aircraft.set_bank_angle(c.isim_aircraft.get_bank_angle() - 0.12);
}

void isim_controller::key_press_bank_right(isim_controller& c)
{
    c.isim_aircraft.set_bank_angle(c.isim_aircraft.get_bank_angle() + 0.12);
}

void isim_controller::key_press_power_down(isim_controller& c)
{
    double new_power_setting = c.isim_aircraft.get_power_setting() - 0.01;
    if (new_power_setting < 15)
    {
        new_power_setting = 15;
    }
    c.isim_aircraft.set_power_setting(new_power_setting);
}

void isim_controller::key_press_power_up(isim_controller& c)
{
    double new_power_setting = c.isim_aircraft.get_power_setting() + 0.01;
    if (new_power_setting > 28)
    {
        new_power_setting = 28;
    }
    c.isim_aircraft.set_power_setting(new_power_setting);
}

void isim_controller::key_press_pitch_down(isim_controller& c)
{
    c.isim_aircraft.set_pitch_angle(c.isim_aircraft.get_pitch_angle() - 0.05);
}

void isim_controller::key_press_pitch_up(isim_controller& c)
{
    c.isim_aircraft.set_pitch_angle(c.isim_aircraft.get_pitch_angle() + 0.05);
}

void isim_controller::run()
{
    bool done = false;

    while (!done)
    {
        // message processing loop
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
                case SDL_QUIT:
                    done = true;
                break;

                // check for keypresses
                case SDL_KEYDOWN:
                    // exit if ESCAPE is pressed
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            done = true;
                        break;
                        default:
                            if (keys_pressed.count(event.key.keysym.sym) > 0)
                            {
                                keys_pressed[event.key.keysym.sym] = true;
                            }
                        break;
                    }
                break;

                case SDL_KEYUP:
                    if (keys_pressed.count(event.key.keysym.sym) > 0)
                    {
                        keys_pressed[event.key.keysym.sym] = false;
                    }
                break;

            }
        }

        map<int, bool>::iterator i;
        for (i = keys_pressed.begin(); i != keys_pressed.end(); i++)
        {
            if (i->second)
            {
                key_actions[i->first](*this);
            }
        }

        step();
        draw();
    }
}

void isim_controller::step()
{
    static std::clock_t last_tick = 0;
    if (last_tick == 0)
    {
        last_tick = std::clock();
    }
    else
    {
        std::clock_t this_tick = std::clock();
        //std::cout << last_tick << " " << this_tick << " " << CLOCKS_PER_SEC << std::endl;
        int step_millis = (int)((double)(this_tick - last_tick) / (CLOCKS_PER_SEC / 1000.0));
        if (step_millis > 0)
        {
            isim_aircraft.simulate(step_millis);
            last_tick = this_tick;
        }
    }
}

void isim_controller::draw()
{
    // clear screen
    sdl_helper::normal_fill_rect_color(0, 0, 1, 1, sdl_helper::BLACK);
    isim_panel.draw(isim_aircraft, isim_world);

    sdl_helper::flip();
}

void isim_controller::initialize()
{
    initialize_video();
    //10% padding around vors below
    isim_world.set_dimensions(
        -72.1808091,
        -70.7093665,
        42.2847487,
        43.1571638
    );

    vor* v1 = new vor(-70.9895472, 42.3574500, 20, -16, "BOS", 11270);
    vor* v2 = new vor(-71.0948419, 42.7404156, 302, -15, "LWM", 11250);
    vor* v3 = new vor(-71.3695447, 42.8685317, 469, -15, "MHT", 11440);
    vor* v4 = new vor(-70.8319867, 43.0844625, 99, -16, "PSM", 11650);
    vor* v5 = new vor(-72.0581889, 42.5459500, 1280, -14, "GDM", 11060);

    isim_world.add_object(v1);
    isim_world.add_object(v2);
    isim_world.add_object(v3);
    isim_world.add_object(v4);
    isim_world.add_object(v5);

    isim_world.finalize_objects();

    isim_panel.initialize();

    isim_aircraft.set_airspeed(90);
    isim_aircraft.set_altitude(2000);
    isim_aircraft.set_power_setting(25);
    isim_aircraft.set_x_position(-71.2890300);
    isim_aircraft.set_y_position(42.4699531);

    initialize_keys_pressed();
    initialize_key_actions();
}

void isim_controller::initialize_video()
{
    sdl_helper::initialize();
}


#endif
