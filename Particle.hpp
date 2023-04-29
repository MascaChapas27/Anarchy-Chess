#ifndef __PARTICLE_HPP__
#define __PARTICLE_HPP__

#include <SFML/Graphics.hpp>
#include "Constants.hpp"

class Particle{

    // Board is a friend class, just like with the Piece class
    friend class Board;

private:
    double gravity;
    double speedX;
    double speedY;
    double rotationSpeed;
    sf::Sprite sprite;
public:
    Particle(bool isWhite, double x, double y, sf::Texture * texture);
    Particle(constants::Type t, bool isWhite, double x, double y, sf::Texture * texture);
    Particle(int x, int y, sf::Texture * texture);
    bool update();
};

#endif // __PARTICLE_HPP__
