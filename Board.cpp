#include "Board.hpp"
#include <iostream>

Board::Board(){

    window.create(sf::VideoMode(constants::WIDTH*constants::PIXELS_PER_SQUARE, constants::HEIGHT*constants::PIXELS_PER_SQUARE), "Anarchy Chess");
    window.setFramerateLimit(60);
    window.setMouseCursorVisible(false);

    texturesPiecesBlack->loadFromFile("textures/piecesBlack.png");
    texturesPiecesWhite->loadFromFile("textures/piecesWhite.png");

    textureParticles->loadFromFile("textures/particles.png");

    rectanglePawn = sf::IntRect(0,0,constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE);
    rectangleKnook = sf::IntRect(0,constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE);
    rectangleHorsey = sf::IntRect(0,2*constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE);
    rectangleRook = sf::IntRect(0,3*constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE);
    rectangleBishop = sf::IntRect(2*constants::PIXELS_PER_SQUARE,0,constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE);
    rectangleKing = sf::IntRect(2*constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE);
    rectangleQueen = sf::IntRect(2*constants::PIXELS_PER_SQUARE,2*constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE);
    rectangleKnishop = sf::IntRect(2*constants::PIXELS_PER_SQUARE,3*constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE);

    rectanglePawnGrab = sf::IntRect(constants::PIXELS_PER_SQUARE,0,constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE);
    rectangleKnookGrab = sf::IntRect(constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE);
    rectangleHorseyGrab = sf::IntRect(constants::PIXELS_PER_SQUARE,2*constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE);
    rectangleRookGrab = sf::IntRect(constants::PIXELS_PER_SQUARE,3*constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE);
    rectangleBishopGrab = sf::IntRect(3*constants::PIXELS_PER_SQUARE,0,constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE);
    rectangleKingGrab = sf::IntRect(3*constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE);
    rectangleQueenGrab = sf::IntRect(3*constants::PIXELS_PER_SQUARE,2*constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE);
    rectangleKnishopGrab = sf::IntRect(3*constants::PIXELS_PER_SQUARE,3*constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE);

    textureBoard.loadFromFile("textures/board.png");
    spriteBoard.setTexture(textureBoard);

    textureHands.loadFromFile("textures/hands.png");

    rectangleWhiteHand = sf::IntRect(0,0,constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE);
    rectangleBlackHand = sf::IntRect(constants::PIXELS_PER_SQUARE,0,constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE);

    spriteHand.setTexture(textureHands);
    spriteHand.setTextureRect(rectangleWhiteHand);

    movement = STILL;

    movementState = 0;

    // First rank
    pieces[0][0] = new Piece(0,0,constants::ROOK,false,texturesPiecesBlack,rectangleRook);
    pieces[0][1] = new Piece(1,0,constants::HORSEY,false,texturesPiecesBlack,rectangleHorsey);
    pieces[0][2] = new Piece(2,0,constants::KNISHOP,false,texturesPiecesBlack,rectangleKnishop);
    pieces[0][3] = new Piece(3,0,constants::QUEEN,false,texturesPiecesBlack,rectangleQueen);
    pieces[0][4] = new Piece(4,0,constants::KING,false,texturesPiecesBlack,rectangleKing);
    pieces[0][5] = new Piece(5,0,constants::BISHOP,false,texturesPiecesBlack,rectangleBishop);
    pieces[0][6] = new Piece(6,0,constants::HORSEY,false,texturesPiecesBlack,rectangleHorsey);
    pieces[0][7] = new Piece(7,0,constants::KNOOK,false,texturesPiecesBlack,rectangleKnook);

    // Second rank
    for(int i=0;i<constants::WIDTH;i++){
        pieces[1][i] = new Piece(i,1,constants::PAWN,false,texturesPiecesBlack,rectanglePawn);
    }

    // Empty ranks in the middle
    for(int i=0;i<constants::WIDTH;i++){
        for(int j=2;j<constants::HEIGHT-2;j++){
            pieces[j][i] = NULL;
        }
    }

    // Seventh rank
    for(int i=0;i<constants::WIDTH;i++){
        pieces[6][i] = new Piece(i,6,constants::PAWN,true,texturesPiecesWhite,rectanglePawn);
    }

    // Eighth rank
    pieces[7][0] = new Piece(0,7,constants::KNOOK,true,texturesPiecesWhite,rectangleKnook);
    pieces[7][1] = new Piece(1,7,constants::HORSEY,true,texturesPiecesWhite,rectangleHorsey);
    pieces[7][2] = new Piece(2,7,constants::BISHOP,true,texturesPiecesWhite,rectangleBishop);
    pieces[7][3] = new Piece(3,7,constants::QUEEN,true,texturesPiecesWhite,rectangleQueen);
    pieces[7][4] = new Piece(4,7,constants::KING,true,texturesPiecesWhite,rectangleKing);
    pieces[7][5] = new Piece(5,7,constants::KNISHOP,true,texturesPiecesWhite,rectangleKnishop);
    pieces[7][6] = new Piece(6,7,constants::HORSEY,true,texturesPiecesWhite,rectangleHorsey);
    pieces[7][7] = new Piece(7,7,constants::ROOK,true,texturesPiecesWhite,rectangleRook);
}

