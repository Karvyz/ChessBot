#pragma once
#include "piece.hpp"

class Rook : public Piece
{
private:

public:
    Rook(Position position ,Color color = WHITE);
    ~Rook();
    Piece* clone() { return new Rook(*this); }


    void print();
    void draw(sf::RenderWindow* window);
    std::vector<Move> getMoves(std::vector<Piece*> pieceList);
};
