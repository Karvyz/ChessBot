#pragma once
#include "piece.hpp"

class Knight : public Piece
{
private:

public:
    Knight(Position position ,Color color = WHITE);
    ~Knight();
    Piece* clone() { return new Knight(*this); }


    void print();
    void draw(sf::RenderWindow* window);
    std::vector<Move> getMoves(std::vector<Piece*> pieceList);
};
