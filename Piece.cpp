#include "Piece.hpp"

Piece::Piece(int file, int rank, Type type, bool isWhite, sf::Texture * texture, sf::IntRect rectangle, int pixelsPerSquare){
    this->file = file;
    this->rank = rank;
    this->type = type;
    this->isWhite = isWhite;
    this->sprite.setPosition(sf::Vector2f(file*pixelsPerSquare,rank*pixelsPerSquare));
    this->sprite.setTexture(*texture);
    this->sprite.setTextureRect(rectangle);
    this->movements = NULL;
    this->hasMoved = false;
}

Piece::~Piece(){
    delete this->movements;
}
