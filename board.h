#pragma once
#include <string>
#include "pieces/rook.h"

class Board
{
private:
    const int SBOARD = 8;
    Piece ***tab;
    Color PlayerColor;
public:
    Board(/* args */);
    ~Board();

    void print();

    void addPiece(Position position, Color color = WHITE);
    void fromFen(std::string fen);
    std::vector<Move> getLegalMoves();
};
