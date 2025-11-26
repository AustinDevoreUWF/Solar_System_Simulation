#include <SFML/Graphics.hpp>
#include "vector2D.hpp"
#include "Physics.hpp"
#include <optional>

int main() {

    sf::RenderWindow window(sf::VideoMode({800,800}), "Physics Sim");
    window.setFramerateLimit(60);  

    

    Ball ball1{{400.f,400.f},100.f,500.f,{0,0}};//init pos{x,y},radius, mass,vel
    Ball ball2{{100.f,30.f},50.f,150.f,{20,0}};

    sf::CircleShape Lball(ball1.radius);
    sf::CircleShape Sball(ball2.radius);

    Lball.setFillColor(sf::Color::Red);
    Sball.setFillColor(sf::Color::Green);
//-----------------------------------
    Lball.setPosition(ball1.pos);//this passes in a vector but the converter in vector2D returns as a vector2f type when it sees this
    Sball.setPosition(ball2.pos);
//-----------------------------------
    Physics physics;
    physics.addBall(&ball1);
    physics.addBall(&ball2);
sf::Clock clock;    
//game loop
    while(window.isOpen()){

        while(const optional event = window.pollEvent()){
            if(event->is<sf::Event::Closed>())
                window.close();
        }
float dt = clock.restart().asSeconds();
        physics.step(dt);
        Lball.setPosition(ball1.pos);
        Sball.setPosition(ball2.pos);

        window.clear();
        window.draw(Lball);
        window.draw(Sball);
        
        window.display();

    }
    return 0;
}