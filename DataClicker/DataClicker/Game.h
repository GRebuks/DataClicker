#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Menu.h"
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
    void initObj();
    void pollEvents();

    // Objects
    Menu menu;


public:
    // Variables
    sf::Font font;
    // Constructors
    Game();
    virtual ~Game();

    // Accessors
    const bool running() const;

    // Functions
    void update();
    void render();
};