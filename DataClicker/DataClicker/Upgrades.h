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
	int baseCost;
	int baseProduction;

	float costRate;
	float productionRate;

public:
	// Constructors
	Upgrades(int baseCost, int baseProduction, float costRate, float productionRate);
	Upgrades();

	// Functions
	void buy_upgrade(Player* player);
	float get_production();
};

