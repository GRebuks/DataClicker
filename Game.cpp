#include "Game.h"

// Private functions
void Game::initVar(){

}

void Game::initWin(){
    this->videoMode.width = 800;
    this->videoMode.height = 600;
    this->window = new sf::RenderWindow(this->videoMode, "Data Clicker", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
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
        }
    }
}

// Constructors
Game::Game() {
    this->initWin();
    this->initVar();
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
    this->window->clear(sf::Color::White);
    this->window->display();
}