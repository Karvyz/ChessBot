#pragma once
#include <string>
#include "pieces/rook.h"

class Board
{
private:
    const int SBOARD = 8;
    std::vector<Piece*> pieceList;
    Color PlayerColor;
public:
    Board(/* args */);
    ~Board();

    void print();
    void draw(sf::RenderWindow* window);

    void addPiece(Position position, Color color = WHITE);
    void fromFen(std::string fen);

    std::vector<Move> getLegalMoves();

    void movePiece(Move move);
};
