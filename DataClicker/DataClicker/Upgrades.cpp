#include "Upgrades.h"
#include <cmath>
#include <iostream>

Upgrades::Upgrades(int base_cost, int base_production, float cost_rate, float production_rate)
{
	this->base_cost = base_cost;
	this->base_production = base_production;
	this->cost_rate = cost_rate;
	this->production_rate = production_rate;

	this->cost = this->base_cost * pow(this->cost_rate, this->count);
	this->production = this->base_production * this->count;
}

Upgrades::Upgrades()
{
}

void Upgrades::buy_upgrade(Player* player)
{
	if (player->get_bits() >= this->cost) {
		player->add_bits(-this->cost);
		this->count++;
		this->cost = this->base_cost * pow(this->cost_rate, this->count);
		this->production = this->base_production * this->count;
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

float Upgrades::get_cost()
{
	return this->cost;
}
float Upgrades::get_base_prod() {
	return this->base_production;
}
