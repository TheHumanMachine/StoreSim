#pragma once

#include <string>

class Item
{
public:
	Item(std::string name);
	
	std::string getName() const { return _name; }
	int getPrice() const { return _price; }

	void updateItemPrice(float modifier);

private:
	std::string _name;
	int _price = 5;

};

