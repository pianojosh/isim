#ifndef __ILS_H
#define __ILS_H

class ils : public localizer
{
    private:
        double glide_slope_width;
        double glide_slope_angle;

    public:
        ils() {}
        ils(double xpos, double ypos, double elev, int var, std::string id, int freq, int dir) :
            localizer(xpos, ypos, elev, var, id, freq, dir),
            glide_slope_width(5.0),
            glide_slope_angle(3.0)
        {}

        ils(double xpos, double ypos, double elev, int var, std::string id, int freq, int dir, double width) :
            localizer(xpos, ypos, elev, var, id, freq, dir, width),
            glide_slope_width(5.0),
            glide_slope_angle(3.0)
        {}

        ils(double xpos, double ypos, double elev, int var, std::string id, int freq, int dir, double gsw, double gsa) :
            localizer(xpos, ypos, elev, var, id, freq, dir),
            glide_slope_width(5.0),
            glide_slope_angle(3.0)
        {}

        ils(double xpos, double ypos, double elev, int var, std::string id, int freq, int dir, double width, double gsw, double gsa) :
            localizer(xpos, ypos, elev, var, id, freq, dir, width),
            glide_slope_width(gsw),
            glide_slope_angle(gsa)
        {}
};

#endif
