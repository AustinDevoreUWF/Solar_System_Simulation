#ifndef VECTOR_2D
#define VECTOR_2D
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
using namespace std;
//i need to create vectors that track direction and magnitude
struct Vector{
    double x=0.0;
    double y=0.0;
    Vector(double xPassed=0.0, double yPassed=0.0):x(xPassed),y(yPassed){};//different way to initialize, x(= this ) this creates a vector with given vals

//------------------------------------
    operator sf::Vector2f() const{
        return sf::Vector2f(static_cast<float>(x), static_cast<float>(y));//static cast change the double x and y to floats when the actual object is called, leaving equations untouched
    };
//------------------------------------

    //Here we are creating vector mathmatics, enabling +-*/ for vectors
    Vector operator+(const Vector &v)const{return Vector(x + v.x, y + v.y);}//vector addition
    Vector operator-(const Vector &v)const{return Vector(x - v.x, y - v.y);}//vector subtraction
    Vector operator*(double scalar) const { return Vector(x * scalar, y * scalar); }
    Vector operator/(double scalar) const { return Vector(x / scalar, y / scalar); }

    double dot(const Vector &newVector)const{return (x * newVector.x + y * newVector.y);}//dot product
    //give the actual vector to be modified
    Vector& operator+=(const Vector &v){
        x+=v.x;
        y+=v.y;
        //return the modified vector,c++ knows
        return *this;
    }
    Vector& operator/=(double scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }
//To find the magnitude we need to get the value and make it positive if its negative
double mag()const{
    return sqrt(x*x +y*y);//gets the abs val
};
void printV(){
    cout << "("<<x<<','<<y<<')'<< endl;
    };
//anyVector.norm =  
    Vector norm() const{
        double magnitude = mag();
        if(magnitude>0){
            return Vector(x/magnitude, y/magnitude);
        }return Vector(0.0,0.0);//if 0 return 0 easy
    }
};

//Define the Ball
struct Ball{
    Vector pos;
    Vector vel;
    Vector force;
    double radius;
    double mass;
    //dont pass in vel we find that
    Ball(const Vector& startPos, double r, double m,Vector vel): pos(startPos), vel(vel), radius(r), mass(m){};
};
#endif