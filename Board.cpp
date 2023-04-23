#include "Board.hpp"

Board::Board(){

    window.create(sf::VideoMode(WIDTH*PIXELS_PER_SQUARE, HEIGHT*PIXELS_PER_SQUARE), "Anarchy Chess");
    window.setFramerateLimit(60);
    window.setMouseCursorVisible(false);

    texturesPiecesBlack->loadFromFile("textures/piecesBlack.png");
    texturesPiecesWhite->loadFromFile("textures/piecesWhite.png");

    rectanglePawn = sf::IntRect(0,0,PIXELS_PER_SQUARE,PIXELS_PER_SQUARE);
    rectangleKnook = sf::IntRect(0,PIXELS_PER_SQUARE,PIXELS_PER_SQUARE,PIXELS_PER_SQUARE);
    rectangleHorsey = sf::IntRect(0,2*PIXELS_PER_SQUARE,PIXELS_PER_SQUARE,PIXELS_PER_SQUARE);
    rectangleRook = sf::IntRect(0,3*PIXELS_PER_SQUARE,PIXELS_PER_SQUARE,PIXELS_PER_SQUARE);
    rectangleBishop = sf::IntRect(2*PIXELS_PER_SQUARE,0,PIXELS_PER_SQUARE,PIXELS_PER_SQUARE);
    rectangleKing = sf::IntRect(2*PIXELS_PER_SQUARE,PIXELS_PER_SQUARE,PIXELS_PER_SQUARE,PIXELS_PER_SQUARE);
    rectangleQueen = sf::IntRect(2*PIXELS_PER_SQUARE,2*PIXELS_PER_SQUARE,PIXELS_PER_SQUARE,PIXELS_PER_SQUARE);
    rectangleKnishop = sf::IntRect(2*PIXELS_PER_SQUARE,3*PIXELS_PER_SQUARE,PIXELS_PER_SQUARE,PIXELS_PER_SQUARE);

    rectanglePawnCaptured = sf::IntRect(PIXELS_PER_SQUARE,0,PIXELS_PER_SQUARE,PIXELS_PER_SQUARE);
    rectangleKnookCaptured = sf::IntRect(PIXELS_PER_SQUARE,PIXELS_PER_SQUARE,PIXELS_PER_SQUARE,PIXELS_PER_SQUARE);
    rectangleHorseyCaptured = sf::IntRect(PIXELS_PER_SQUARE,2*PIXELS_PER_SQUARE,PIXELS_PER_SQUARE,PIXELS_PER_SQUARE);
    rectangleRookCaptured = sf::IntRect(PIXELS_PER_SQUARE,3*PIXELS_PER_SQUARE,PIXELS_PER_SQUARE,PIXELS_PER_SQUARE);
    rectangleBishopCaptured = sf::IntRect(3*PIXELS_PER_SQUARE,0,PIXELS_PER_SQUARE,PIXELS_PER_SQUARE);
    rectangleKingCaptured = sf::IntRect(3*PIXELS_PER_SQUARE,PIXELS_PER_SQUARE,PIXELS_PER_SQUARE,PIXELS_PER_SQUARE);
    rectangleQueenCaptured = sf::IntRect(3*PIXELS_PER_SQUARE,2*PIXELS_PER_SQUARE,PIXELS_PER_SQUARE,PIXELS_PER_SQUARE);
    rectangleKnishopCaptured = sf::IntRect(3*PIXELS_PER_SQUARE,3*PIXELS_PER_SQUARE,PIXELS_PER_SQUARE,PIXELS_PER_SQUARE);

    textureBoard.loadFromFile("textures/board.png");
    spriteBoard.setTexture(textureBoard);

    textureHands.loadFromFile("textures/hands.png");

    rectangleWhiteHand = sf::IntRect(0,0,PIXELS_PER_SQUARE,PIXELS_PER_SQUARE);
    rectangleBlackHand = sf::IntRect(PIXELS_PER_SQUARE,0,PIXELS_PER_SQUARE,PIXELS_PER_SQUARE);

    spriteHand.setTexture(textureHands);
    spriteHand.setTextureRect(rectangleWhiteHand);

    // First rank
    pieces[0][0] = new Piece(0,0,ROOK,false,texturesPiecesBlack,rectangleRook,PIXELS_PER_SQUARE);
    pieces[0][1] = new Piece(1,0,HORSEY,false,texturesPiecesBlack,rectangleHorsey,PIXELS_PER_SQUARE);
    pieces[0][2] = new Piece(2,0,KNISHOP,false,texturesPiecesBlack,rectangleKnishop,PIXELS_PER_SQUARE);
    pieces[0][3] = new Piece(3,0,QUEEN,false,texturesPiecesBlack,rectangleQueen,PIXELS_PER_SQUARE);
    pieces[0][4] = new Piece(4,0,KING,false,texturesPiecesBlack,rectangleKing,PIXELS_PER_SQUARE);
    pieces[0][5] = new Piece(5,0,BISHOP,false,texturesPiecesBlack,rectangleBishop,PIXELS_PER_SQUARE);
    pieces[0][6] = new Piece(6,0,HORSEY,false,texturesPiecesBlack,rectangleHorsey,PIXELS_PER_SQUARE);
    pieces[0][7] = new Piece(7,0,KNOOK,false,texturesPiecesBlack,rectangleKnook,PIXELS_PER_SQUARE);

    // Second rank
    for(int i=0;i<WIDTH;i++){
        pieces[1][i] = new Piece(i,1,PAWN,false,texturesPiecesBlack,rectanglePawn,PIXELS_PER_SQUARE);
    }

    // Empty ranks in the middle
    for(int i=0;i<WIDTH;i++){
        for(int j=2;j<HEIGHT-2;j++){
            pieces[j][i] = NULL;
        }
    }

    // Seventh rank
    for(int i=0;i<WIDTH;i++){
        pieces[6][i] = new Piece(i,6,PAWN,true,texturesPiecesWhite,rectanglePawn,PIXELS_PER_SQUARE);
    }

    // Eighth rank
    pieces[7][0] = new Piece(0,7,KNOOK,true,texturesPiecesWhite,rectangleKnook,PIXELS_PER_SQUARE);
    pieces[7][1] = new Piece(1,7,HORSEY,true,texturesPiecesWhite,rectangleHorsey,PIXELS_PER_SQUARE);
    pieces[7][2] = new Piece(2,7,BISHOP,true,texturesPiecesWhite,rectangleBishop,PIXELS_PER_SQUARE);
    pieces[7][3] = new Piece(3,7,QUEEN,true,texturesPiecesWhite,rectangleQueen,PIXELS_PER_SQUARE);
    pieces[7][4] = new Piece(4,7,KING,true,texturesPiecesWhite,rectangleKing,PIXELS_PER_SQUARE);
    pieces[7][5] = new Piece(5,7,KNISHOP,true,texturesPiecesWhite,rectangleKnishop,PIXELS_PER_SQUARE);
    pieces[7][6] = new Piece(6,7,HORSEY,true,texturesPiecesWhite,rectangleHorsey,PIXELS_PER_SQUARE);
    pieces[7][7] = new Piece(7,7,ROOK,true,texturesPiecesWhite,rectangleRook,PIXELS_PER_SQUARE);
}

