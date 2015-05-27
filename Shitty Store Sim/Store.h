#pragma once
#include <vector>
#include <iostream>
#include "Item.h"


class Store
{
public:
	Store();

	void getInventory();
	void getItemInInventory(int i);
	void updatePrice(float modifier);
	void deleteItemFromInventory(int i);
	bool buyItem(Item *item);
	Item *sellItem(int i);
	void addItemToInventory(Item *item);
	int _sizeOfInventory()const { return _inventory.size(); }
	int getStoreMoney() const { return _money; }
	void addStoreMoney(int m){ _money += m; }

private:
	int _money;
	int _shopsize = 10;
	std::vector<Item*> _inventory;
};

