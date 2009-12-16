#ifndef __AIRCRAFT_H
#define __AIRCRAFT_H

class aircraft
{
    private:
        double x_position;
        double y_position;
        double altitude;
        double heading;
        double airspeed;
        double pitch_angle;
        double bank_angle;
        double power_setting;

        double turn_rate;
        double climb_rate;

    public:
        aircraft() :
            x_position(0.0),
            y_position(0.0),
            altitude(0.0),
            heading(0.0),
            airspeed(0.0),
            pitch_angle(0.0),
            bank_angle(0.0),
            power_setting(0),
            turn_rate(0),
            climb_rate(0)
        {}

        aircraft(int xpos, int ypos) :
            x_position(xpos),
            y_position(ypos),
            altitude(0.0),
            heading(0.0),
            airspeed(0.0),
            pitch_angle(0.0),
            bank_angle(0.0),
            power_setting(0),
            turn_rate(0),
            climb_rate(0)
        {}

        void simulate(int step_millis);

        double get_x_position() const;
        double get_y_position() const;
        double get_altitude() const;
        double get_heading() const;
        double get_airspeed() const;
        double get_pitch_angle() const;
        double get_bank_angle() const;
        double get_power_setting() const;

        double get_climb_rate() const;
        double get_turn_rate() const;

        void set_x_position(double x);
        void set_y_position(double y);
        void set_altitude(double a);
        void set_heading(double h);
        void set_airspeed(double s);
        void set_pitch_angle(double p);
        void set_bank_angle(double b);
        void set_power_setting(double p);

};

#endif
