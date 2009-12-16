#ifndef __NDB_H
#define __NDB_H

#include <string>

class ndb : public ground_object
{
    private:
        int channel;

    public:
        ndb() {}
        ndb(double xpos, double ypos, double elev, int var, std::string id, int cnl) :
            ground_object(xpos, ypos, elev, var, id),
            channel(cnl)
        {}
};

#endif
