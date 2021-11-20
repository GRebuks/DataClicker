#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
class Game {
private:
    // Variables

    // Window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event event;

    // Functions
    void initVar();
    void initWin();
    void pollEvents();


public:
    // Constructors
    Game();
    ~Game();

    // Accessors
    const bool running() const;

    // Functions
    void update();
    void render();
};