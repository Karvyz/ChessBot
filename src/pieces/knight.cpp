#include "knight.hpp"

Knight::Knight(Position position, Color color) : Piece(position, color, 5)
{
}

Knight::~Knight()
{
}

void Knight::print(){
    std::cout << ((color == WHITE) ? "n" : "N");
}

void Knight::draw(sf::RenderWindow* window)
{
    sf::Texture texture;
    texture.loadFromFile(((color == WHITE) ? "img/white knight.png" : "img/black knight.png"));
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(0.4, 0.4));
    sprite.setPosition(sf::Vector2f(position.getX() * 100, (7 - position.getY()) * 100));
    window->draw(sprite);
}
  


std::vector<Move> Knight::getMoves(std::vector<Piece*> pieceList)
{
    Position offset[] = {{1, 2}, {2, 1}, {-1 ,2}, {-2, 1}, {-1, -2}, {-2, -1}, {1, -2}, {2, -1}}; // directions of movements
    std::vector<Move> moves;
    for (size_t i = 0; i < 8; i++)
    {
        Position temposition = position;
        
        
            temposition = temposition + offset[i];
            if (!temposition.isLegal()) continue; // check if the position is in the board

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
            if (stop) continue;

            moves.push_back(Move(position, temposition));
        
    }
    
    return moves;
}