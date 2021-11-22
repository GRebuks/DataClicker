#include "Menu.h"
#include <iostream>

// Initialization functions
void Menu::initTexture()
{
	// Shop button textures
	this->button_textures[0][0].loadFromFile("Textures/button_hdd.png");
	this->button_textures[0][1].loadFromFile("Textures/button_hdd_hover_new.png");

	this->button_textures[1][0].loadFromFile("Textures/button_ssd.png");
	this->button_textures[1][1].loadFromFile("Textures/button_ssd_hover_new.png");

	this->button_textures[2][0].loadFromFile("Textures/button_cpu.png");
	this->button_textures[2][1].loadFromFile("Textures/button_cpu_hover_new.png");

	this->button_textures[3][0].loadFromFile("Textures/button_ram.png");
	this->button_textures[3][1].loadFromFile("Textures/button_ram_hover_new.png");

	// Shop background texture
	this->shop_background_texture.loadFromFile("Textures/menu_shop.png");

	// Currency field texture
	this->currency_field_texture.loadFromFile("Textures/currency_info.png");

	// Clickable object texture
	this->clickable_texture.loadFromFile("Textures/PerfectCookie.png");
}

void Menu::initSprite(float width, float height)
{
	// Shop background sprite
	this->shop_background.setTexture(this->shop_background_texture);
	this->shop_background.setPosition(sf::Vector2f(560, 0));

	// Shop button sprites
	for (int i = 0; i < 4; i++) {
		this->button_sprites[i].setTexture(this->button_textures[i][0]);
		this->button_sprites[i].setPosition(sf::Vector2f(570 + (width - 570) / 4 * i - 1, 54));
	}

	// Currency field sprite
	this->currency_field.setTexture(this->currency_field_texture);
	this->currency_field.setPosition(sf::Vector2f(570 / 2 - this->currency_field_texture.getSize().x / 2, 20));

	// Clickable object sprite
	this->clickable.setTexture(this->clickable_texture);
	this->clickable.setPosition(sf::Vector2f(570 / 2 - this->currency_field_texture.getSize().x / 2, (height - 70) / 2 + 70));
	this->clickable.setScale(0.5, 0.5);

}
void Menu::initText(float width, float height, sf::Font& font)
{
	setText(this->currency_text, font, sf::Color::White, "Bits: 24 b", 24, sf::Vector2f(570 / 2 - this->currency_field_texture.getSize().x / 2 + 20, 27));
}

void Menu::initObj(Player* player) {
	this->player = player;
}

void Menu::buttonClick(sf::RenderWindow *window)
{
	sf::Vector2f mouse = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
	for (int i = 0; i < 4; i++) {
		sf::FloatRect bounds = button_sprites[i].getGlobalBounds();
		if (bounds.contains(mouse))
		{
			for (int i = 0; i < 4; i++) {
				this->button_sprites[i].setTexture(this->button_textures[i][0]);
				this->button_sprites[i].setScale(sf::Vector2f(1, 1));
			}
			this->button_sprites[i].setTexture(this->button_textures[i][1]);
			this->button_sprites[i].setScale(sf::Vector2f(0.98, 0.98));
		}
	}
	sf::FloatRect bounds;
	bounds.width = 570;
	bounds.height = 600;
	if (bounds.contains(mouse)) {
		this->player->add_bits(1);
		this->currency_text.setString("Bits: " + std::to_string(this->player->get_bits()));
	}
}

Menu::Menu(Player* player, float width, float height, sf::Font& font)
{
	this->initTexture();
	this->initSprite(width, height);
	this->initText(width, height, font);
	this->initObj(player);
}

Menu::Menu()
{
}

void Menu::draw(sf::RenderWindow *window)
{
	window->draw(currency_field);
	window->draw(currency_text);
	window->draw(clickable);
	window->draw(shop_background);
	for (int i = 0; i < 4; i++) {
		window->draw(this->button_sprites[i]);
	}
}

// Utility functions
void Menu::setText(sf::Text& text, sf::Font& font, sf::Color color, sf::String string, unsigned int size, sf::Vector2f pos)
{
	text.setFont(font);
	text.setFillColor(color);
	text.setString(string);
	text.setCharacterSize(size);
	text.setPosition(pos);
	text.setStyle(sf::Text::Bold);
}
