#ifndef INITIALVALUES
#define INITIALVALUES
#include <cmath>
#include "vector2D.hpp"
using namespace std;

    const double G = 5e-8;

    double initialVelocity(double aphelion, double perihelion){
        double a = (aphelion+perihelion)/2.0;
        double vel = sqrt(G * 6000000 * (2.0/perihelion - 1.0/a));
            return vel;
    }

        double v1 = initialVelocity(15,10);
        double v2 = initialVelocity(24,23);
        double v3 = initialVelocity(33,32);
        double v4 = initialVelocity(54,45);
        double v5 = initialVelocity(177,170);
        double v6 = initialVelocity(325,308);
        double v7 = initialVelocity(649,619);
        double v8 = initialVelocity(980,964);

    inline Ball sun{{960, 540}, 20, 6000000, {0,}};
    inline Ball mercury{{970, 540}, 3, 1, {0, v1}};
    inline Ball venus{{983, 540}, 4, 14.8, {0, v2}};
    inline Ball earth{{992, 540}, 4, 18.2, {0, v3}};
    inline Ball mars{{1005, 540}, 3, 3.9, {0, v4}};
    inline Ball jupiter{{1130, 540}, 10, 5750, {0, v5}};
    inline Ball saturn{{1268, 540}, 9, 1720, {0, v6}};
    inline Ball uranus{{1579, 540}, 6, 263, {0, v7}};
    inline Ball neptune{{1924, 540}, 6, 310, {0, v8}};
#endif