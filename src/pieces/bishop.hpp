#pragma once
#include "piece.hpp"

class Bishop : public Piece
{
private:

public:
    Bishop(Position position ,Color color = WHITE);
    ~Bishop();
    Piece* clone() { return new Bishop(*this); }


    void print();
    void draw(sf::RenderWindow* window);
    std::vector<Move> getMoves(std::vector<Piece*> pieceList);
};
