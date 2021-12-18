#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "../logic/move.h"

enum Color{
    WHITE,
    BLACK
};

class Piece
{
protected:
    Position position;
    Color color;
    float value;
public:
    Piece(Position position, Color color, float value = 1) : position(position), color(color), value(value) {}
    ~Piece() {}

    Color getColor() { return color; }
    float getValue() { return value; }
    void setPosition(Position position) { this->position = position;}

    virtual void print() = 0;
    virtual void draw(sf::RenderWindow* window) = 0;
    virtual std::vector<Move> getMoves(std::vector<Piece*> pieceList) = 0;
};