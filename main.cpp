#include <SFML/Graphics.hpp>
#include "vector2D.hpp"
#include "Physics.hpp"
#include <optional>
#include "initialValues.hpp"
int main() {

    sf::RenderWindow window(sf::VideoMode({1920,1080}), "Physics Sim");
    window.setFramerateLimit(60);  




//real (SUN) weight 1.989e30 SIMULATED =
//real ball2(EARTH) weight 5.972e24
//  Type name {xpos,ypos}ras mass iVel  
    Ball sun{{960,540},20,6000000,{0,0}};

    Ball mercury{{970,540},3,1,{0,v1}};//masses have to be close or straight line
    Ball venus{{983,540},4,14.8,{0,v2}};
    Ball earth{{992,540},4,18.2,{0,v3}};
    Ball mars{{1005,540},3,3.9,{0,v4}};
    Ball jupiter{{1130,540},10,5750,{0,v5}};
    Ball saturn{{1268,540},9,1720,{0,v6}};
    Ball uranus{{1579,540},6,263,{0,v7}};
    Ball neptune{{1924,540},6,310,{0,v8}};

    sf::CircleShape Sun(sun.radius);
    sf::CircleShape Mercury(mercury.radius);
    sf::CircleShape Venus(venus.radius);
    sf::CircleShape Earth(earth.radius);
    sf::CircleShape Mars(mars.radius);
    sf::CircleShape Jupiter(jupiter.radius);
    sf::CircleShape Saturn(saturn.radius);
    sf::CircleShape Uranus(uranus.radius);
    sf::CircleShape Neptune(neptune.radius);

    Sun.setFillColor(sf::Color::Yellow);
    Mercury.setFillColor(sf::Color(169, 169, 169));  // Gray
    Venus.setFillColor(sf::Color(255, 198, 73));     // Orange
    Earth.setFillColor(sf::Color::Blue);
    Mars.setFillColor(sf::Color::Red);
    Jupiter.setFillColor(sf::Color(216, 202, 157));  // Tan
    Saturn.setFillColor(sf::Color(255, 215, 0));     // Gold
    Uranus.setFillColor(sf::Color::Cyan);
    Neptune.setFillColor(sf::Color(63, 84, 186));    // Dark Blue

//-----------------------------------
    Physics physics;
    physics.addBall(&sun);
    physics.addBall(&mercury);
    physics.addBall(&venus);
    physics.addBall(&earth);
    physics.addBall(&mars);
    physics.addBall(&jupiter);
    physics.addBall(&saturn);
    physics.addBall(&uranus);
    physics.addBall(&neptune);

sf::Clock clock;
double speedMultiplier = 1000.0;
//game loop
    while(window.isOpen()){
    while(const optional event = window.pollEvent()){
        if(event->is<sf::Event::Closed>())
            window.close();
    }
    
    double dt = clock.restart().asSeconds();
    int subSteps =10;
        for(int i=0;i<subSteps;i++){
            physics.step((dt*speedMultiplier) / subSteps);
        }
    //this passes in a vector but the converter in vector2D returns as a vector2f type when it sees this
    // ALL shapes need radius offset
    //replace 20 with Ball.radius incase updates are done.
    Sun.setPosition(sun.pos - Vector(sun.radius, sun.radius));
    Mercury.setPosition(mercury.pos - Vector(mercury.radius, mercury.radius));
    Venus.setPosition(venus.pos - Vector(venus.radius, venus.radius));
    Earth.setPosition(earth.pos - Vector(earth.radius, earth.radius));
    Mars.setPosition(mars.pos - Vector(mars.radius, mars.radius));
    Jupiter.setPosition(jupiter.pos - Vector(jupiter.radius, jupiter.radius));
    Saturn.setPosition(saturn.pos - Vector(saturn.radius, saturn.radius));
    Uranus.setPosition(uranus.pos - Vector(uranus.radius, uranus.radius));
    Neptune.setPosition(neptune.pos - Vector(neptune.radius, neptune.radius));
    
    window.clear(sf::Color::Black);
    window.draw(Sun);
    window.draw(Mercury);
    window.draw(Venus);
    window.draw(Earth);
    window.draw(Mars);
    window.draw(Jupiter);
    window.draw(Saturn);
    window.draw(Uranus);
    window.draw(Neptune);
    window.display();
    };
}