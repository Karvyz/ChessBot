#include "rook.h"

Rook::Rook(Position position, Color color) : Piece(position, color, 5)
{
}

Rook::~Rook()
{
}

void Rook::print(){
    std::cout << ((color == WHITE) ? "r" : "R");
}

std::vector<Move> Rook::getMoves(Piece*** board)
{
    Position offset[4] = {{1, 0}, {-1, 0}, {0 ,1}, {0, -1}};
    std::vector<Move> moves;
    for (size_t i = 0; i < 4; i++)
    {
        Position temposition = position;
        while (true)
        {
            temposition = temposition + offset[i];
            if (!temposition.isLegal()) break;
            if (board[temposition.getX()][temposition.getY()] != nullptr)
            {
                if (board[temposition.getX()][temposition.getY()]->getColor() == color)
                {
                    break;
                }
                moves.push_back(Move(position, temposition));
                break;
            }
            moves.push_back(Move(position, temposition));
        }
    }
    
    return moves;
}