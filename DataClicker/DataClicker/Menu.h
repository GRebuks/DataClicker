#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.h"
class Menu
{
private:
	// Variables
	int currency;
	int production;
	int prod[4] = {1, 2, 3, 4};

	// Textures / Sprites
	sf::Text currency_text;
	sf::Text production_text;

	sf::Texture button_textures[4][2];
	sf::Texture upgrade_texture;
	sf::Texture shop_background_texture;
	sf::Texture currency_field_texture;
	sf::Texture clickable_texture;

	sf::Sprite button_sprites[4];
	sf::Sprite upgrade_sprites[4];
	sf::Sprite shop_background;
	sf::Sprite currency_field;
	sf::Sprite clickable;

	// Objects
	Player* player;

	// Functions
	void initTexture();
	void initSprite(float width, float height);
	void initText(float width, float height, sf::Font& font);
	void initObj(Player* player);

	void setText(sf::Text& text, sf::Font& font, sf::Color color, sf::String string, unsigned int size, sf::Vector2f pos);

public:
	// Constructors
	Menu(Player* player, float width, float height, sf::Font& font);
	Menu();

	// Functions
	void draw(sf::RenderWindow *window);
	void buttonClick(sf::RenderWindow* window);

};

