#include <cmath>
#include "vector2D.hpp"
#include <vector>
#include <cstddef>
class Physics{
    private://standered gravitational constant 6.674e-11
            //5e-8 gave close
        double time=0.0;
        Vector v;
        std::vector<Ball*> balls;//incase many balls
    public:
        const double G = 5e-8;

        void addBall(Ball *b){
            balls.push_back(b);
        }

        Vector forceG(Ball *a, Ball *b){
            Vector dir = b->pos - a->pos;
            double distance = dir.mag();
            if(distance ==0) return Vector(0,0);
            double magnitude = G*(a->mass *b->mass)/(distance*distance);
            return dir.norm() * magnitude; //give the full force vector, direction and mag
        };


    void step(double dt){
            for(auto b:balls){
                b->force = Vector(0,0);
            }
            //iterate through all ball relationships and update the forces
            for(std::size_t i=0;i<balls.size();i++){
            for(std::size_t j=i+1;j<balls.size();j++){
                Ball* ballA=balls[i];
                Ball* ballB=balls[j];

                Vector f =forceG(ballA,ballB);
                ballA->force+=f;//updates the balls force due to gravity toward 
                ballB->force+=f * -1;
            }
        }
        //we know mass and force, then find a=f/m
            for(std::size_t i=0;i<balls.size();i++){
                Ball *b =balls[i];
                Vector acceleration = b->force /b->mass;
                b->vel +=acceleration*dt;
                b->pos +=b->vel *dt;
            }
            time=time+dt;
            };
        };

//Values for initial velocity