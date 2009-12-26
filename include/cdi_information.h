#ifndef __CDI_INFORMATION_H
#define __CDI_INFORMATION_H

struct cdi_information
{
    bool flag;
    enum {TO, FROM} direction;
    double deviation;
};

#endif
