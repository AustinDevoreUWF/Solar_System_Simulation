#include <cmath>
#include <iostream>
using namespace std;
//i need to create vectors that track direction and magnitude
struct Vector{
    double x=0.0;
    double y=0.0;
    Vector(double xPassed=0.0, double yPassed=0.0):x(xPassed),y(yPassed){};//different way to initialize, x(= this ) this creates a vector with given vals
    //Here we are creating vector mathmatics, enabling +-*/ for vectors
    Vector operator+(const Vector &v)const{return Vector(x + v.x, y + v.y);}//vector addition
    Vector operator-(const Vector &v)const{return Vector(x - v.x, y - v.y);}//vector subtraction
    Vector operator*(double scalar) const { return Vector(x * scalar, y * scalar); }
    Vector operator/(double scalar) const { return Vector(x / scalar, y / scalar); }

    double dot(const Vector &newVector)const{return (x * newVector.x + y * newVector.y);}//dot product

//To find the magnitude we need to get the value and make it positive if its negative
double mag()const{
    return sqrt(x*x +y*y);//gets the abs val
};
void printV(){
    cout << "("<<x<<','<<y<<')'<< endl;
    };
};
//Define the Ball
struct Ball{
    Vector pos;
    Vector vel;
    double radius;
    Ball(Vector startPos, double r): pos(startPos), vel(0,0), radius(r){};
};
