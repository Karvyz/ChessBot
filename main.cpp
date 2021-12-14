#include "board.h"

void readMoveList(std::vector<Move> moves)
{
    for (auto move : moves)
    {
        std::cout << move << std::endl;
    }
}

int main(){
    Board test;
    test.addPiece({0,0});
    test.print();
    test.movePiece({{0,0}, {0,4}});
    test.print();
    readMoveList(test.getLegalMoves());
    return 1;
}