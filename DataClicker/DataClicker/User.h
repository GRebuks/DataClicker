#include <iostream>
#pragma once
class User
{
private:
	int bits = 0;

public:
	int get_bits();
	void add_bits(int amount);
};