Board::~Board(){
    for(int i=0;i<constants::HEIGHT;i++){
        for(int j=0;j<constants::WIDTH;j++){
            if(pieces[i][j]!=NULL)
                delete pieces[i][j]->movements;
            delete pieces[i][j];
        }
    }

    delete texturesPiecesBlack;
    delete texturesPiecesWhite;
    delete textureParticles;
}

// Helper function that calculates all possible movements for a piece
void Board::calculateMovements(int i, int j){

    pieces[i][j]->movements = new std::list<std::pair<int,int>>();

    switch(pieces[i][j]->type){
    case constants::PAWN:

        if(pieces[i][j]->isWhite){
            // We see if it can move upwards
            if(i-1>=0 && pieces[i-1][j] == NULL)
                pieces[i][j]->movements->insert(pieces[i][j]->movements->begin(),std::pair<int,int>(i-1,j));

            // We see if it can move upwards twice
            if(!pieces[i][j]->hasMoved && i-2>=0 && pieces[i-2][j] == NULL)
                pieces[i][j]->movements->insert(pieces[i][j]->movements->begin(),std::pair<int,int>(i-2,j));

            // We see if there is an enemy piece that can be holy hell'd on its left
            if(j-1>=0 && i-1>=0 && ((pieces[i][j-1] != NULL && !pieces[i][j-1]->isWhite) || (pieces[i-1][j-1] != NULL && !pieces[i-1][j-1]->isWhite)))
                pieces[i][j]->movements->insert(pieces[i][j]->movements->begin(),std::pair<int,int>(i-1,j-1));

            // The same with the piece on its right
            if(j+1<constants::WIDTH && i-1>=0 && ((pieces[i][j+1] != NULL && !pieces[i][j+1]->isWhite) || (pieces[i-1][j+1] != NULL && !pieces[i-1][j+1]->isWhite)))
                pieces[i][j]->movements->insert(pieces[i][j]->movements->begin(),std::pair<int,int>(i-1,j+1));

        } else {
            // The same but downwards
            // We see if it can move downwards
            if(i+1<constants::HEIGHT && pieces[i+1][j] == NULL)
                pieces[i][j]->movements->insert(pieces[i][j]->movements->begin(),std::pair<int,int>(i+1,j));

            // We see if it can move downwards twice
            if(!pieces[i][j]->hasMoved && i+2 < constants::HEIGHT && pieces[i+2][j] == NULL)
                pieces[i][j]->movements->insert(pieces[i][j]->movements->begin(),std::pair<int,int>(i+2,j));

            // We see if there is an enemy piece that can be holy hell'd on its left
            if(j-1>=0 && i+1 < constants::HEIGHT && ((pieces[i][j-1] != NULL && pieces[i][j-1]->isWhite) || (pieces[i+1][j-1] != NULL && pieces[i+1][j-1]->isWhite)))
                pieces[i][j]->movements->insert(pieces[i][j]->movements->begin(),std::pair<int,int>(i+1,j-1));

            // The same with the piece on its right
            if(j+1<constants::WIDTH && i+1 < constants::HEIGHT && ((pieces[i][j+1] != NULL && pieces[i][j+1]->isWhite) || (pieces[i+1][j+1] != NULL && pieces[i+1][j+1]->isWhite)))
                pieces[i][j]->movements->insert(pieces[i][j]->movements->begin(),std::pair<int,int>(i+1,j+1));
        }

        break;
    case constants::ROOK:
        break;
    case constants::HORSEY:
        break;
    case constants::BISHOP:
        break;
    case constants::KING:
        break;
    case constants::QUEEN:
        break;
    case constants::KNOOK:
        break;
    case constants::KNISHOP:
        break;
    }
}

