#include <iostream>
#include <cstddef>
#include "board.h"

Board::Board(/* args */)
{
    PlayerColor = WHITE;
    tab = new Piece**[8];
    for (int i = 0; i < SBOARD; i++)
    {
        tab[i] = new Piece*[8];
        for (int j = 0; j < SBOARD; j++)
        {
            tab[i][j] = nullptr;
        }
        
    }
    std::cout<< "Board created" << std::endl;
}

Board::~Board()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (tab[i][j] != nullptr) delete tab[i][j];
        }
        delete tab[i];
    }
    delete tab;
    std::cout<< "Board destroyed" << std::endl;
}

void Board::print(){
    for (int y = 7; y >= 0; y--)
    {
    std::cout << y + 1;
        for (int x = 0; x < 8; x++)
        {
            if (tab[x][y] == nullptr)
                std::cout << ".";
            else
            {
                tab[x][y]->print();

            }
        }
        std::cout << std::endl;
        
    }
    std::cout << " abcdefgh" << std::endl;
    
}

void Board::addPiece(Position position, Color color)
{
    tab[position.getX()][position.getY()] = new Rook(position, color);
}

void Board::fromFen(std::string fen)
{
    size_t pos = 0;
    for (size_t i = 0; i < fen.size(); i++)
    {
        if (fen[i] >= '0' && fen[i] <= '9')
        {
            pos += fen[i] - '0';
            continue;
        }
        if (fen[i] == 'r')
        {
            tab[pos%SBOARD][pos/SBOARD] = new Rook(Position(pos%SBOARD, 7 - pos/SBOARD));
            std::cout << "   "  << pos%SBOARD<< 7 - pos/SBOARD  << std::endl;
            pos++;
        }
    }
    
}

std::vector<Move> Board::getLegalMoves()
{
    std::vector<Move> moves;
    for (size_t i = 0; i < SBOARD; i++)
    {
        for (size_t j = 0; j < SBOARD; j++)
        {
            if (tab[i][j] != nullptr && tab[i][j]->getColor() == PlayerColor)
            {
                std::vector<Move> temp = tab[i][j]->getMoves(tab);
                moves.insert( moves.end(), temp.begin(), temp.end());
            }
        }
        
    }
    return moves;
}