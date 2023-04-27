#include "Particle.hpp"
#include "Constants.hpp"

Particle::Particle(bool isWhite, double x, double y, sf::Texture * texture){
    int randNum = rand()%6;
    sf::IntRect rectangle(randNum*constants::PIXELS_PER_SQUARE,isWhite*constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE);
    sprite.setTexture(*texture);
    sprite.setTextureRect(rectangle);
    sprite.setPosition(x+constants::PIXELS_PER_SQUARE/2,y+constants::PIXELS_PER_SQUARE/2);
    sprite.setOrigin(constants::PIXELS_PER_SQUARE/2,constants::PIXELS_PER_SQUARE/2);
    gravity = 0.5;
    speedX = rand()%14 - 8;
    speedY = rand()%5 - 10;
    rotationSpeed = rand()%10 - 5;
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
