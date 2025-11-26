#include <cmath>
#include "vector2D.hpp"
#include <vector>
class Physics{
    private:
        const float G = 1000.0f;
        double time=0.0;
        Vector v;
        vector<Ball*> ball;
    public:

        void addBall(Ball *b){
            ball.push_back(b);
        }

        Vector forceG(Ball *a, Ball *b){
            Vector dir = b->pos - a->pos;
            float distance = dir.mag();
            if(distance ==0) return Vector(0,0);
            float magnitude = G*(a->mass *b->mass)/(distance*distance);
            return dir.norm() * magnitude; //give the full force vector, direction and mag
        };

        void step(double dt){
            for(auto b:ball){
                b->force = Vector(0,0);
            }
            //iterate through all ball relationships and update the forces
            for(size_t i=0;i<ball.size();i++){
            for(size_t j=i+1;j<ball.size();j++){
                Ball* ballA=ball[i];
                Ball* ballB=ball[j];

                Vector f =forceG(ballA,ballB);
                ballA->force+=f;//updates the balls force due to gravity toward 
                ballB->force+=f * -1;
            }
        }
        //we know mass and force, then find a=f/m
            for(size_t i=0;i<ball.size();i++){
                Ball *b =ball[i];
                Vector acceleration = b->force /b->mass;
                b->vel +=acceleration*dt;
                b->pos +=b->vel *dt;
            }
            time=time+dt;
            }
        };