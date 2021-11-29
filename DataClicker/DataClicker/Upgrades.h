#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.h"

class Upgrades
{
private:
	float cost;
	float production;
	int count = 0;

	// Base upgrade values
	int base_cost;
	int base_production;

	float cost_rate;
	float production_rate;

public:
	// Constructors
	Upgrades(int baseCost, int baseProduction, float costRate, float productionRate);
	Upgrades();

	// Functions
	void buy_upgrade(Player* player);
	float get_production();
	float get_cost();
	float get_base_prod();
};

