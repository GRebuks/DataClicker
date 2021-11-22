#include "Game.h"
#include <iostream>
// Private functions
void Game::initVar(){
    if (!font.loadFromFile("Fonts/VT323-Regular.ttf"))
    {
        std::cout << "Cant open font" << std::endl;
    }
    else {
        std::cout << "Font loaded" << std::endl;
    }
}

void Game::initWin(){
    this->videoMode.width = 1000;
    this->videoMode.height = 600;
    this->window = new sf::RenderWindow(this->videoMode, "Data Clicker", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

void Game::initObj()
{
    this->player = new Player();
    this->menu = new Menu(this->player, this->videoMode.width, this->videoMode.height, this->font);
}

void Game::pollEvents() {
    while(this->window->pollEvent(this->event)) {
        switch(this->event.type){
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if(this->event.key.code == sf::Keyboard::Escape){
                    this->window->close();
                }
                break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    menu->buttonClick(window);
                }
                break;
        }
    }
}

// Constructors
Game::Game() {
    this->initWin();
    this->initVar();
    this->initObj();
}
Game::~Game() {
    delete this->window;
}

// Accessors
const bool Game::running() const {
    return this->window->isOpen();
}

// Functions
void Game::update() {
    this->pollEvents();
}

void Game::render() {
    this->window->clear(sf::Color(210, 154, 91));
    this->menu->draw(this->window);
    this->window->display();
}

Player* Game::getPlayer() {
    return this->player;
}