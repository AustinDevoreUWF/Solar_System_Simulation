#ifndef VECTOR_2D
#define VECTOR_2D
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
using namespace std;
//i need to create vectors that track direction and magnitude
struct Vector{
    float x=0.0f;
    float y=0.0f;
    Vector(float xPassed=0.0, float yPassed=0.0):x(xPassed),y(yPassed){};//different way to initialize, x(= this ) this creates a vector with given vals

//-----------------------------------
    operator sf::Vector2f() const {// whenever a Vector2f is expected this is ran, taking x and y of the obj and returning it in proper form(a vector2f type)
        return sf::Vector2f(x, y);
    }
//-----------------------------------

    //Here we are creating vector mathmatics, enabling +-*/ for vectors
    Vector operator+(const Vector &v)const{return Vector(x + v.x, y + v.y);}//vector addition
    Vector operator-(const Vector &v)const{return Vector(x - v.x, y - v.y);}//vector subtraction
    Vector operator*(float scalar) const { return Vector(x * scalar, y * scalar); }
    Vector operator/(float scalar) const { return Vector(x / scalar, y / scalar); }

    double dot(const Vector &newVector)const{return (x * newVector.x + y * newVector.y);}//dot product
    //give the actual vector to be modified
    Vector& operator+=(const Vector &v){
        x+=v.x;
        y+=v.y;
        //return the modified vector,c++ knows
        return *this;
    }
    Vector& operator/=(float scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }
//To find the magnitude we need to get the value and make it positive if its negative
float mag()const{
    return sqrt(x*x +y*y);//gets the abs val
};
void printV(){
    cout << "("<<x<<','<<y<<')'<< endl;
    };
//anyVector.norm =  
    Vector norm() const{
        float magnitude = mag();
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
    float radius;
    float mass;
    //dont pass in vel we find that
    Ball(const Vector& startPos, float r, float m,Vector vel): pos(startPos), vel(vel), radius(r), mass(m){};
};
#endif