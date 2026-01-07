#ifndef INITIAL_VALUES_3D
#define INITIAL_VALUES_3D
#include "immediateC.hpp"
#include "vector3D.hpp"
#include <vector>

//scale factor
const double s = 5;
// Calculate velocities
const double G = 5e-8;

inline double initialVelocity(double aphelion, double perihelion){
    double a = (aphelion + perihelion) / 2.0;
    return std::sqrt(G * 6000000 * (2.0/perihelion - 1.0/a));
}

inline double v1 = initialVelocity(15*s, 10*s);
inline double v2 = initialVelocity(24*s, 23*s);
inline double v3 = initialVelocity(33*s, 32*s);
inline double v4 = initialVelocity(54*s, 45*s);
inline double v5 = initialVelocity(177*s, 170*s);
inline double v6 = initialVelocity(325*s, 308*s);
inline double v7 = initialVelocity(649*s, 619*s);
inline double v8 = initialVelocity(980*s, 964*s);

inline Ball sun{{960, 540, 0}, 20, 6000000, {0, 0, 0}};    
inline Ball mercury{{960+(10*s), 540, 0}, 3, 1, {0, v1, 0}};
inline Ball venus{{960+(23*s), 540, 0}, 4, 14.8, {0, v2, 0}};
inline Ball earth{{960+(32*s), 540, 0}, 4, 18.2, {0, v3, 0}};
inline Ball mars{{960+(45*s), 540, 0}, 3, 3.9, {0, v4, 0}};
inline Ball jupiter{{960+(170*s), 540, 0}, 10, 5750, {0, v5, 0}};
inline Ball saturn{{960+(308*s), 540, 0}, 9, 1720, {0, v6, 0}};
inline Ball uranus{{1579+(619*s), 540, 0}, 6, 263, {0, v7, 0}};
inline Ball neptune{{1924+(964*s), 540, 0}, 6, 310, {0, v8, 0}};

//color/size/mass/initVel/location
struct Planet{
    float r,g,b;
    Ball* solarBody;
    const float SCALE = .05f;

    Planet(Ball* aBall,float red, float green, float blue):solarBody(aBall),r(red),g(green),b(blue){};
    
    void draw(const Vector& sunPos){
        // Map 2D (X, Y) to 3D (X, Z) and center around the Sun
        float x3d = (solarBody->pos.x - sunPos.x) * SCALE;
        float z3d = (solarBody->pos.y - sunPos.y) * SCALE;
        float y3d = (solarBody->pos.z-sunPos.z)*SCALE; 
        
        glPushMatrix();
        glTranslatef(x3d,y3d,z3d);
        glColor3f(r,g,b);
        drawSphere(solarBody->radius*SCALE, 20,20);
        glPopMatrix();

    }
    void update2d(){

    }
};
        
    inline Planet Sun(&sun, 1.0f, 1.0f, 0.0f);
    inline Planet Mercury(&mercury, 0.7f, 0.7f, 0.7f);
    inline Planet Venus(&venus, 1.0f, 0.8f, 0.4f);
    inline Planet Earth(&earth, 0.2f, 0.5f, 1.0f);
    inline Planet Mars(&mars, 1.0f, 0.2f, 0.1f);
    inline Planet Jupiter(&jupiter, 0.8f, 0.7f, 0.5f);
    inline Planet Saturn(&saturn, 0.9f, 0.8f, 0.3f);
    inline Planet Uranus(&uranus, 0.5f, 0.9f, 0.9f);
    inline Planet Neptune(&neptune, 0.2f, 0.3f, 0.9f);

inline std::vector<Planet*> solarSystem={&Sun,&Mercury,&Venus,&Earth,&Mars,
    &Jupiter,&Saturn,&Uranus,&Neptune};

//create a starry background by placing stars randomly on the spheres edges
    struct Starfield{
    struct Star{
        float x, y, z;
        Star(float x, float y, float z) : x(x), y(y), z(z) {}
    };
std::vector<Star> stars;
    Starfield(int count){
        for(int i=0;i<count;i++){
            float theta = ((float)rand() / RAND_MAX) * (2.0 * PI);
            float phi = ((float)rand() / RAND_MAX) * (PI);
            float distance = 100;

            stars.push_back({
                distance * sin(phi)*cos(theta),
                distance * sin(phi)*sin(theta),
                distance * cos(phi)
            });
        }
    }
    void drawStars(){
        glBegin(GL_POINTS);
        glColor3f(1.0f,1.0f,1.0f);//Star Bright White color
        for(const auto& star: stars){
            glVertex3f(star.x,star.y,star.z);
        }glEnd();
    }
};



#endif //INITIAL_VALUES_3D