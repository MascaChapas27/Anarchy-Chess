#include "Particle.hpp"
#include "Constants.hpp"

Particle::Particle(bool isWhite, double x, double y, sf::Texture texture){
    int randNum = rand()%6;
    sf::IntRect rectangle(randNum*constants::PIXELS_PER_SQUARE,isWhite*constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE);
    sprite.setTextureRect(rectangle);
    sprite.setPosition(x,y);
    gravity = rand()%3;
    speedX = rand()%10 - 5;
    speedY = rand()%10 - 10;
    rotationSpeed = rand()%10 - 5;
}

// Returns true if it went too low and should be erased
bool Particle::update(){
    speedY+=gravity;
    sf::Vector2f positions = sprite.getPosition();
    positions.x += speedX;
    positions.y += speedY;
    sprite.setPosition(positions);
    sprite.rotate(rotationSpeed);
    return positions.y > (constants::PIXELS_PER_SQUARE * constants::HEIGHT);
}
