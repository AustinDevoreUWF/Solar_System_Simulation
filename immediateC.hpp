#ifndef SPHERE
#define SPHERE
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <vector>
#include <cmath>
#include <optional> // Required for SFML 3.0 events
const float PI = 3.14159265359f;

void drawCircle(float radius,int segments=8){
    glBegin(GL_TRIANGLE_FAN);
    for(int i=0;i<segments;i++){
        float angle = 2.0f * PI * i /segments;

        glVertex3f(radius * cosf(angle),radius*sinf(angle),0.0f);
    }glEnd();
}

void drawSphere(float radius, int segments, int rings){
    for(int i =0;i<rings;i++){
        float lat0=PI *(-0.5f+ (float)i /rings);
        float lat1=PI *(-0.5f+(float)(i+1)/rings);
        float z0 = sin(lat0);//vertical height of the bottom ring edge
        float z1 = sin(lat1);//vertical height of the top ring edge
        float r0 = cos(lat0);//horizontal radius of the bottom ring edge
        float r1 = cos(lat1);//horizontal radius of the top ring edge

        glBegin(GL_QUAD_STRIP);
        for(int j=0;j<=segments;j++){
            float lng =2*PI *(float)j /segments;
            float x=cos(lng);
            float y=sin(lng);

            glVertex3f(radius * x * r0,radius * y*r0, radius *z0);
            glVertex3f(radius*x*r1,radius*y*r1,radius*z1);
        }
        glEnd();
    }
}




#endif//SPHERE