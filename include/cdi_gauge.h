#ifndef __CDI_GAUGE_H
#define __CDI_GAUGE_H

class cdi_gauge : public panel_element
{
    private:
        int selected_course;
        vor_receiver &receiver;
    
    public:
        cdi_gauge(int xpos, int ypos, int xsz, int ysz, vor_receiver &vor) :
            panel_element(xpos, ypos, xsz, ysz),
            receiver(vor)
        {}
};

#endif
