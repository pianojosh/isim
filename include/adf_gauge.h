#ifndef __ADF_GAUGE_H
#define __ADF_GAUGE_H

class adf_gauge : public panel_element
{
    private:
        int selected_heading;
        adf_receiver &receiver;
    
    public:
        adf_gauge(int xpos, int ypos, int xsz, int ysz, adf_receiver &adf) :
            panel_element(xpos, ypos, xsz, ysz),
            receiver(adf)
        {}
};

#endif
