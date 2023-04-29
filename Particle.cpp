#include "Particle.hpp"
#include "Constants.hpp"
#include <iostream>

Particle::Particle(bool isWhite, double x, double y, sf::Texture * texture){
    int randNum = rand()%8;
    sf::IntRect rectangle(randNum*constants::PIXELS_PER_SQUARE,isWhite*constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE);
    sprite.setTexture(*texture);
    sprite.setTextureRect(rectangle);
    sprite.setPosition(x+constants::PIXELS_PER_SQUARE/2,y+constants::PIXELS_PER_SQUARE/2);
    sprite.setOrigin(constants::PIXELS_PER_SQUARE/2,constants::PIXELS_PER_SQUARE/2);
    gravity = 0.5;
    speedX = rand()%14 - 8;
    speedY = rand()%5 - 10;
    rotationSpeed = rand()%10 - 5;
    this->sprite.scale(3.0/4.0,3.0/4.0);
}

Particle::Particle(constants::Type t, bool isWhite, double x, double y, sf::Texture * texture) : Particle(isWhite,x,y,texture){
    int n;
    switch(t){
    case constants::PAWN:
        n=0;
        break;
    case constants::KNOOK:
        n=1;
        break;
    case constants::HORSEY:
        n=2;
        break;
    case constants::ROOK:
        n=3;
        break;
    case constants::BISHOP:
        n=4;
        break;
    case constants::KING:
        n=5;
        break;
    case constants::QUEEN:
        n=6;
        break;
    case constants::KNISHOP:
        n=7;
        break;
    default:
        n=0;
        break;
    }
    sf::IntRect rectangle(n*constants::PIXELS_PER_SQUARE,2*constants::PIXELS_PER_SQUARE+isWhite*constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE);
    this->sprite.setTextureRect(rectangle);
    this->sprite.scale(4.0/3.0,4.0/3.0);

}

Particle::Particle(int x, int y, sf::Texture * texture){
    sf::IntRect rectangle(8*constants::PIXELS_PER_SQUARE,0,constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE);
    sprite.setTexture(*texture);
    sprite.setTextureRect(rectangle);
    sprite.setPosition(x+constants::PIXELS_PER_SQUARE/2,y+constants::PIXELS_PER_SQUARE/2);
    sprite.setOrigin(constants::PIXELS_PER_SQUARE/2,constants::PIXELS_PER_SQUARE/2);
    gravity = 0.5;
    speedX = rand()%14 - 8;
    speedY = rand()%5 - 10;
    rotationSpeed = rand()%10 - 5;
}

// Returns true if it went too low and should be erased
bool Particle::update(){
    speedY+=gravity;
    sf::Vector2f positions = sprite.getPosition();
    if(positions.x<0 || positions.x > constants::WIDTH*constants::PIXELS_PER_SQUARE) speedX = -speedX;
    positions.x += speedX;
    positions.y += speedY;
    if(positions.y > constants::HEIGHT*constants::PIXELS_PER_SQUARE){
        speedY = -abs(3*speedY/4);
        speedX = speedX/2;
        rotationSpeed = rotationSpeed/2;
    }
    sprite.setPosition(positions);
    sprite.rotate(rotationSpeed);
    return positions.y > (constants::PIXELS_PER_SQUARE * constants::HEIGHT + constants::PIXELS_PER_SQUARE/2);
}
