#ifndef __GROUND_OBJECT_H
#define __GROUND_OBJECT_H

#include "SDL.h"
#include <string>

class ground_object
{
    private:
        double x_position;
        double y_position;
        double elevation;
        int variation;

    protected:
        virtual double moving_map_size_factor() const;
        std::string identifier;

    public:
        ground_object() {}
        ground_object(double xpos, double ypos, double elev, int var, const std::string& id) :
            x_position(xpos),
            y_position(ypos),
            elevation(elev),
            variation(var),
            identifier(id)
        {}
        ground_object(const ground_object &go) :
            x_position(go.x_position),
            y_position(go.y_position),
            elevation(go.elevation),
            variation(go.variation)
        {}
        virtual ~ground_object() {}

        virtual double get_x_position() const;
        virtual double get_y_position() const;

        static int compare_by_x_dimension(ground_object* l, ground_object* r);
        static int compare_by_y_dimension(ground_object* l, ground_object* r);

        virtual void draw_moving_map_symbol(double xpos, double ypos, double xsize, double ysize) const;

};

#endif
