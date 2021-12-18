#pragma once
#include "piece.h"

class Rook : public Piece
{
private:

public:
    Rook(Position position ,Color color = WHITE);
    ~Rook();


    void print();
    void draw(sf::RenderWindow* window);
    std::vector<Move> getMoves(std::vector<Piece*> pieceList);
};
