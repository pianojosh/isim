#ifndef __PANEL_CPP
#define __PANEL_CPP

#include "../include/panel.h"
#include "../include/world.h"

#include "../include/sdl_helper.h"
#include "../include/panel_element.h"

#include "../include/airspeed_indicator.h"
#include "../include/attitude_indicator.h"
#include "../include/altimeter.h"
#include "../include/turn_coordinator.h"
#include "../include/heading_indicator.h"
#include "../include/vertical_speed_indicator.h"
#include "../include/manifold_pressure_gauge.h"
#include "../include/vor_receiver.h"

#include <map>

panel_element& panel::get_element(int e)
{
    return *elements[e];
}

void panel::set_vor_frequency(int v, int f)
{
    int key = (v == 1 ? VOR_1_RADIO : VOR_2_RADIO);
    vor_receiver& r = dynamic_cast<vor_receiver&>(*elements[key]);
    r.set_standby_frequency(f);
}

int panel::get_vor_frequency(int v) const
{
    int key = (v == 1 ? VOR_1_RADIO : VOR_2_RADIO);
    //syntax is annoying, but std::map's operator[] doesn't have a const version
    vor_receiver& r = dynamic_cast<vor_receiver&>(*elements.find(key)->second);
    return r.get_standby_frequency();
}

void panel::swap_vor_frequencies(int v)
{
    int key = (v == 1 ? VOR_1_RADIO : VOR_2_RADIO);
    vor_receiver& r = dynamic_cast<vor_receiver&>(*elements[key]);
    r.swap_frequencies();
}


void panel::initialize()
{
    double start_x = 0.1;
    double start_y = 0.4;
    double size = 0.08;
    double inc = 0.175;
    double y_correct = 1.333333;

    double cur_x = start_x;
    double cur_y = start_y;

    vor_receiver* vor1 = new vor_receiver(0.75, 0.3, 0.23, 0.1);
    vor_receiver* vor2 = new vor_receiver(0.75, 0.45, 0.23, 0.1);
    vor_receiver* vor3 = new vor_receiver(0.75, 0.6, 0.23, 0.1);

    for (int i = 1; i < 11; i++)
    {
        if (i == 10)
        {
            cur_x += inc;
        }

        switch (i)
        {
            case 1:
                elements[i] = new airspeed_indicator(cur_x, cur_y, size, size * y_correct, 25, 180);
            break;
            case 2:
                elements[i] = new attitude_indicator(cur_x, cur_y, size, size * y_correct);
            break;
            case 3:
                elements[i] = new altimeter(cur_x, cur_y, size, size * y_correct);
            break;
            case 4:
                elements[i] = new cdi_gauge(cur_x, cur_y, size, size * y_correct, *vor1);
            break;
            case 5:
                elements[i] = new turn_coordinator(cur_x, cur_y, size, size * y_correct);
            break;
            case 6:
                elements[i] = new heading_indicator(cur_x, cur_y, size, size * y_correct);
            break;
            case 7:
                elements[i] = new vertical_speed_indicator(cur_x, cur_y, size, size * y_correct);
            break;
            case 8:
                elements[i] = new cdi_gauge(cur_x, cur_y, size, size * y_correct, *vor2);
            break;
            case 10:
                elements[i] = new manifold_pressure_gauge(cur_x, cur_y, size, size * y_correct);
            break;
            default:
                elements[i] = new panel_element(cur_x, cur_y, size, size * y_correct);
            break;
        }
        if (i % 4)
        {
            cur_x += inc;
        }
        else
        {
            cur_x = start_x;
            cur_y += inc * y_correct;
        }
    }

    elements[12] = vor1;
    elements[13] = vor2;
    elements[14] = vor3;
}

void panel::draw(const aircraft& a, const world& w)
{
    sdl_helper::normal_line_color(0.0, 0.3, 0.4, 0.2, sdl_helper::WHITE);
    sdl_helper::normal_line_color(0.4, 0.2, 0.8, 0.2, sdl_helper::WHITE);
    sdl_helper::normal_line_color(0.8, 0.2, 1.2, 0.3, sdl_helper::WHITE);

    std::map<int, panel_element*>::iterator iter;
    for (iter = elements.begin(); iter != elements.end(); iter++)
    {
        iter->second->draw(a, w);
    }

    w.draw_moving_map(0.75, 0.75, 0.23, 0.23, a);
}


#endif
