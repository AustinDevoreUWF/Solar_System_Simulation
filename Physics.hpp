#include <cmath>
class Physics{
    private:
        const double g = 9.8;

    public:
    double deltaV = g * log(massI/massF); 
};