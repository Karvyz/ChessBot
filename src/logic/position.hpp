#pragma once
#include <iostream>

class Position
{
private:
    int x;
    int y;
public:
    Position(int x, int y);
    ~Position();

    int getX() { return x; }
    int getY() { return y; }

    bool isLegal();
    Position mouseToBoard();

    Position operator+(const Position p);
    bool operator==(const Position p);
    friend std::ostream& operator<<(std::ostream &o, const Position p);
};
