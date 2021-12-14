#pragma once
#include "piece.h"

class Rook : public Piece
{
private:

public:
    Rook(Position position ,Color color = WHITE);
    ~Rook();


    void print();

    std::vector<Move> getMoves(Piece*** board);
};
