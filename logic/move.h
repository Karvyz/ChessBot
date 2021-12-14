#pragma once
#include "position.h"

class Move
{
private:
    Position start;
    Position end;
public:
    Move(Position start, Position end);
    Move(int startx, int starty, int endx, int endy);
    ~Move();

    Position getStart() { return start; }
    Position getEnd() { return end; }

    bool operator==(const Move m);
    friend std::ostream& operator<<(std::ostream &o, const Move m);
};
