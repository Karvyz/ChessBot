#include "king.hpp"

King::King(Position position, Color color) : Piece(position, color, 1000)
{
}

King::~King()
{
}

void King::print(){
    std::cout << ((color == WHITE) ? "k" : "K");
}

void King::draw(sf::RenderWindow* window)
{
    sf::Texture texture;
    texture.loadFromFile(((color == WHITE) ? "img/white king.png" : "img/black king.png"));
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(0.4, 0.4));
    sprite.setPosition(sf::Vector2f(position.getX() * 100, (7 - position.getY()) * 100));
    window->draw(sprite);
}
  


std::vector<Move> King::getMoves(std::vector<Piece*> pieceList)
{
    Position offset[] = {{1, 0}, {-1, 0}, {0 ,1}, {0, -1}, {1, 1}, {-1, -1}, {-1 ,1}, {1, -1}}; // directions of movements
    std::vector<Move> moves;
    for (size_t i = 0; i < 8; i++)
    {
        Position temposition = position;
            temposition = temposition + offset[i];
            if (!temposition.isLegal()) continue; // check if the position is in the board

            // check if there is a piece at the location
            bool noPiece = true;
            for (auto piece : pieceList)
            {
                if (piece->getPosition() == temposition)
                {
                    noPiece = false;
                    if (piece->getColor() == color) break;
                    else
                    {
                        moves.push_back(Move(position, temposition, this, piece));
                        break;
                    }
                }
            }
        if (noPiece)
            moves.push_back(Move(position, temposition));
    }
    
    return moves;
}
