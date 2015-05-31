#pragma once
#include <vector>
#include <iostream>
#include "Item.h"



class Player
{
public:
	Player();








	//Selling and Buying functions
	void printInventory();
	bool clearSoldItem(int i);

	Item *getItem(int i);
	bool sellItem(int money, int i);
	void recieveItem(Item *item);
	bool buyItem(Item *item);
	int _sizeOfInventory()const { return _inventory.size(); }

	int getMoney() const { return _money; }
	void addMoney(int m){ _money += m; }
	void removeMoney(int itemCost);

private:
	int _money;
	int _inventoryLimit = 10;
	std::vector<Item*> _inventory;
};

