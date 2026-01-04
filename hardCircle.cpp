#include "sphere.hpp"
#include <vector>
#include <cmath>
#include <SFML/Window.hpp>   // window + OpenGL context
#include <SFML/OpenGL.hpp>  // OpenGL types + platform glue
#include <optional>
using namespace std;
//calcs the circle
std::vector<float> makeVertices(float r, int segments){
    vector<float> vertices;
    vertices.push_back(0.0f);
    vertices.push_back(0.0f);

    float step = (2.0f * M_PI) / segments;
    for(int i = 0;i<=segments;i++){//each iteration adds a vertex
        float angle = i * step;//angle is from reversing the step 2PI/
        vertices.push_back(r*cos(angle));
        vertices.push_back(r*sin(angle));
    }
};

//dont understand
void createCircleBuffers(
    unsigned int& vao,
    unsigned int& vbo,
    const std::vector<float>& vertices
){
    glGenVertexArrays(1,&vao);
};
