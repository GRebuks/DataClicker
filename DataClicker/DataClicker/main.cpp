#include <SFML/Graphics.hpp>
#include "User.h"

void main()
{
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Data Clicker", sf::Style::Fullscreen);

    User user;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonPressed:
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    user.add_bits(1);
                    std::cout << user.get_bits() << std::endl;
                }
                break;
            }
        }
        window.clear(sf::Color::White);
        window.display();
    }
}