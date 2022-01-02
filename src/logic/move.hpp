#pragma once
#include "position.hpp"

class Move
{
private:
    Position start;
    Position end;
    void* startPiece;
    void* endPiece;
public:
    Move(Position start, Position end, void* startPiece = nullptr, void* endPiece = nullptr);
    Move(int startx, int starty, int endx, int endy);
    ~Move();

    Position getStart() { return start; }
    Position getEnd() { return end; }
    void* getStartPiece() { return startPiece; }
    void* getEndPiece() { return endPiece; }

    bool operator==(const Move m);
    friend std::ostream& operator<<(std::ostream &o, const Move m);
};
