#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Menu
{
private:
	// Objects
	sf::Text texts[4];
	sf::Texture textures[4];
	sf::Sprite sprites[4];

public:
	// Constructors
	Menu(float width, float height, sf::Font& font);
	Menu();

	// Functions
	void draw(sf::RenderWindow *window);

};

