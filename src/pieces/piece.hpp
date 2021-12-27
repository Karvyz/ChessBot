#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include "../logic/move.hpp"

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
    std::vector<Move> moveList;
public:
    Piece(Position position, Color color, float value = 1) : position(position), color(color), value(value) {}
    ~Piece() {}

    Color getColor() { return color; }
    float getValue() { return value; }
    Position getPosition() { return position; }
    void setPosition(Position position) { this->position = position;}

    void setMoveList(std::vector<Piece*> pieceList) {
        moveList = getMoves(pieceList);
    }
    bool inMoveList(Position p) {
        for (auto move : moveList)
            if (move.getEnd() == p) return true;
        return false;
    }
    virtual void print() = 0;
    virtual void draw(sf::RenderWindow* window) = 0;
    virtual std::vector<Move> getMoves(std::vector<Piece*> pieceList) = 0;
};