#include "position.h"

Position::Position(int x, int y) : x(x), y(y)
{
}

Position::~Position()
{
}

bool Position::isLegal()
{
    return (x >= 0 && x <=7 && y >= 0 && y <= 7);
}

Position Position::operator+(const Position p2){
    Position p1(*this);
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

bool Position::operator==(const Position p)
{
    return (x == p.x && y == p.y);
}

std::ostream& operator<<(std::ostream &o, const Position p)
{
    o << (char)(p.x + 'a') << p.y + 1;
    return o;
}