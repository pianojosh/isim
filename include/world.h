#ifndef __WORLD_H
#define __WORLD_H

#include "ground_object.h"

#include <vector>

using std::vector;

class world
{
    private:
        double x_dim_min;
        double x_dim_max;
        double y_dim_min;
        double y_dim_max;

        vector<ground_object*> objects;
        vector<ground_object*> objects_by_x_dim;
        vector<ground_object*> objects_by_y_dim;

        bool dimensions_finalized;
        bool objects_finalized;

    public:
        world() :
            dimensions_finalized(false),
            objects_finalized(false)
        {}

        world(double xds, double xdb, double yds, double ydb) :
            x_dim_min(xds),
            x_dim_max(xdb),
            y_dim_min(yds),
            y_dim_max(ydb),
            dimensions_finalized(false),
            objects_finalized(false)
        {}

        void set_dimensions(double xds, double xdb, double yds, double ydb);
        void finalize_dimensions();

        void add_object(ground_object* obj);
        void finalize_objects();

        void draw_moving_map(double xpos, double ypos, double xsize, double ysize) const;

};

#endif
