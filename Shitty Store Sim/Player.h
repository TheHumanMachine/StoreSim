#pragma once
#include <vector>
#include <iostream>
#include "Item.h"

class Player
{
public:
	Player();
	void printInventory();
	int getPlayerMoney() const { return _money; }
	void deleteItemFromInventory(int i);
	Item *sellItem(int i);
	bool buyItem(Item *item);
	void removeItemFromInventory(Item *item);
	int _sizeOfInventory()const { return _inventory.size(); }
	void addPlayerMoney(int m){ _money += m; }

private:
	int _money;
	int _inventoryLimit = 10;
	std::vector<Item*> _inventory;
};

