#pragma once
#include <string>
#include "pieces/rook.hpp"
#include "pieces/queen.hpp"

class Board
{
private:
    const int SBOARD = 8;
    std::vector<Piece*> pieceList;
    Color PlayerColor;
    std::vector<Position> whitePieces;
    std::vector<Position> blackPieces;
public:
    Board(/* args */);
    ~Board();

    Piece* getPiece(Position position);

    void print();
    void draw(sf::RenderWindow* window);
    void drawMoves(sf::RenderWindow* window, Piece* piece);

    void addPiece(Piece* p);
    void fromFen(std::string fen);
    

    std::vector<Move> getLegalMoves();
    void setMoves();
};
