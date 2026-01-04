#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <vector>
#include <cmath>
#include <iostream>
#include "immediateC.hpp"
#include "initialValues3d.hpp"
#include "Physics3D.hpp"
int main() {
    sf::Window window(sf::VideoMode({800, 600}),
    "3D Circle Example",
    sf::Style::Default);

    if (!window.setActive(true)) {
        std::cerr << "Failed to activate OpenGL context" << std::endl;
        return -1;
    }
    window.setMouseCursorVisible(false);
    window.setMouseCursorGrabbed(true);

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.f, 0.f, 0.15f, 1.f);

    // projection setup
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float aspect = 800.f / 600.f;
    glFrustum(-aspect, aspect, -1.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);

    //Camera Settup
    float camX=0.0f, camY=0.0f, camZ=8.0f;
    float camYaw = 0.0f;
    float camPitch = 0.0f;
    float moveSpeed = 0.01f;
    float mouseSensitivity = 0.002f;
    //Center the mouse
    sf::Vector2i centerPos(400,300);
    sf::Mouse::setPosition(centerPos,window);

    sf::Clock clock;
    Physics physics;

    for(Planet *p:solarSystem){
        physics.addBall(p->solarBody);
    }

while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }if(event->is<sf::Event::KeyPressed>()){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){
                window.close();
            }
        }
    }
 double speedMultiplier = 1000;
        double dt = clock.restart().asSeconds();
        int subSteps =10;
        for(int i=0;i<subSteps;i++){
            physics.step((dt*speedMultiplier) / subSteps);
        }
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2i mouseDelta = mousePos - centerPos;

    camYaw += mouseDelta.x * mouseSensitivity;
    camPitch += mouseDelta.y * mouseSensitivity;

    if(camPitch >PI /2.0f-0.1f)camPitch = PI/2.0-0.1f;
    if(camPitch<-PI/2.0f+.01f)camPitch=-PI/2.0+0.1f;
    sf::Mouse::setPosition(centerPos,window);//need to keep mouse in middle so you can look forever

    //really dont understand to be honest
    float cosYaw = cos(camYaw);//gets the x
    float sinYaw = sin(camYaw);//gets the y
    float cosPitch = cos(camPitch);
    float forwardX = sinYaw * cosPitch;
    float forwardY = -sin(camPitch);
    float forwardZ = -cosYaw * cosPitch;
    float rightX = cosYaw;
    float rightZ = sinYaw;

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            camX += forwardX * moveSpeed;
            camY += forwardY * moveSpeed;
            camZ += forwardZ * moveSpeed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            camX -= forwardX * moveSpeed;
            camY -= forwardY * moveSpeed;
            camZ -= forwardZ * moveSpeed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            camX -= rightX * moveSpeed;
            camZ -= rightZ * moveSpeed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            camX += rightX * moveSpeed;
            camZ += rightZ * moveSpeed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
            camY += moveSpeed;  // Move up
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
            camY -= moveSpeed;  // Move down
        }        


        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();

        glRotatef(camPitch*180.0f/PI,1.0f,0.0f,0.0f);
        glRotatef(camYaw*180.0f/PI,0.0f,1.0f,0.0f);
        glTranslatef(-camX,-camY,-camZ);
        //applys the camera position

//make an object that takes, color/size/mass/initVel/location  
        for(Planet* p:solarSystem){
            p->draw(Sun.solarBody->pos);
        }
        window.display();
    }

    return 0;
}