Board::~Board(){
    for(int i=0;i<HEIGHT;i++){
        for(int j=0;j<WIDTH;j++){
            if(pieces[i][j]!=NULL)
                delete pieces[i][j]->movements;
            delete pieces[i][j];
        }
    }

    delete texturesPiecesBlack;
    delete texturesPiecesWhite;
}

// Helper function that calculates all possible movements for a piece
void Board::calculateMovements(int i, int j){

    pieces[i][j]->movements = new std::list<std::pair<int,int>>();

    switch(pieces[i][j]->type){
    case PAWN:

        if(pieces[i][j]->isWhite){
            // We see if it can move upwards
            if(i-1>0 && pieces[i-1][j] == NULL)
                pieces[i][j]->movements->insert(pieces[i][j]->movements->begin(),std::pair<int,int>(i-1,j));

            // We see if it can move upwards twice
            if(!pieces[i][j]->hasMoved && i-2>0 && pieces[i-2][j] == NULL)
                pieces[i][j]->movements->insert(pieces[i][j]->movements->begin(),std::pair<int,int>(i-2,j));

            // We see if there is an enemy piece that can be holy hell'd on its left
            if(j-1>0 && i-1>0 && pieces[i][j-1] != NULL && !pieces[i][j-1]->isWhite && pieces[i-1][j-1] == NULL)
                pieces[i][j]->movements->insert(pieces[i][j]->movements->begin(),std::pair<int,int>(i-1,j-1));

            // The same with the piece on its right
            if(j+1<WIDTH && i-1>0 && pieces[i][j+1] != NULL && !pieces[i][j+1]->isWhite && pieces[i-1][j+1] == NULL)
                pieces[i][j]->movements->insert(pieces[i][j]->movements->begin(),std::pair<int,int>(i-1,j+1));

        } else {
            // The same but downwards
            // We see if it can move downwards
            if(i+1<HEIGHT && pieces[i+1][j] == NULL)
                pieces[i][j]->movements->insert(pieces[i][j]->movements->begin(),std::pair<int,int>(i+1,j));

            // We see if it can move downwards twice
            if(!pieces[i][j]->hasMoved && i+2 < HEIGHT && pieces[i+2][j] == NULL)
                pieces[i][j]->movements->insert(pieces[i][j]->movements->begin(),std::pair<int,int>(i+2,j));

            // We see if there is an enemy piece that can be holy hell'd on its left
            if(j-1>0 && i+1 < HEIGHT && pieces[i][j-1] != NULL && pieces[i][j-1]->isWhite && pieces[i+1][j-1] == NULL)
                pieces[i][j]->movements->insert(pieces[i][j]->movements->begin(),std::pair<int,int>(i+1,j-1));

            // The same with the piece on its right
            if(j+1<WIDTH && i+1 < HEIGHT && pieces[i][j+1] != NULL && pieces[i][j+1]->isWhite && pieces[i+1][j+1] == NULL)
                pieces[i][j]->movements->insert(pieces[i][j]->movements->begin(),std::pair<int,int>(i+1,j+1));
        }

        break;
    case ROOK:
        break;
    case HORSEY:
        break;
    case BISHOP:
        break;
    case KING:
        break;
    case QUEEN:
        break;
    case KNOOK:
        break;
    case KNISHOP:
        break;
    }
}

