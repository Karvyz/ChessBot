#include "board.hpp"
#include <ctime>

void readMoveList(std::vector<Move> moves)
{
    for (auto move : moves)
    {
        std::cout << move << std::endl;
    }
}

int main(){
    sf::RenderWindow window(sf::VideoMode(800,800), "board");

    Board board;
    board.addPiece(new King({1,1}));
    board.addPiece(new Queen({1, 6}));
    board.addPiece(new Rook({0,7}, BLACK));
    board.addPiece(new Bishop({5,5}));
    board.addPiece(new Knight({6,6}));
    board.setLegalMoves();
    readMoveList(board.getLegalMoves());
    
    board.draw(&window);
    window.display();
    Position mousePosition(0,0);

    Piece* selected = nullptr;
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                if ((1 - 1 > 0.1) || (event.mouseButton.x != mousePosition.getX() && event.mouseButton.y != mousePosition.getY()))
                {
                    mousePosition = {event.mouseButton.x, event.mouseButton.y};
                    std::cout << "the left button was pressed" << std::endl;
                    if (selected != nullptr && selected->inMoveList(mousePosition.mouseToBoard()))
                    {
                        std::cout << "move tentative" << std::endl;
                        selected->setPosition(mousePosition.mouseToBoard());
                        board.setLegalMoves();
                        selected = nullptr;
                        board.draw(&window);
                        window.display();
                        continue;                        
                    }
                    selected = board.getPiece(mousePosition.mouseToBoard());
                    board.drawMoves(&window, selected);
                    window.display();
                }
            }
        }
    }
    return 0;
}