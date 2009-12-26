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

        /*
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
        */



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
