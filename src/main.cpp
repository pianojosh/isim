#include <iostream>

#include "../include/isim_controller.h"

int main(int argc, char* argv[])
{
    isim_controller c;
    c.initialize();
    c.run();
    return 0;
}
