#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include "Piece.hpp"

const int WIDTH = 8;
const int HEIGHT = 8;
const int PIXELS_PER_SQUARE = 64;

enum Outcome {
    OK, CHECKMATE, STALEMATE
};

class Board{
private:

    // Window in which everything happens
    sf::RenderWindow window;

    // Textures that contain the images for the pieces
    // They are pointers because pieces need to point at
    // them as well or else nothing works
    sf::Texture * texturesPiecesBlack = new sf::Texture();
    sf::Texture * texturesPiecesWhite = new sf::Texture();

    // Rectangles for every piece
    sf::IntRect rectanglePawn;
    sf::IntRect rectangleKnook;
    sf::IntRect rectangleHorsey;
    sf::IntRect rectangleRook;
    sf::IntRect rectangleBishop;
    sf::IntRect rectangleKing;
    sf::IntRect rectangleQueen;
    sf::IntRect rectangleKnishop;

    // Rectangles for every piece but when they are being grabbed
    sf::IntRect rectanglePawnGrab;
    sf::IntRect rectangleKnookGrab;
    sf::IntRect rectangleHorseyGrab;
    sf::IntRect rectangleRookGrab;
    sf::IntRect rectangleBishopGrab;
    sf::IntRect rectangleKingGrab;
    sf::IntRect rectangleQueenGrab;
    sf::IntRect rectangleKnishopGrab;

    // Texture that contains the board
    sf::Texture textureBoard;

    // Sprite for the board
    sf::Sprite spriteBoard;

    // Texture that contains the hands
    sf::Texture textureHands;

    // Rectangles for the black hand and the white hand
    sf::IntRect rectangleWhiteHand;
    sf::IntRect rectangleBlackHand;

    // Sprite for the hand
    sf::Sprite spriteHand;

    // The board is represented by a matrix of pointers to pieces
    // (if the pointer is null there is no piece, if it's not null
    // then it points at a piece)
    Piece * pieces[HEIGHT][WIDTH];

    // True when the king has been captured or there is a stalemate
    bool gameOver = false;

    // True if it's white's turn, false if it's black's turn
    bool whitesTurn = true;

    // Piece that we are holding
    Piece * heldPiece = NULL;

    // Helper function that calculates all movements of a piece and
    // updates its list of movements
    void calculateMovements(int i, int j);

    // Helper function that draws a piece's moves
    void drawMoves(Piece * piece);

    // Helper function called when changing the position of a piece
    Outcome changeTurn();



public:
    Board();
    void play();
    ~Board();
};

#endif // __BOARD_HPP__
