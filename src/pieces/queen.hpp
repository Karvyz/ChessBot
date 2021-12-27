#pragma once
#include "piece.hpp"

class Queen : public Piece
{
private:

public:
    Queen(Position position ,Color color = WHITE);
    ~Queen();


    void print();
    void draw(sf::RenderWindow* window);
    std::vector<Move> getMoves(std::vector<Piece*> pieceList);
};
