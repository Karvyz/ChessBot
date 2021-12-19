#include "board.hpp"

void readMoveList(std::vector<Move> moves)
{
    for (auto move : moves)
    {
        std::cout << move << std::endl;
    }
}

int main(){
    sf::RenderWindow window(sf::VideoMode(800,800), "test");

    Board test;
    test.addPiece({0,0}, BLACK);

    window.clear();
    test.draw(&window);
    window.display();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


    }
    return 0;
}