// Given a piece, draws its moves
void Board::drawMoves(Piece * piece){
    sf::RectangleShape rectangle(sf::Vector2f(constants::PIXELS_PER_SQUARE,constants::PIXELS_PER_SQUARE));
    rectangle.setFillColor(sf::Color(0,255,0,100));
    for(auto it = piece->movements->begin();
        it != piece->movements->end();
        it++){
        rectangle.setPosition(sf::Vector2f((*it).second * constants::PIXELS_PER_SQUARE,(*it).first * constants::PIXELS_PER_SQUARE));
        window.draw(rectangle);
    }
}

// Updates the particles on the screen
void Board::updateParticles(){
    std::list<Particle*>::iterator it = listParticles.begin();
    while(it != listParticles.end()){
        window.draw((*it)->sprite);
        if((*it)->update()){
            // If the element should be erased, we erase it
            // This happens when it reaches the botton of the window
            delete *it;
            it = listParticles.erase(it);
        } else {
            it++;
        }
    }
}

// Updates the window movement
void Board::moveWindow(){
    sf::Vector2i winPos = window.getPosition();
    switch(movement){
    case DOWN:
        if(movementState == 10){
            winPos.y+=9;
        } else {
            winPos.y-=1;
        }
        break;

    case SHAKE:
        if(movementState % 4 == 0){
            winPos.x -= movementState;
        } else if(movementState % 4 == 3){
            winPos.x += movementState;
        }
        break;
    default:
        break;
    }
    window.setPosition(winPos);
    movementState--;
    if(movementState == 0) movement = STILL;
}

void Board::setMovement(WindowMovement m){
    movement = m;
    switch(m){
    case DOWN:
        movementState = 10;
        break;
    case SHAKE:
        movementState = 30;
        break;
    default:
        break;
    }
}

void Board::generateParticles(constants::Type t, bool white, double x, double y){
    generateParticles(white,x,y);
    Particle * p = new Particle(t,white,x,y,textureParticles);
    listParticles.insert(listParticles.begin(),p);
}

void Board::generateParticles(bool white, double x, double y){
    for(int i=0;i<5;i++){
        Particle * p = new Particle(white,x,y,textureParticles);
        listParticles.insert(listParticles.begin(),p);
    }
}

