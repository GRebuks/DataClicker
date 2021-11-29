#include "Upgrades.h"
#include <cmath>
#include <iostream>

Upgrades::Upgrades(int baseCost, int baseProduction, float costRate, float productionRate)
{
	this->baseCost = baseCost;
	this->baseProduction = baseProduction;
	this->costRate = costRate;
	this->productionRate = productionRate;

	this->cost = this->baseCost * pow(this->costRate, this->count);
	this->production = this->baseProduction * this->count; // Neaizmirsti pievienot reizinataju dauni
}

Upgrades::Upgrades()
{
}

void Upgrades::buy_upgrade(Player* player)
{
	if (player->get_bits() >= this->cost) {
		player->add_bits(-this->cost);
		this->count++;
		this->cost = this->baseCost * pow(this->costRate, this->count);
		this->production = this->baseProduction * this->count;
	}
	else {
		std::cout << "Not enough money" << std::endl;
	}
	return;
}

float Upgrades::get_production()
{
	return this->production;
}
