#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include "Piece.hpp"
#include "Particle.hpp"

enum Outcome {
    OK, CHECKMATE, STALEMATE, FRONT_FACING_HORSEY
};

enum WindowMovement {
    DOWN, SHAKE, STILL
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

    // Texture for the particles
    sf::Texture * textureParticles = new sf::Texture();

    // List of particles that are currently on screen
    std::list<Particle*> listParticles;

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
    Piece * pieces[constants::HEIGHT][constants::WIDTH];

    // True when the king has been captured or there is a stalemate
    bool gameOver = false;

    // True if it's white's turn, false if it's black's turn
    bool whitesTurn = true;

    // Piece that we are holding
    Piece * heldPiece = NULL;

    // Current window movement
    WindowMovement movement;

    // Current state of the window movement
    int movementState;

    // Helper function that calculates all movements of a piece and
    // updates its list of movements
    void calculateMovements(int i, int j);

    // Helper function that draws a piece's moves
    void drawMoves(Piece * piece);

    // Helper function called when changing the position of a piece
    Outcome changeTurn(int x, int y);

    // Draws particles and moves them
    void updateParticles();

    // Moves the window
    void moveWindow();

    // Sets the current type of movement for the window
    void setMovement(WindowMovement m);

    // Generates a set of particles and a special particle for the captured piece
    void generateParticles(constants::Type t, bool white, double x, double y);

    // Generates a set of particles
    void generateParticles(bool white, double x, double y);

public:
    Board();
    void play();
    ~Board();
};

#endif // __BOARD_HPP__
