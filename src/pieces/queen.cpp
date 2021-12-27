#include "queen.hpp"

Queen::Queen(Position position, Color color) : Piece(position, color, 5)
{
}

Queen::~Queen()
{
}

void Queen::print(){
    std::cout << ((color == WHITE) ? "q" : "Q");
}

void Queen::draw(sf::RenderWindow* window)
{
    sf::Texture texture;
    texture.loadFromFile(((color == WHITE) ? "img/white queen.png" : "img/black queen.png"));
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(0.4, 0.4));
    sprite.setPosition(sf::Vector2f(position.getX() * 100, (7 - position.getY()) * 100));
    window->draw(sprite);
}
  


std::vector<Move> Queen::getMoves(std::vector<Piece*> pieceList)
{
    Position offset[] = {{1, 0}, {-1, 0}, {0 ,1}, {0, -1}, {1, 1}, {-1, -1}, {-1 ,1}, {1, -1}}; // directions of movements
    std::vector<Move> moves;
    for (size_t i = 0; i < 8; i++)
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
                        moves.push_back(Move(position, temposition));
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