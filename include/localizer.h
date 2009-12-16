#ifndef __LOCALIZER_H
#define __LOCALIZER_H

class localizer : public ground_object
{
    private:
        int frequency;
        int direction;
        double beam_width;

    public:
        localizer() {}
        localizer(double xpos, double ypos, double elev, int var, std::string id, int freq, int dir) :
            ground_object(xpos, ypos, elev, var, id),
            frequency(freq),
            direction(dir),
            beam_width(5.0)
        {}

        localizer(double xpos, double ypos, double elev, int var, std::string id, int freq, int dir, double width) :
            ground_object(xpos, ypos, elev, var, id),
            frequency(freq),
            direction(dir),
            beam_width(width)
        {}

};

#endif
