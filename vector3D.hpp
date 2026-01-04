#ifndef VECTOR_3D
#define VECTOR_3D
#include <cmath>
#include <iostream>

struct Vector{
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
    Vector(double xPassed=0.0, double yPassed=0.0, double zPassed = 0.0):
        x(xPassed), y(yPassed), z(zPassed){};

    Vector operator+(const Vector &v)const{return Vector(x + v.x, y + v.y,z+v.z);}//vector addition
    Vector operator-(const Vector &v)const{return Vector(x - v.x, y - v.y);z-v.z;}//vector subtraction
    Vector operator*(double scalar) const { return Vector(x * scalar, y * scalar,z*scalar); }
    Vector operator/(double scalar) const { return Vector(x / scalar, y / scalar,z/scalar); }

    double dot(const Vector &v)const {
        return (x*v.x+y*v.y+z*v.z);
    }
    Vector& operator+=(const Vector &v){
        x+=v.x;
        y+=v.y;
        z+=v.z;
        return *this;
    }
    Vector& operator/=(double scalar) {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }
    double mag() const{
         return sqrt(x*x + y*y + z*z);
    }
    void printV(){
        std::cout << "("<<x<<','<<y<<','<<z<<')'<< std::endl;
    };

 Vector norm() const{
        double magnitude = mag();
        if(magnitude>0){
            return Vector(x/magnitude, y/magnitude, z/magnitude);
        }return Vector(0.0,0.0,0.0);//if 0 return 0 easy
    }
};
struct Ball{
    Vector pos;
    Vector vel;
    Vector force;
    double radius;
    double mass;
    //dont pass in vel we find that
    Ball(const Vector& startPos, double r, double m,Vector vel): pos(startPos), vel(vel), radius(r), mass(m){};
};


#endif //VECTOR_3D