#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <vector>
#include <cmath>
#include <optional> // Required for SFML 3.0 events

#define PI 3.14159265359f

int main() {
    sf::ContextSettings settings;
    settings.depthBits = 24;

    sf::Window window(
        sf::VideoMode({800u, 600u}), 
        "OpenGL Sphere",             
        sf::Style::Default,          
        sf::State::Windowed,         
        settings                     
    );

    window.setActive(true);
    glEnable(GL_DEPTH_TEST);

    // PERSPECTIVE SETUP: Without this, 3D will look flat or won't show
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Simple way to set 3D perspective without GLU
    float aspect = 800.f / 600.f;
    glFrustum(-aspect, aspect, -1.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);

    // Sphere Parameters
    float radius = 1.0f;
    int sectorCount = 36;
    int stackCount = 18;
    std::vector<float> vertices;

    for (int i = 0; i <= stackCount; ++i) {
        float stackAngle = PI / 2 - i * (PI / stackCount);
        float xy = radius * cosf(stackAngle);
        float z = radius * sinf(stackAngle);

        for (int j = 0; j <= sectorCount; ++j) {
            float sectorAngle = j * (2 * PI / sectorCount);
            vertices.push_back(xy * cosf(sectorAngle));
            vertices.push_back(xy * sinf(sectorAngle));
            vertices.push_back(z);
        }
    }

    sf::Clock clock;
    
    // PRIMARY LOOP: Keep the window open
    while (window.isOpen()) {
        
        // EVENT LOOP: Process inputs
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        // RENDERING LOGIC: Must be OUTSIDE the pollEvent loop
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();

        float time = clock.getElapsedTime().asSeconds();
        glTranslatef(0.0f, 0.0f, -5.0f); // Move back 5 units to see the sphere
        glRotatef(time * 50.0f, 1.0f, 1.0f, 0.0f); 

        glBegin(GL_POINTS); 
        glColor3f(0.0f, 1.0f, 1.0f); 
        for (size_t i = 0; i < vertices.size(); i += 3) {
            glVertex3f(vertices[i], vertices[i+1], vertices[i+2]);
        }
        glEnd();

        window.display();
    }

    return 0;
}
