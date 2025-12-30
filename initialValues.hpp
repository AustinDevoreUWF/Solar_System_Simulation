#ifndef INITIALVALUES
#define INITIALVALUES
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
#endif