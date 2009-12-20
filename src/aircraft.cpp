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
    const double STALL_SPEED = 50.0;
    const double SPEED_BASE = 30.0;
    const double MIN_POWER = 15.0;

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

    double desired_airspeed = SPEED_BASE + (power_setting - MIN_POWER) * AIRSPEED_POWER_FACTOR - climb_rate * AIRSPEED_CLIMB_FACTOR;
    double airspeed_difference = desired_airspeed - airspeed;
    airspeed = airspeed + (airspeed_difference * AIRSPEED_STEP_FACTOR * step_millis);

    if (airspeed < STALL_SPEED)
    {
        pitch_angle -= (STALL_SPEED - airspeed) * AIRSPEED_STALL_FACTOR;
    }

    double x_knots = airspeed * cos(panel_element::degrees_to_radians(heading - 90.0));
    double y_knots = airspeed * -sin(panel_element::degrees_to_radians(heading - 90.0));
    double x_delta = step_millis * x_knots / (60.0 * 60.0 * 1000.0);
    double y_delta = step_millis * y_knots / (60.0 * 60.0 * 1000.0);

    double xmpd = nautical_miles_per_degree_latitude_at_degrees_latitude(y_position);
    double ympd = nautical_miles_per_degree_longitude_at_degrees_latitude(y_position);

    x_position += x_delta / xmpd;
    y_position += y_delta / ympd;


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

double aircraft::get_x_position() const
{
    return x_position;
}

void aircraft::set_x_position(double x)
{
    x_position = x;
}

double aircraft::get_y_position() const
{
    return y_position;
}

void aircraft::set_y_position(double y)
{
    y_position = y;
}

double aircraft::nautical_miles_per_degree_latitude_at_degrees_latitude(double degrees_latitude)
{
    const double m1 = 111132.92;
    const double m2 = -559.82;
    const double m3 = 1.175;
    const double m4 = -0.0023;

    double lat = panel_element::degrees_to_radians(degrees_latitude);
    return 0.000539955723 * (m1 + (m2 * cos(2 * lat)) + (m3 * cos(4 * lat)) + (m4 * cos(6 * lat)));
}

double aircraft::nautical_miles_per_degree_longitude_at_degrees_latitude(double degrees_latitude)
{
    const double p1 = 111412.84;
    const double p2 = -93.5;
    const double p3 = 0.118;

    double lat = panel_element::degrees_to_radians(degrees_latitude);
    return 0.000539955723 * ((p1 * cos(lat)) + (p2 * cos(3 * lat)) + (p3 * cos(5 * lat)));
}

#endif
