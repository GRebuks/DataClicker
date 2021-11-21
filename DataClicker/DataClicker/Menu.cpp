#include "Menu.h"
#include <iostream>

Menu::Menu(float width, float height, sf::Font& font)
{
	// Shop buttons
	this->textures[0].loadFromFile("Textures/button_hdd.png");
	this->textures[1].loadFromFile("Textures/button_ssd.png");
	this->textures[2].loadFromFile("Textures/button_cpu.png");
	this->textures[3].loadFromFile("Textures/button_ram.png");

	/*for (int i = 0; i < 4; i++) {
		this->sprites[i].setTexture(this->textures[i]);
		this->sprites[i].setPosition(sf::Vector2f(800 / 2 + 800 / 8 * i, 0));
	}*/

}

Menu::Menu()
{
}

void Menu::draw(sf::RenderWindow *window)
{
	for (int i = 0; i < 4; i++) {
		this->sprites[i].setTexture(this->textures[i]);
		this->sprites[i].setPosition(sf::Vector2f(800 / 2 + 800 / 8 * i, 0));
		window->draw(this->sprites[i]);
	}
}
