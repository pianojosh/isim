#ifndef __AIRCRAFT_CPP
#define __AIRCRAFT_CPP

#include "../include/aircraft.h"

#include <iostream>

void aircraft::simulate(int step_millis)
{
    double old_heading = heading;
    heading = heading + bank_angle * step_millis * 0.00032;

    double old_altitude = altitude;
    altitude = altitude + pitch_angle * step_millis * 0.0019;

    turn_rate = 1000.0 * (heading - old_heading) / (double)step_millis / 2.0;
    climb_rate = 60.0 * 1000.0 * (altitude - old_altitude) / (double)step_millis;

    while (heading >= 360)
    {
        heading -= 360;
    }
    while (heading < 0)
    {
        heading += 360;
    }

    if (altitude < 0)
    {
        altitude = 0;
    }

    double desired_airspeed = power_setting *  4.10714285;
    double airspeed_difference = desired_airspeed - airspeed;
    airspeed = airspeed + (airspeed_difference * 0.00015 * step_millis);

}

double aircraft::get_airspeed() const
{
    return airspeed;
}

void aircraft::set_airspeed(double a)
{
    airspeed = a;
}

double aircraft::get_bank_angle() const
{
    return bank_angle;
}

void aircraft::set_bank_angle(double b)
{
    bank_angle = b;
}

double aircraft::get_pitch_angle() const
{
    return pitch_angle;
}

void aircraft::set_pitch_angle(double p)
{
    pitch_angle = p;
}

double aircraft::get_altitude() const
{
    return altitude;
}

void aircraft::set_altitude(double a)
{
    altitude = a;
}

double aircraft::get_power_setting() const
{
    return power_setting;
}

void aircraft::set_power_setting(double p)
{
    power_setting = p;
}

double aircraft::get_heading() const
{
    return heading;
}

double aircraft::get_turn_rate() const
{
    return turn_rate;
}

double aircraft::get_climb_rate() const
{
    return climb_rate;
}

#endif
