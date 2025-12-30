#ifndef SPHERE
#define SPHERE
#include <cmath>
//create a struct of x and y coords for a location
//create a vector of dots that refer to X,Y 
//then hold a vector of type vector for many circles
int smoothness = 8;//number of triangles
float r = 4;
void generateCircle(float r, int smoothness){
    float step = (2*M_PI)/smoothness; //distance between each r vec

    for(int i = 0;i<smoothness;i++){
    float angle = i * step;
    float X =r*cos(angle);
    float Y =r*sin(angle);
    };
}

#endif