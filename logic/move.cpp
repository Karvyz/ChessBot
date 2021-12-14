#include "move.h"

Move::Move(Position start, Position end) : start(start), end(end)
{
}

Move::Move(int startx, int starty, int endx, int endy) : start(startx, starty), end(endx, endy)
{
}

Move::~Move()
{
}

bool Move::operator==(const Move m)
{
    return (start == m.start && end == m.end);
}

std::ostream& operator<<(std::ostream &o, const Move m)
{
    o << m.start << " -> " << m.end;
    return o;
}