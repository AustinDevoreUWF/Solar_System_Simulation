#ifndef INITIALVALUES
#define INITIALVALUES
#include "vector3D.hpp"
#include <cmath>
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

    inline Ball sun{{960,540},20,6000000,{0,0}};
    Ball mercury{{970,540},3,1,{0,v1}};//masses have to be close or straight line
    Ball venus{{983,540},4,14.8,{0,v2}};
    Ball earth{{992,540},4,18.2,{0,v3}};
    Ball mars{{1005,540},3,3.9,{0,v4}};
    Ball jupiter{{1130,540},10,5750,{0,v5}};
    Ball saturn{{1268,540},9,1720,{0,v6}};
    Ball uranus{{1579,540},6,263,{0,v7}};
    Ball neptune{{1924,540},6,310,{0,v8}};

    inline Ball sun{{960, 540, 0}, 20, 6000000, {0, 0, 0}};
    inline Ball mercury{{970, 540, 0}, 3, 1, {0, v1, 0}};
    inline Ball venus{{983, 540, 0}, 4, 14.8, {0, v2, 0}};
    inline Ball earth{{992, 540, 0}, 4, 18.2, {0, v3, 0}};
    inline Ball mars{{1005, 540, 0}, 3, 3.9, {0, v4, 0}};
    inline Ball jupiter{{1130, 540, 0}, 10, 5750, {0, v5, 0}};
    inline Ball saturn{{1268, 540, 0}, 9, 1720, {0, v6, 0}};
    inline Ball uranus{{1579, 540, 0}, 6, 263, {0, v7, 0}};
    inline Ball neptune{{1924, 540, 0}, 6, 310, {0, v8, 0}};
#endif