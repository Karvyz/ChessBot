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

    friend std::ostream& operator<<(std::ostream &o, const Move m);
};
