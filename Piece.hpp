#ifndef __PIECE_HPP__
#define __PIECE_HPP__

#include <SFML/Graphics.hpp>
#include "Constants.hpp"
#include <list>

class Piece{
private:

    // Board is a friend class so it can access private stuff
    friend class Board;

    // Column and row in which the piece is located
    int file, rank;

    // Type of the piece
    constants::Type type;

    // True if white, false if black
    bool isWhite;

    // Sprite of the piece
    sf::Sprite sprite;

    // Pointer to a list that contains the possible movements for the piece
    std::list<std::pair<int,int>> * movements;

    // True if the piece has moved, false if not.
    // Useful for pawns (move double in the first move)
    // and kings, rooks and knooks (castling)
    bool hasMoved;

    // Flag that activates if we shake the piece (useful for easter eggs like the
    // knook losing its sunglasses when shaken)
    bool movedTooMuch;

public:
    Piece(int file, int rank, constants::Type type, bool isWhite, sf::Texture * texture, sf::IntRect rectangle);
    ~Piece();
};

#endif // __PIECE_HPP__
