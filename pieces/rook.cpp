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

void Rook::draw(sf::RenderWindow* window)
{
    sf::Texture texture;
    texture.loadFromFile(((color == WHITE) ? "images/white rook.png" : "images/black rook.png"));
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(0.4, 0.4));
    sprite.setPosition(sf::Vector2f(position.getX() * 100, (7 - position.getY()) * 100));
    window->draw(sprite);
}



std::vector<Move> Rook::getMoves(std::vector<Piece*> pieceList)
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
            // if (board[temposition.getX()][temposition.getY()] != nullptr)
            // {
            //     if (board[temposition.getX()][temposition.getY()]->getColor() == color)
            //     {
            //         break;
            //     }
            //     moves.push_back(Move(position, temposition));
            //     break;
            // }
            moves.push_back(Move(position, temposition));
        }
    }
    
    return moves;
}