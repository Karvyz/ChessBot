#pragma once
#include <string>
#include "pieces/rook.hpp"
#include "pieces/queen.hpp"
#include "pieces/king.hpp"

class Board
{
private:
    const int SBOARD = 8;
    std::vector<Piece*> pieceList;
    Color PlayerColor;
public:
    Board(/* args */);
    Board(std::vector<Piece*> pieceList, Color color, Move move);
    ~Board();

    Piece* getPiece(Position position);

    void print();
    void draw(sf::RenderWindow* window);
    void drawMoves(sf::RenderWindow* window, Piece* piece);

    void addPiece(Piece* p);
    void fromFen(std::string fen);
    
    bool isOpposedKingAttacked();
    void setLegalMoves();
    std::vector<Move> getLegalMoves();
};