// Given a piece, draws its moves
void Board::drawMoves(Piece * piece){
    sf::RectangleShape rectangle(sf::Vector2f(PIXELS_PER_SQUARE,PIXELS_PER_SQUARE));
    rectangle.setFillColor(sf::Color(0,255,0,100));
    for(auto it = piece->movements->begin();
        it != piece->movements->end();
        it++){
        rectangle.setPosition(sf::Vector2f((*it).second * PIXELS_PER_SQUARE,(*it).first * PIXELS_PER_SQUARE));
        window.draw(rectangle);
    }
}

// We just placed a piece in a valid position so we have to do stuff
Outcome Board::changeTurn(){
    // heldPiece->hasMoved is now true
    // heldPiece is now null
    // Update matrix, eliminate old piece, put piece in new position
    // If position has value eliminate piece and add animation and window movements
    // Check if holy hell
    // Check if stalemate or if the king was captured
    // Change the turn
    return OK;
}

// Main function
void Board::play(){
    while(!gameOver){
        while(!gameOver){

            sf::Event event;
            while(window.pollEvent(event)){
                if (event.type == sf::Event::Closed){
                    window.close();
                    gameOver = true;
                }
            }

            window.clear();
            window.draw(spriteBoard);

            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            // If the mouse has a valid position, inside of the window...
            if(mousePosition.y > 0 && mousePosition.y < HEIGHT*PIXELS_PER_SQUARE-1 && mousePosition.x > 0 && mousePosition.y < WIDTH*PIXELS_PER_SQUARE-1){

                // If there is no piece being held currently...
                if(heldPiece == NULL){

                    // We check if there is a piece of the right color under the mouse
                    Piece * p = pieces[mousePosition.y / PIXELS_PER_SQUARE][mousePosition.x / PIXELS_PER_SQUARE];
                    if(p != NULL && ((p->isWhite && whitesTurn) || (!p->isWhite && !whitesTurn)) && p->movements != NULL){
                        if(!sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                            // The mouse is on a piece so we show its possible moves
                            drawMoves(p);
                        } else {
                            // We pressed a key so we hold the piece we are pointing at
                            heldPiece = p;
                        }
                    }
                } else {
                    // If we are holding a piece, we check if we are still holding it
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        // If we are still holding it we update the position and draw its moves
                        heldPiece->sprite.setPosition(sf::Vector2f(mousePosition.x-PIXELS_PER_SQUARE/2,mousePosition.y-PIXELS_PER_SQUARE/2));
                        drawMoves(heldPiece);
                    } else {
                        // If we drop it, we check if the position is valid
                        int x = mousePosition.x / PIXELS_PER_SQUARE;
                        int y = mousePosition.y / PIXELS_PER_SQUARE;
                        bool found = false;
                        for(auto it = heldPiece->movements->begin();it != heldPiece->movements->end();it++){
                            if(it->second == x && it->first == y){
                                // If it is, we drop the piece in that position
                                heldPiece->sprite.setPosition(sf::Vector2f(x*PIXELS_PER_SQUARE,y*PIXELS_PER_SQUARE));
                                found=true;
                                //changeTurn();

                                break;
                            }
                        }
                        if(!found) {
                            heldPiece->sprite.setPosition(sf::Vector2f(heldPiece->file * PIXELS_PER_SQUARE, heldPiece->rank * PIXELS_PER_SQUARE));
                            heldPiece = NULL;
                        }
                    }

                }
            }

            for(int i=0;i<HEIGHT;i++){
                for(int j=0;j<WIDTH;j++){
                    if(pieces[i][j] != NULL){
                        if(pieces[i][j]->movements == NULL) calculateMovements(i,j);
                        window.draw(pieces[i][j]->sprite);
                    }
                }
            }

            // If there is no piece being held, we draw the hand
            if(heldPiece == NULL){
                    spriteHand.setPosition(sf::Vector2f(mousePosition.x-PIXELS_PER_SQUARE/2,mousePosition.y-PIXELS_PER_SQUARE/2));
                    window.draw(spriteHand);
            }


            window.display();
        }
    }
}
