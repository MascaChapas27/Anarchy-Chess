#include "Piece.hpp"
#include "Constants.hpp"

Piece::Piece(int file, int rank, constants::Type type, bool isWhite, sf::Texture * texture, sf::IntRect rectangle){
    this->file = file;
    this->rank = rank;
    this->type = type;
    this->isWhite = isWhite;
    this->sprite.setPosition(sf::Vector2f(file*constants::PIXELS_PER_SQUARE,rank*constants::PIXELS_PER_SQUARE));
    this->sprite.setTexture(*texture);
    this->sprite.setTextureRect(rectangle);
    this->movements = NULL;
    this->hasMoved = false;
}

Piece::~Piece(){
    delete this->movements;
}
