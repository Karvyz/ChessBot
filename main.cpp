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
    test.addPiece({0,1});
    test.addPiece({1,0}, BLACK);
    test.print();
    readMoveList(test.getLegalMoves());
    return 1;
}