// We just placed a piece in a valid position so we have to do stuff
Outcome Board::changeTurn(int x, int y){
    // The held piece has moved of course
    heldPiece->hasMoved = true;
    // The held piece has the right sprite now
    sf::IntRect rectangle(heldPiece->sprite.getTextureRect());
    rectangle.left-=constants::PIXELS_PER_SQUARE;
    heldPiece->sprite.setTextureRect(rectangle);
    // If position has value eliminate piece and add animation and window movements
    if(pieces[y][x]!=NULL){
        generateParticles(pieces[y][x]->type, pieces[y][x]->isWhite, x*constants::PIXELS_PER_SQUARE, y*constants::PIXELS_PER_SQUARE);
        delete pieces[y][x];
        setMovement(SHAKE);
    } else {
        setMovement(DOWN);
    }

    pieces[y][x] = heldPiece;
    pieces[heldPiece->rank][heldPiece->file] = NULL;
    heldPiece->file = x;
    heldPiece->rank = y;


    // We set all pieces' movements to NULL so that they have to
    // be calculated again
    for(int i=0;i<constants::HEIGHT;i++){
        for(int j=0;j<constants::WIDTH;j++){
            if(pieces[i][j]!=NULL){
                delete pieces[i][j]->movements;
                pieces[i][j]->movements = NULL;
            }
        }
    }

    // Check if holy hell
    // Check vaticano
    // Update matrix, eliminate old piece, put piece in new position
    // Check if stalemate or if the king was captured
    // heldPiece is now null
    heldPiece = NULL;
    // Change the turn
    whitesTurn = !whitesTurn;
    // Change the color of the hand
    if(whitesTurn) spriteHand.setTextureRect(rectangleWhiteHand);
    else spriteHand.setTextureRect(rectangleBlackHand);
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
            if(mousePosition.y > 0 && mousePosition.y < constants::HEIGHT*constants::PIXELS_PER_SQUARE-1 && mousePosition.x > 0 && mousePosition.x < constants::WIDTH*constants::PIXELS_PER_SQUARE-1){

                // If there is no piece being held currently...
                if(heldPiece == NULL){

                    // We check if there is a piece of the right color under the mouse
                    Piece * p = pieces[mousePosition.y / constants::PIXELS_PER_SQUARE][mousePosition.x / constants::PIXELS_PER_SQUARE];
                    if(p != NULL && ((p->isWhite && whitesTurn) || (!p->isWhite && !whitesTurn)) && p->movements != NULL){
                        // The mouse is on a piece so we show its possible moves
                        drawMoves(p);
                        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                            // We clicked on a piece so we hold it
                            heldPiece = p;
                            sf::IntRect rectangle(p->sprite.getTextureRect());
                            rectangle.left+=constants::PIXELS_PER_SQUARE;
                            heldPiece->sprite.setTextureRect(rectangle);
                        }
                    }
                } else {
                    // If we are holding a piece, we check if we are still holding it
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        // If we are still holding it we update the position and draw its moves
                        heldPiece->sprite.setPosition(sf::Vector2f(mousePosition.x-constants::PIXELS_PER_SQUARE/2,mousePosition.y-constants::PIXELS_PER_SQUARE/2));
                        drawMoves(heldPiece);
                    } else {
                        // If we drop it, we check if the position is valid
                        int x = mousePosition.x / constants::PIXELS_PER_SQUARE;
                        int y = mousePosition.y / constants::PIXELS_PER_SQUARE;
                        bool found = false;
                        for(auto it = heldPiece->movements->begin();it != heldPiece->movements->end();it++){
                            if(it->second == x && it->first == y){
                                // If it is, we drop the piece in that position
                                heldPiece->sprite.setPosition(sf::Vector2f(x*constants::PIXELS_PER_SQUARE,y*constants::PIXELS_PER_SQUARE));
                                found=true;
                                changeTurn(x,y);
                                break;
                            }
                        }
                        if(!found) {
                            // If the position is invalid, we send the piece to its original place and
                            // set the sprite to the normal one
                            heldPiece->sprite.setPosition(sf::Vector2f(heldPiece->file * constants::PIXELS_PER_SQUARE, heldPiece->rank * constants::PIXELS_PER_SQUARE));

                            sf::IntRect rectangle(heldPiece->sprite.getTextureRect());
                            rectangle.left-=constants::PIXELS_PER_SQUARE;
                            heldPiece->sprite.setTextureRect(rectangle);

                            heldPiece = NULL;
                        }
                    }

                }
            }

            for(int i=0;i<constants::HEIGHT;i++){
                for(int j=0;j<constants::WIDTH;j++){
                    if(pieces[i][j] != NULL){
                        if(pieces[i][j]->movements == NULL) calculateMovements(i,j);
                        if(pieces[i][j] != heldPiece) window.draw(pieces[i][j]->sprite);
                    }
                }
            }

            // If there is no piece being held, we draw the hand
            if(heldPiece == NULL){
                spriteHand.setPosition(sf::Vector2f(mousePosition.x-constants::PIXELS_PER_SQUARE/2,mousePosition.y-constants::PIXELS_PER_SQUARE/2));
                window.draw(spriteHand);
            } else {
                // If we are holding a piece, we draw it on top of everything
                window.draw(heldPiece->sprite);
            }

            updateParticles();
            if(movement!=STILL) moveWindow();

            window.display();
        }
    }
}
