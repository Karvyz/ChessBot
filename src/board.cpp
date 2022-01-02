#include <iostream>
#include <cstddef>
#include "board.hpp"

Board::Board(/* args */)
{
    PlayerColor = WHITE;
}

Board::Board(std::vector<Piece*> pieceList, Color color, Move move)
{
    for (auto piece : pieceList)
    {
        if (!(piece->getPosition() == move.getEnd()))
        {
            Piece* temp = piece->clone();
            if (piece->getPosition() == move.getStart())
            {
                temp->setPosition(move.getEnd());
            }
            this->pieceList.push_back(temp);
        }
    }
}

Board::~Board()
{
}

Piece* Board::getPiece(Position p)
{
    for (auto piece : pieceList)
    {
        if (piece->getPosition() == p) return piece;
    }
    return nullptr;
}

void Board::print(){
    for (int y = 7; y >= 0; y--)
    {
    std::cout << y + 1;
        for (int x = 0; x < 8; x++)
        {
            Position temp(x, y);
            bool stop = true;
            for (auto piece : pieceList)
            {
                if (piece->getPosition() == temp)
                {
                    stop = false;
                    piece->print();
                }
            }
            if (stop)
                std::cout << ".";
        }
        std::cout << std::endl;
        
    }
    std::cout << " abcdefgh" << std::endl;
    
}

void Board::draw(sf::RenderWindow* window)
{
    std::cout << "draw" << std::endl;
    window->clear(sf::Color(120,120,120));
    sf::RectangleShape square(sf::Vector2f(100,100));
    square.setFillColor(sf::Color(255,255,255));
    
    for (size_t y = 0; y < 8; y++)
    {
        for (size_t x = 0; x < 4; x++)
        {
            square.setPosition(sf::Vector2f( (2 * x + ((y % 2 == 0) ? 0 : 1)) * 100, y * 100));
            window->draw(square);
        }
        
    }
    for (auto piece : pieceList)
    {
        piece->draw(window);
    }
    //window->display();
}

void Board::drawMoves(sf::RenderWindow* window, Piece* piece)
{
    draw(window);

    if (piece == nullptr) return;
    std::cout << "draw moves" << std::endl;

    sf::RectangleShape square(sf::Vector2f(100, 100));
    square.setFillColor(sf::Color(255, 0, 0, 160));
    for (auto move : piece->getLegalMoves())
    {
        square.setPosition(sf::Vector2f(move.getEnd().getX() * 100, (7 - move.getEnd().getY()) * 100));
        window->draw(square);
    }
}

void Board::addPiece(Piece* piece)
{
    pieceList.push_back(piece);
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
            pieceList.push_back(new Rook(Position(pos%SBOARD, 7 - pos/SBOARD)));
            std::cout << "   "  << pos%SBOARD<< 7 - pos/SBOARD  << std::endl;
            pos++;
        }
    }
    
}

bool Board::isOpposedKingAttacked()
{
    std::vector<Move> moves;
    for (auto piece : pieceList)
    {
        std::vector<Move> temp = piece->getMoves(pieceList);
        moves.insert( moves.end(), temp.begin(), temp.end());
    }
    for (auto move : moves)
    {
        if (move.getEndPiece() != nullptr)
        {
            Piece* temp = (Piece*)move.getEndPiece();
            if (temp->getValue() == 1000)
            {
                return true;
            }
        }
    }
    return false;
}

void Board::setLegalMoves()
{
    for (auto piece : pieceList)
    {
        if (piece->getColor() == PlayerColor)
        {
            std::vector<Move> moves = piece->getMoves(pieceList);
            std::vector<Move> legalMoves;
            for (auto move : moves)
            {
                Board b(pieceList, (Color)(1 - PlayerColor), move);
                if (b.isOpposedKingAttacked()) continue;
                legalMoves.push_back(move);
            }
            piece->setLegalMoves(legalMoves);
        }
    }
}

std::vector<Move> Board::getLegalMoves()
{
    std::vector<Move> moves;
    for (auto piece : pieceList)
    {
        if (piece->getColor() == PlayerColor)
        {
            std::vector<Move> temp = piece->getLegalMoves();
            moves.insert( moves.end(), temp.begin(), temp.end());
        }
    }
    return moves;
}

bool isMoveLegal(std::vector<Move> moves, Move actual)
{
    for (auto move : moves)
    {
        if (move == actual)
        return true;
    }
    return false;
}