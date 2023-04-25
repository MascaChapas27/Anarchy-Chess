#ifndef __PIECE_HPP__
#define __PIECE_HPP__

#include <SFML/Graphics.hpp>
#include <list>

enum Type {
    PAWN, KNOOK, HORSEY, ROOK, BISHOP, KING, QUEEN, KNISHOP
};

class Piece{
private:

    // Board is a friend class so it can access private stuff
    friend class Board;

    // Column and row in which the piece is located
    int file, rank;

    // Type of the piece
    Type type;

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

public:
    Piece(int file, int rank, Type type, bool isWhite, sf::Texture * texture, sf::IntRect rectangle);
    ~Piece();
};

#endif // __PIECE_HPP__
