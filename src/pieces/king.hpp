#pragma once
#include "piece.hpp"

class King : public Piece
{
private:

public:
    King(Position position ,Color color = WHITE);
    ~King();
    Piece* clone() { return new King(*this); }

    void print();
    void draw(sf::RenderWindow* window);
    std::vector<Move> getMoves(std::vector<Piece*> pieceList);
};
