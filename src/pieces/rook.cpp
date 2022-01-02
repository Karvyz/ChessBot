#include "rook.hpp"

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
    texture.loadFromFile(((color == WHITE) ? "img/white rook.png" : "img/black rook.png"));
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(0.4, 0.4));
    sprite.setPosition(sf::Vector2f(position.getX() * 100, (7 - position.getY()) * 100));
    window->draw(sprite);
}



std::vector<Move> Rook::getMoves(std::vector<Piece*> pieceList)
{
    Position offset[4] = {{1, 0}, {-1, 0}, {0 ,1}, {0, -1}}; // directions of movements
    std::vector<Move> moves;
    for (size_t i = 0; i < 4; i++)
    {
        Position temposition = position;
        while (true)
        {
            temposition = temposition + offset[i];
            if (!temposition.isLegal()) break; // check if the position is in the board

            // check if there is a piece at the location
            bool stop = false;
            for (auto piece : pieceList)
            {
                if (piece->getPosition() == temposition)
                {
                    stop = true;
                    if (piece->getColor() == color) break;
                    else
                    {
                        moves.push_back(Move(position, temposition, this, piece));
                        break;
                    }
                }
            }
            if (stop) break;
            moves.push_back(Move(position, temposition));
        }
    }
    
    return moves;
}