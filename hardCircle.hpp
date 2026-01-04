#ifndef SPHERE
#define SPHERE
#include <cmath>
#include <vector>

std::vector<float> makeVertices(float r, int segments);

struct location2D{
    float X;
    float Y;
};
//dont understand
void createCircleBuffers(
    unsigned int& vao,
    unsigned int& vbo,
    const std::vector<float>& vertices
);

void generateCircle(float r, int segments);

void drawCircle(float cx, float cy, float radius, int segments = 32) {
    glBegin(GL_LINE_LOOP); // outline circle
    for (int i = 0; i < segments; ++i) {
        float angle = 2.0f * PI * i / segments;
        glVertex2f(
            cx + radius * cosf(angle),
            cy + radius * sinf(angle)
        );
    }
    glEnd();
}


#endif