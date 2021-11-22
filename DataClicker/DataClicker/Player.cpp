#include "Player.h"

int Player::get_bits()
{
	return this->bits;
}

void Player::add_bits(int amount)
{
	this->bits += amount;
}

