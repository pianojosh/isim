#ifndef __AIRCRAFT_CPP
#define __AIRCRAFT_CPP

#include "../include/aircraft.h"
#include "../include/panel_element.h"

#include <iostream>
#include <math.h>

void aircraft::simulate(int step_millis)
{
    // most of these are try-and-tweak
    const double AIRSPEED_TURN_FACTOR = 1.5;
    const double TURN_MULTIPLIER = 1500.0;
    const double CLIMB_MULTIPLIER = 64.0;
    const double CLIMB_TURN_FACTOR = 10.0;
    const double AIRSPEED_POWER_FACTOR = 6.9230769;
    const double AIRSPEED_CLIMB_FACTOR = 0.05;
    const double AIRSPEED_STEP_FACTOR = 0.00045;
    const double AIRSPEED_STALL_FACTOR = 0.75;

    turn_rate = (TURN_MULTIPLIER * tan(panel_element::degrees_to_radians(bank_angle)) / (AIRSPEED_TURN_FACTOR * airspeed));
    climb_rate = CLIMB_MULTIPLIER * tan(panel_element::degrees_to_radians(pitch_angle)) * airspeed;

    climb_rate -= CLIMB_TURN_FACTOR * fabs(bank_angle);

    heading += turn_rate * ((double)step_millis / 1000.0);
    altitude += climb_rate * ((double)step_millis / 60000.0);

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

    double desired_airspeed = 30 + (power_setting - 15) * AIRSPEED_POWER_FACTOR - climb_rate * AIRSPEED_CLIMB_FACTOR;
    double airspeed_difference = desired_airspeed - airspeed;
    airspeed = airspeed + (airspeed_difference * AIRSPEED_STEP_FACTOR * step_millis);

    if (airspeed < 50)
    {
        pitch_angle -= (50 - airspeed) * AIRSPEED_STALL_FACTOR;
    }

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
