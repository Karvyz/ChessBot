#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include "../logic/move.hpp"

enum Color{
    WHITE = 0,
    BLACK = 1
};

class Piece
{
protected:
    Position position;
    Color color;
    float value;
    std::vector<Move> legalMoveList;
public:
    Piece(Position position, Color color, float value = 1) : position(position), color(color), value(value) {}
    ~Piece() {}
    virtual Piece* clone() = 0;


    Color getColor() { return color; }
    float getValue() { return value; }
    Position getPosition() { return position; }
    void setPosition(Position position) { this->position = position;}

    std::vector<Move> getLegalMoves() { return legalMoveList; }
    void setLegalMoves(std::vector<Move> moves) { legalMoveList = moves; }
    bool inMoveList(Position p) {
        for (auto move : legalMoveList)
            if (move.getEnd() == p) return true;
        return false;
    }
    virtual void print() = 0;
    virtual void draw(sf::RenderWindow* window) = 0;
    virtual std::vector<Move> getMoves(std::vector<Piece*> pieceList) = 0;
};